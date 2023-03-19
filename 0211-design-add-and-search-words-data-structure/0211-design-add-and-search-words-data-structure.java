class TrieNode {
    boolean isEnd;
    
    TrieNode[] children;
    
    TrieNode() {
        isEnd = false;
        
        children = new TrieNode[26];
    }
    
    public boolean isLast() {
        return isEnd;
    }
    
    public void setAsLast() {
        isEnd = true;
    }
    
    public void addChild(char c) {
        if (children[c-'a'] != null) return;
        
        children[c-'a'] = new TrieNode();
    }
    
    public TrieNode getChild(char c) {
        return children[c-'a'];
    }
    
    public boolean isChildPresent(char c) {
        return (children[c-'a']!=null);
    }
}

class WordDictionary {
    TrieNode root;
    
    public WordDictionary() {
        root = new TrieNode();
    }
    
    public void addWord(String word) {
        TrieNode current = root;
        
        for (char c : word.toCharArray()) {
            current.addChild(c);
            
            current = current.getChild(c);
        }
        current.setAsLast();
    }
    
    public boolean search(String word) {
        return search(word, 0, root);
    }
    
    private boolean search(String word, int index, TrieNode currentRoot) {
        if (index >= word.length()) {
            return currentRoot.isLast();
        }
        
        TrieNode current = currentRoot;
        for (int i = index; i < word.length(); ++i) {
            if (word.charAt(i) == '.') {
                boolean result = false;
                
                for (int j = 0; j < 26; ++j) {
                    if (!current.isChildPresent((char)('a'+j))) continue;
                    
                    result = result || (search(word, i+1, current.getChild((char)('a'+j))));
                }
                
                return result;
            }
            
            if (!current.isChildPresent(word.charAt(i))) return false;
            current = current.getChild(word.charAt(i));
        }
        
        return current.isLast();
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
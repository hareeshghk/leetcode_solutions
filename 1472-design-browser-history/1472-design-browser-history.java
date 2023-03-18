class BrowserHistory {
    
    int currentPosition, maxPosition;
    ArrayList<String> urls;

    public BrowserHistory(String homepage) {
        urls = new ArrayList<String>();
        currentPosition = 0;
        maxPosition = 0;
        
        urls.add(homepage);
    }
    
    public void visit(String url) {
        ++currentPosition;
        if (currentPosition >= urls.size()) {
            urls.add(url);
        } else {
            urls.set(currentPosition, url);
        }
        maxPosition = currentPosition;
    }
    
    public String back(int steps) {
        currentPosition = Math.max(0, currentPosition-steps);
        return urls.get(currentPosition);
    }
    
    public String forward(int steps) {
        currentPosition = Math.min(maxPosition, currentPosition+steps);
        return urls.get(currentPosition);
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */
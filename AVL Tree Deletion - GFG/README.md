# AVL Tree Deletion
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a AVL tree and N values to be deleted from the tree. Write a function to delete a given value from the tree.</span></p>

<pre><span style="font-size:18px"><strong>Example 1:
</strong>
Tree = 
        4
      /   \
     2     6
    / \   / \  
   1   3 5   7</span>

<span style="font-size:18px">N = 4
Values to be deleted = {4,1,3,6}</span>

<span style="font-size:18px"><strong>Input: </strong>Value to be deleted = 4
<strong>Output:</strong>
        5    
      /   \
     2     6
    / \     \  
   1   3     7</span>

<span style="font-size:18px"><strong>Input: </strong>Value to be deleted = 1
<strong>Output:</strong>
        5    
      /   \
     2     6
      \     \  
       3     7</span>

<span style="font-size:18px"><strong>Input: </strong>Value to be deleted = 3
<strong>Output:</strong>
        5    
      /   \
     2     6
            \  
             7</span>

<span style="font-size:18px"><strong>Input: </strong>Value to be deleted = 6
<strong>Output:</strong>
        5    
      /   \
     2     7</span>

</pre>

<p><span style="font-size:18px"><strong>Your Task: &nbsp;</strong><br>
You dont need to read input or print anything. Complete the function<strong> delelteNode()</strong> which takes the root of the tree and the value of the node to be deleted as input parameters and returns the root of the modified tree.</span></p>

<p><span style="font-size:18px"><strong>Note:&nbsp;</strong>The tree will be checked after each deletion.&nbsp;<br>
If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.<br>
If instead all deletion are successful, inorder traversal of tree will be printed.<br>
If every single node is deleted from tree, 'null' will be printed.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(height of tree)<br>
<strong>Expected Auxiliary Space: </strong>O(height of tree)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 500</span></p>
 <p></p>
            </div>
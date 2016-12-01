/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {

    private TreeNode pre, first, second;

    private void swap(TreeNode A, TreeNode B){
        int t = A.val;
        A.val = B.val;
        B.val = t;
    }

    private void Dfs(TreeNode t){
        if(t == null)
            return;
        Dfs(t.left);
        if(pre != null){
            if(pre.val > t.val){
                if(first == null)
                    first = pre;
                second = t;
            }
        }
        pre = t;
        Dfs(t.right);
    }

    public void recoverTree(TreeNode root) {
        pre = null; first = null; second = null;
        Dfs(root);
        swap(first, second);
    }
}
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans=0;
    public void solve(TreeNode root, int max_par){
        if(root==null) return ;
        if(root.val>=max_par){
            //System.out.println(root.val);
            max_par=root.val;
            ans++;
        }
        solve(root.left, max_par);
        solve(root.right, max_par);
    }

    public int goodNodes(TreeNode root) {
        solve(root, -10001);
        return ans;
    }
}
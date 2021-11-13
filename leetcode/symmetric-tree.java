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
    private boolean checkSymmetry(TreeNode left, TreeNode right) {        
        // Check if left and right are equal.
        if (left.val != right.val) {
            return false;
        }

        boolean isSymmetric;
        
        // Check left's left and right's right.
        // (1) If both of them are null, it's symmetric.
        // (2) If both of them are non-null, check recursively.
        // (3) If only one of them are null, it's asymmetric.
        if (left.left == null && right.right == null) {
            isSymmetric = true;
        } else if (left.left != null && right.right != null) {
            isSymmetric = checkSymmetry(left.left, right.right);
        } else {
            return false;
        }
        
        if (isSymmetric != true) {
            return false;
        }
        
        // Check left's right and right's left.
        // Same logic.
        if (left.right == null && right.left == null) {
            return true;
        } else if (left.right != null && right.left != null) {
            return checkSymmetry(left.right, right.left);
        } else {
            return false;
        }
        
    }
    
    public boolean isSymmetric(TreeNode root) {
        // Edge case: what if there's only one node
        if (root.left == null && root.right == null) {
            return true;
        }
        
        // Edge case: what if there's only one left node
        if (!(root.left != null && root.right != null)) {
            return false;
        }
        
        // Compare left and right recursively
        return checkSymmetry(root.left, root.right);
    }
}

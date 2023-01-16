# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ans=0
    def solve(self,root: TreeNode, max_par:int):
        if root is not None:
            if root.val>=max_par:
                max_par=root.val
                self.ans=self.ans+1
            self.solve(root.left, max_par)
            self.solve(root.right, max_par)
    def goodNodes(self, root: TreeNode) -> int:
        self.solve(root, -10001)
        return self.ans
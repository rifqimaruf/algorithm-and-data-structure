from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        else:
            # Recursive DFS approach
            left_depth = self.maxDepth(root.left)
            right_depth = self.maxDepth(root.right)
            return max(left_depth, right_depth) + 1

def main():
    # Example 1
    root1 = TreeNode(3)
    root1.left = TreeNode(9)
    root1.right = TreeNode(20)
    root1.right.left = TreeNode(15)
    root1.right.right = TreeNode(7)
    
    # Example 2
    root2 = TreeNode(1)
    root2.right = TreeNode(2)
    
    solution = Solution()
    
    # Test case 1
    print(f"Max Depth of Tree 1: {solution.maxDepth(root1)}")  # Output: 3
    
    # Test case 2
    print(f"Max Depth of Tree 2: {solution.maxDepth(root2)}")  # Output: 2

if __name__ == "__main__":
    main()

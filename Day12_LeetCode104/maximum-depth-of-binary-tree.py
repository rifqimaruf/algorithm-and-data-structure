from typing import Optional
from collections import deque

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
        
        # BFS approach
        queue = deque([root])
        depth = 0
        
        while queue:
            level_size = len(queue)
            for _ in range(level_size):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            depth += 1
        
        return depth

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

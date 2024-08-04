from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        for i in range(len(nums)):

            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        return k

def main():
    solution = Solution()

    nums1 = [3, 2, 2, 3]
    val1 = 3
    k1 = solution.removeElement(nums1, val1)
    print(k1, nums1[:k1]) 

    nums2 = [0, 1, 2, 2, 3, 0, 4, 2]
    val2 = 2
    k2 = solution.removeElement(nums2, val2)
    print(k2, nums2[:k2]) 

if __name__ == "__main__":
    main()
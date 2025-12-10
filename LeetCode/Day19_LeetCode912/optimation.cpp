#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to merge two halves
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> leftArray(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> rightArray(nums.begin() + mid + 1, nums.begin() + right + 1);

        int i = 0, j = 0, k = left;

        // Merge the two arrays
        while (i < leftArray.size() && j < rightArray.size()) {
            if (leftArray[i] <= rightArray[j]) {
                nums[k++] = leftArray[i++];
            } else {
                nums[k++] = rightArray[j++];
            }
        }

        // Copy remaining elements from leftArray
        while (i < leftArray.size()) {
            nums[k++] = leftArray[i++];
        }

        // Copy remaining elements from rightArray
        while (j < rightArray.size()) {
            nums[k++] = rightArray[j++];
        }
    }

    // Recursive function for merge sort
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            // Sort the first half
            mergeSort(nums, left, mid);

            // Sort the second half
            mergeSort(nums, mid + 1, right);

            // Merge the sorted halves
            merge(nums, left, mid, right);
        }
    }

    // Main function to sort an array
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> sortedNums = solution.sortArray(nums);

    for (int num : sortedNums) {
        printf("%d ", num);
    }

    return 0;
}

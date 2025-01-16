#include <iostream>  
#include <vector>  
using namespace std;  
  
class Solution {  
public:  
    vector<int> sortArray(vector<int>& nums) {  
        quickSort(nums, 0, nums.size() - 1);  
        return nums;  
    }  
  
private:  
    void quickSort(vector<int>& nums, int low, int high) {  
        if (low < high) {  
            // Partition the array and get the pivot index  
            int pivotIndex = partition(nums, low, high);  
            // Recursively sort elements before and after partition  
            quickSort(nums, low, pivotIndex - 1);  
            quickSort(nums, pivotIndex + 1, high);  
        }  
    }  
  
    int partition(vector<int>& nums, int low, int high) {  
        int pivot = nums[high]; // Choosing the last element as pivot  
        int i = low - 1; // Index of smaller element  
  
        for (int j = low; j < high; j++) {  
            // If current element is smaller than or equal to pivot  
            if (nums[j] <= pivot) {  
                i++; // Increment index of smaller element  
                swap(nums[i], nums[j]); // Swap  
            }  
        }  
        swap(nums[i + 1], nums[high]); // Swap the pivot element with the element at i + 1  
        return i + 1; // Return the partitioning index  
    }  
};  
  
int main() {  
    Solution solution;  
    vector<int> data = {9, 1, 8, 2, 7, 3, 6, 4, 5};  
    vector<int> sortedData = solution.sortArray(data);  
      
    cout << "Sorted Array: ";  
    for (int i = 0; i < sortedData.size(); i++) {  
        cout << sortedData[i] << " ";  
    }  
    return 0;  
}  

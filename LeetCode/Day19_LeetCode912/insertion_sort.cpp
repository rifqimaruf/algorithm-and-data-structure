#include <iostream>  
#include <vector>  
using namespace std;  
  
class Solution {  
public:  
    vector<int> sortArray(vector<int>& nums) {  
        int size = nums.size();  
        for (int i = 1; i < size; i++) {  
            int key = nums[i];  
            int j = i - 1;  
  
            // Move elements of nums[0..i-1], that are greater than key,  
            // to one position ahead of their current position  
            while (j >= 0 && nums[j] > key) {  
                nums[j + 1] = nums[j];  
                j--;  
            }  
            nums[j + 1] = key;  
        }  
        return nums;  
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

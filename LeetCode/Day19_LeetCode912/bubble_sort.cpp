#include <iostream>  
#include <vector>  
using namespace std;  
  
class Solution {  
public:  
    vector<int> sortArray(vector<int>& nums) {  
        int size = nums.size();  
        for(int i = 0; i < size - 1; i++) {  
            for(int j = 0; j < size - i - 1; j++) {  
                if(nums[j] > nums[j + 1]) {  
                    swap(nums[j], nums[j + 1]);  
                }  
            }  
        }  
        return nums;  
    }  
};  
  
int main() {  
    Solution solution;  
    vector<int> data = {9, 1, 8, 2, 7, 3, 6, 4, 5};  
    vector<int> sortedData = solution.sortArray(data);  
      
    cout << "Sorted Array: ";  
    for(int i = 0; i < sortedData.size(); i++) {  
        cout << sortedData[i] << " ";  
    }  
    return 0;  
}  

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int target, k;

    cout << "Enter the size of nums: ";
    cin >> k;

    cout << "Enter the nums: " << endl;
    nums.resize(k); 
    for (int i = 0; i < k; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the target: ";
    cin >> target;

    vector<int> result = solution.twoSum(nums, target);
    cout << "Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

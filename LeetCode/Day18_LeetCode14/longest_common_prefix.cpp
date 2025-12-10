#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string prefix = strs[0]; // Start with the first string as the prefix

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            // Compare characters of the prefix with the current string
            while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
                j++;
            }

            prefix = prefix.substr(0, j); // Update the prefix to the common part

            if (prefix.empty()) {
                return ""; // If the prefix becomes empty, no common prefix exists
            }
        }

        return prefix; // Return the longest common prefix
    }
};


int main() {
    Solution sol;

    // Test case 1
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Longest common prefix: " << sol.longestCommonPrefix(strs1) << endl;

    // Test case 2
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest common prefix: " << sol.longestCommonPrefix(strs2) << endl;

    return 0;
}
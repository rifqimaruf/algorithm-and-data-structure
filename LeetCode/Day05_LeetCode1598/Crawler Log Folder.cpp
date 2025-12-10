# include <iostream>
# include <vector>
# include <string>
using namespace std;


class Solution {
public:
    int minOperations(vector<string>& logs) {
        // Initialize a stack to keep track of directories
        vector<string> stack;

        for (const string& log : logs) {
            if (log == "../") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (log != "./") {
                stack.push_back(log);
            }
        }

        return stack.size();
    }
};
int main(){
    vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};

    Solution sol;
    int result = sol.minOperations (logs);
    cout << result << endl;

    return 0;
}
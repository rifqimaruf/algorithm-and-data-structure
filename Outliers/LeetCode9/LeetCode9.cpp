# include <iostream>
# include <algorithm>
# include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string p = s;
        reverse(p.begin(), p.end());

        return s == p;
    }
};

int main(){
    int x;
    Solution solution;
    cin >> x;
    if(solution.isPalindrome(x)){
        cout << "True";
    }else{
        cout << "False";
    }
    
    return 0;
}
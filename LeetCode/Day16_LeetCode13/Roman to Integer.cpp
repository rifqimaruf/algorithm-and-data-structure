#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int romanToInteger(string& str) {
    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int sum = 0;
    for (int i = 0; i < str.length(); ++i) {
        int value = romanMap[str[i]];
        // If the next number is greater, subtract the current value
        if (i + 1 < str.length() && romanMap[str[i + 1]] > value) {
            sum -= value;
        } else {
            sum += value;
        }
    }
    return sum;
}

int main() {
    string romanNumeral = "MCMXCIV";
    int integerValue = romanToInteger(romanNumeral);
    cout << integerValue << endl; // Output: 1994
    return 0;
}
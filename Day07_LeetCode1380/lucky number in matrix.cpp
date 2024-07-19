#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution{
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckyNumbers;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> minRowValues(m, INT_MAX);
        vector<int> minRowIndices(m, -1);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < minRowValues[i]) {
                    minRowValues[i] = matrix[i][j];
                    minRowIndices[i] = j;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            int candidate = minRowValues[i];
            int colIndex = minRowIndices[i];
            bool isMaxInColumn = true;
            
            for (int k = 0; k < m; ++k) {
                if (matrix[k][colIndex] > candidate) {
                    isMaxInColumn = false;
                    break;
                }
            }
            
            if (isMaxInColumn) {
                luckyNumbers.push_back(candidate);
            }
        }
        
        return luckyNumbers;
    }
};


int main(){
    Solution solution;
    vector<vector<int>> matrix = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    vector<int> result1 = solution.luckyNumbers(matrix);
    cout << "Lucky Numbers: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

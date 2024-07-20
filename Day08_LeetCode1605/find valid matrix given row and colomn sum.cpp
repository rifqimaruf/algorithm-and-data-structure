#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row_sum, vector<int>& col_sum) {
        int rows = row_sum.size();
        int cols = col_sum.size();
        vector<vector<int>> matrix(rows, vector<int>(cols));

        // iterate through each cell of the matrix
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // find minimum value between current row sum and col sum
                int value = min(row_sum[i], col_sum[j]);
                matrix[i][j] = value;

                // subtract the assigned value from row and column sums
                row_sum[i] -= value;
                col_sum[j] -= value;
            }
        }
        return matrix;
    }
};

int main() {
    Solution solution;
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<int> row_sum(m);
    vector<int> col_sum(n);

    cout << "Enter the row sums: " << endl;
    for (int i = 0; i < m; ++i) {
        cin >> row_sum[i];
    }
    cout << "Enter the col sums: "<< endl;
    for (int j = 0; j < n; ++j) {
        cin >> col_sum[j];
    }

    vector<vector<int>> result = solution.restoreMatrix(row_sum, col_sum);
    for (const auto& row : result) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}

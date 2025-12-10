#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    // initialize the triangle
    vector<vector<int>> triangle;

    // loop through each row
    for (int i = 0; i < numRows; i++)
    {
        // create a new row
        vector<int> row(i + 1, 1);

        // fill the value into current row
        for (int j = 1; j < i; j++)
        {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; // the value of current row is the sum of the value previous row*, the provious row with with same index, and the previous row with index - 1
        }

        // add the current row to the triangle
        triangle.push_back(row);
    }
    return triangle;
}

 int main()
 {
    int numRows;
    cout << "Give the number of rows: "; cin >> numRows;

    vector<vector<int>> result = generate(numRows);

    // print the triangle
    for (const auto& row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

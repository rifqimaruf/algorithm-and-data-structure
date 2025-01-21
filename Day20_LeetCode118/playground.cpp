#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate (int numRows)
{
    vector<vector<int>> triangle;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> row(i + 1, 1);

        for(int j = 1; j < i; j++)
        {
            row[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
        }
        triangle.push_back(row);
    }
    return triangle;
}

int main()
{
    int numRows;
    cout << "How much numRows: "; cin >> numRows;

    vector<vector<int>> result = generate(numRows);
    // print triangle
    for (const auto& row :result)
    {
        for (int num :row)
        {
            cout <<num << " ";
        }
    }
}
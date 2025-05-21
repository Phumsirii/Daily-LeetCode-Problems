#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<int> zeroRows, zeroCols;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zeroRows.push_back(i);
                    zeroCols.push_back(j);
                }
            }
        }
        for (int i = 0; i < zeroRows.size(); ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                matrix[zeroRows[i]][j] = 0;
            }
        }
        for (int i = 0; i < zeroCols.size(); ++i)
        {
            for (int j = 0; j < rows; ++j)
            {
                matrix[j][zeroCols[i]] = 0;
            }
        }
        return;
    }
};
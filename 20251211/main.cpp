#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        vector<vector<int>> XAsKey(n + 1);
        vector<vector<int>> YAsKey(n + 1);
        int ans = 0;
        int noOfBuildings = buildings.size();
        for (int i = 0; i < noOfBuildings; ++i)
        {
            int x = buildings[i][0];
            int y = buildings[i][1];
            XAsKey[x].push_back(y);
            YAsKey[y].push_back(x);
        }

        for (int i = 1; i <= n; ++i)
        {
            if (XAsKey[i].size() > 2)
            {
                sort(XAsKey[i].begin(), XAsKey[i].end());
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            if (YAsKey[i].size() > 2)
            {
                sort(YAsKey[i].begin(), YAsKey[i].end());
                for (int j = 1; j < YAsKey[i].size() - 1; ++j)
                {
                    int currentX = YAsKey[i][j];
                    if (XAsKey[currentX].size() > 2 && currentX != XAsKey[currentX][0] && currentX != XAsKey[currentX].back())
                        ++ans;
                }
            }
        }
        return ans;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        unordered_map<int, int> countMap;
        for (int num : arr)
        {
            countMap[num]++;
        }
        int luckyNumber = -1;
        for (const auto &pair : countMap)
        {
            if (pair.first == pair.second)
            {
                luckyNumber = max(luckyNumber, pair.first);
            }
        }
        return luckyNumber;
    }
};
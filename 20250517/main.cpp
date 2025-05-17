#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        unordered_map<int, int> colorCount;
        for (int i = 0; i < 3; ++i)
            colorCount[i] = 0;
        for (int &num : nums)
            colorCount[num]++;
        int n = nums.size();
        int i = 0;
        int currentColor = 0;
        while (i < n)
        {
            int currentCount = colorCount[currentColor];
            for (int j = 0; j < currentCount; ++j)
            {
                nums[i++] = currentColor;
            }
            ++currentColor;
        }
        return;
    }
};
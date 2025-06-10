#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxDifference(string s)
    {
        vector<int> charCount(26);
        for (char c : s)
        {
            charCount[c - 'a']++;
        }
        int maxOdd = -1;
        int minEven = 102;
        for (int i = 0; i < 26; i++)
        {
            if (charCount[i] % 2 == 1)
            {
                maxOdd = max(maxOdd, charCount[i]);
            }
            else if (charCount[i] > 0)
            {
                minEven = min(minEven, charCount[i]);
            }
        }
        return maxOdd - minEven;
    }
};
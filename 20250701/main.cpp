#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int possibleStringCount(string word)
    {
        char currentChar = word[0];
        int count = 0;
        int n = word.size();
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (word[i] == currentChar)
            {
                count++;
            }
            else
            {
                currentChar = word[i];
                ans += count;
                count = 0;
            }
        }
        ans += count;
        return ans;
    }
};
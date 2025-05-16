#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int lastIndex = 0;
        for (int j = 1; j < n; ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                if (condition_2(words[i], words[j]) && dp[i] + 1 > dp[j] && groups[i] != groups[j])
                {
                    dp[j] = dp[i] + 1;
                    prev[j] = i;
                }
            }
            if (dp[j] > dp[lastIndex])
                lastIndex = j;
        }
        vector<string> result;
        while (lastIndex != -1)
        {
            result.push_back(words[lastIndex]);
            lastIndex = prev[lastIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool condition_2(string s1, string s2)
    {
        if (s1.size() != s2.size() || s1 == s2)
            return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] != s2[i])
            {
                ++diff;
                if (diff > 1)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
}
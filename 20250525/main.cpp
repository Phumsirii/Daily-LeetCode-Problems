#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> prefix_suffix_count;
        int ans = 0;
        int mid_result = 0;

        for (const string &word : words)
        {
            string reversed_word = string(1, word[1]) + word[0];
            if (prefix_suffix_count[reversed_word] > 0)
            {
                ans += 4;
                prefix_suffix_count[reversed_word]--;
            }
            else
            {
                prefix_suffix_count[word]++;
            }
        }

        for (auto &[word, count] : prefix_suffix_count)
        {
            if (word[0] == word[1])
            {
                ans += 4 * (count / 2);
                if (count % 2)
                    mid_result = 2;
            }
        }

        return ans + mid_result;
    }
};

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    string clearStars(string s)
    {
        vector<stack<int>> locations(26);
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '*')
            {
                for (int j = 0; j < 26; ++j)
                {
                    if (!locations[j].empty())
                    {
                        s[locations[j].top()] = '*';
                        locations[j].pop();
                        break;
                    }
                }
            }
            else
            {
                locations[s[i] - 'a'].push(i);
            }
        }
        string result;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != '*')
            {
                result += s[i];
            }
        }
        return result;
    }
};

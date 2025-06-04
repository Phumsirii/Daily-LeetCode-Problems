#include <iostream>

using namespace std;

class Solution
{
public:
    string answerString(string word, int numFriends)
    {
        if (numFriends == 1)
        {
            return word;
        }
        int n = word.size();
        string result;
        for (int i = 0; i < n; i++)
        {
            result = max(result, word.substr(i, min(n - numFriends + 1, n - i)));
        }
        return result;
    }
};
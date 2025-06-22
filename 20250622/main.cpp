#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        string current = "";
        vector<string> result;
        for (char c : s)
        {
            current += c;
            if (current.size() == k)
            {
                result.push_back(current);
                current = "";
            }
        }
        if (current.size() == 0)
        {
            return result;
        }
        while (current.size() < k)
        {
            current += fill;
        }
        result.push_back(current);
        return result;
    }
};
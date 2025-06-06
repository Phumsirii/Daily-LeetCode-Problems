#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string robotWithString(string s)
    {
        unordered_map<char, int> charCount;
        for (char c : s)
        {
            charCount[c]++;
        }
        stack<char> st;
        string result;
        char minChar = 'a';
        for (char c : s)
        {
            st.push(c);
            charCount[c]--;
            while (minChar <= 'z' && charCount[minChar] == 0)
            {
                minChar++;
            }
            while (!st.empty() && st.top() <= minChar && charCount[st.top()] >= 0)
            {
                result += st.top();
                st.pop();
            }
        }
        return result;
    }
};
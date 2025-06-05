#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> parent = vector<int>(26);
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return;
        if (rootX < rootY)
            parent[rootY] = rootX;
        else
            parent[rootX] = rootY;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.size(), baseStrN = baseStr.size();

        for (int i = 0; i < 26; ++i)
            parent[i] = i;

        for (int i = 0; i < n; ++i)
        {
            unionSets(s1[i] - 'a', s2[i] - 'a');
        }

        for (int i = 0; i < baseStrN; ++i)
        {
            int root = find(baseStr[i] - 'a');
            baseStr[i] = 'a' + root;
        }

        return baseStr;
    }
};
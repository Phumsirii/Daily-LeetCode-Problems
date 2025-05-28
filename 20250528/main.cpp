#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> adj1, adj2;
    vector<bool> visited1, visited2;
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        int n1 = edges1.size();
        int n2 = edges2.size();
        adj1.resize(n1 + 1, vector<int>());
        adj2.resize(n2 + 1, vector<int>());
        visited1.resize(n1 + 1, false);
        visited2.resize(n2 + 1, false);
        for (const auto &edge : edges1)
        {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (const auto &edge : edges2)
        {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        int best2 = 0;
        for (int i = 0; i <= n2; ++i)
        {
            int count = dfs(i, visited2, adj2, k - 1);
            visited2.assign(n2 + 1, false);
            best2 = max(best2, count);
        }
        vector<int> result;
        for (int i = 0; i <= n1; ++i)
        {
            int count = dfs(i, visited1, adj1, k);
            visited1.assign(n2 + 1, false);
            result.push_back(count + best2);
        }
        return result;
    }

    int dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, int k)
    {
        if (visited[node] || k < 0)
            return 0;
        visited[node] = true;
        int count = 1;
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                count += dfs(neighbor, visited, adj, k - 1);
            }
        }
        return count;
    }
};
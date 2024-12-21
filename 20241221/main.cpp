#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> sparseMatrix;
    int componentsCount = 0;
    int dfs(int currentNode,int prevNode,vector<int>& values,int &k){
        int sum = values[currentNode];
        for(auto nextNode:sparseMatrix[currentNode]){
            if(nextNode==prevNode) continue;
            sum+=dfs(nextNode,currentNode,values,k);
        }
        sum%=k;
        if(sum==0) componentsCount++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        sparseMatrix.resize(n,vector<int>());
        for(auto edge:edges){
            sparseMatrix[edge[0]].push_back(edge[1]);
            sparseMatrix[edge[1]].push_back(edge[0]);
        }
        dfs(0,-1,values,k);
        return componentsCount;
    }
};
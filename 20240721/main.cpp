#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& stack) {
        if (visited[node] == 1) return false; // already processed
        if (stack[node] == 1) return true;    // cycle detected
        
        stack[node] = 1; // mark node in the current path
        for (int neighbor : adj[node]) {
            if (hasCycle(neighbor, adj, visited, stack)) return true;
        }
        stack[node] = 0;      // unmark the node
        visited[node] = 1;    // mark node as processed
        return false;
    }
    
    bool detectCycle(int k, vector<vector<int>>& adj) {
        vector<int> visited(k, 0), stack(k, 0);
        for (int i = 0; i < k; ++i) {
            if (!visited[i] && hasCycle(i, adj, visited, stack)) return true;
        }
        return false;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> result(k,vector<int> (k,0)),topToBottom(k),leftToRight(k);
        vector<int> inDegreeFromLeft(k,0),inDegreeFromTop(k,0);
        //specify next and in degree of each numbers
        for(vector<int> &x:rowConditions){
            //x0 to x1
            topToBottom[x[0]-1].push_back(x[1]-1);
            ++inDegreeFromTop[x[1]-1];
        }
        for(vector<int> &x:colConditions){
            //x0 to x1
            leftToRight[x[0]-1].push_back(x[1]-1);
            ++inDegreeFromLeft[x[1]-1];
        }

        if (detectCycle(k,topToBottom) || detectCycle(k,leftToRight)) return vector<vector<int>> (0);
        
        queue<int> leftToRightQ;
        for(int i=0;i<k;++i){
            if (inDegreeFromLeft[i]==0) leftToRightQ.push(i);
        }
        vector<int> resultColN(k);
        int it1=0;
        while(!leftToRightQ.empty()){
            int currentK=leftToRightQ.front();
            for(int &x:leftToRight[currentK]){
                if (inDegreeFromLeft[x]>0){
                    --inDegreeFromLeft[x];
                    if (inDegreeFromLeft[x]==0) leftToRightQ.push(x);
                }
            }
            resultColN[currentK]=it1;
            it1++;
            leftToRightQ.pop();
        }
        queue<int> topToBottomQ;
        for(int i=0;i<k;++i){
            if (inDegreeFromTop[i]==0) topToBottomQ.push(i);
        }
        vector<int> resultRowN(k);
        int it2=0;
        while(!topToBottomQ.empty()){
            int currentK=topToBottomQ.front();
            for(int &x:topToBottom[currentK]){
                if (inDegreeFromTop[x]>0){
                    --inDegreeFromTop[x];
                    if (inDegreeFromTop[x]==0) topToBottomQ.push(x);
                }
            }
            resultRowN[currentK]=it2;
            it2++;
            topToBottomQ.pop();
        }
        for(int i=0;i<k;++i) result[resultRowN[i]][resultColN[i]]=i+1;
        return result;
    }
};
int main(){
    Solution s;
    vector<vector<int>> rowConditions = {{1,2},{2,3},{3,1},{2,3}},colConditions = {{2,1}};
    vector<vector<int>> result=s.buildMatrix(3,rowConditions,colConditions);
    for(vector<int> &x:result){
        for(int &y:x) cout<<y<<" ";
        cout<<endl;
    }
}
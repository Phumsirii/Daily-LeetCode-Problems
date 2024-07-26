#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> floydWarshall(n,vector<int> (n,1e9));
        for(vector<int> &x:edges)floydWarshall[x[0]][x[1]]=floydWarshall[x[1]][x[0]]=x[2];
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j) floydWarshall[i][j]=floydWarshall[j][i]=min(floydWarshall[i][j],floydWarshall[i][k]+floydWarshall[k][j]);
            }
        }
        int ans,noOfans=200;
        for(int i=0;i<n;++i){
            int currentNo=0;
            for(int j=0;j<n;++j){
                if (i!=j && floydWarshall[i][j]<=distanceThreshold) currentNo++;
            }
            if (currentNo<=noOfans){
                noOfans=currentNo;
                ans=i;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    int n = 4,distanceThreshold = 4;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout<<s.findTheCity(n,edges,distanceThreshold);
}
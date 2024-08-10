#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size(),groups=0;
        vector<vector<bool>> expandedGrid(3*n,vector<bool> (3*n,true));
        vector<int> firstHelper={-1,1,0,0},secondHelper={0,0,-1,1};
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                // cout<<i<<" "<<j<<" ";
                // cout<<grid[i][j]<<endl;
                if (grid[i][j]=='/'){
                    int topRightI=3*i,topRightJ=3*j+2;
                    expandedGrid[topRightI][topRightJ]=false;
                    expandedGrid[topRightI+1][topRightJ-1]=false;
                    expandedGrid[topRightI+2][topRightJ-2]=false;
                }
                else if (grid[i][j]=='\\'){
                    int topLeftI=3*i,topLeftJ=3*j;
                    expandedGrid[topLeftI][topLeftJ]=false;
                    expandedGrid[topLeftI+1][topLeftJ+1]=false;
                    expandedGrid[topLeftI+2][topLeftJ+2]=false;
                }
            }
        }
        for(int i=0;i<3*n;++i){
            for(int j=0;j<3*n;++j){
                if (expandedGrid[i][j]){
                    expandedGrid[i][j]=false;
                    //make all connected components false
                    queue<pair<int,int>> tmpq;
                    tmpq.push(make_pair(i,j));
                    while(!tmpq.empty()){
                        int currentI=tmpq.front().first,currentJ=tmpq.front().second;
                        tmpq.pop();
                        for(int x=0;x<4;++x){
                            int nextI=currentI+firstHelper[x],nextJ=currentJ+secondHelper[x];
                            if (nextI<0 || nextJ<0 || nextI>=3*n || nextJ>=3*n || !expandedGrid[nextI][nextJ]) continue;
                            tmpq.push(make_pair(nextI,nextJ));
                            expandedGrid[nextI][nextJ]=false;
                        }
                    }
                    ++groups;
                }
            }
        }
        return groups;
    }
};
int main(){
    Solution s;
    vector<string> grid = {"/\\","\\/"};
    cout<<s.regionsBySlashes(grid)<<endl;
}
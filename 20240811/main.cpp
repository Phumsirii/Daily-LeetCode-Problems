#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> directionX={-1,1,0,0},directionY={0,0,1,-1};
    int minDays(vector<vector<int>>& grid) {
        if (countIslands(grid)!=1) return 0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                //skip water
                if (!grid[i][j]) continue;
                //try making this water
                grid[i][j]=0;
                if (countIslands(grid)!=1) return 1;
                grid[i][j]=1;
            }
        }
        return 2;
    }
    int countIslands(vector<vector<int>> &grid){
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool> (cols,false));
        int islandCounts=0;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if (!visited[i][j] && grid[i][j]){
                    exploreIslands(i,j,grid,visited);
                    ++islandCounts;
                }
            }
        }
        return islandCounts;
    }
    void exploreIslands(int row,int col,vector<vector<int>> &grid,vector<vector<bool>> &visited){
        visited[row][col]=true;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<4;++i){
            int newRow=row+directionY[i];
            int newCol=col+directionX[i];
            if (newRow>=0 && newRow<rows && newCol>=0 && newCol<cols && !visited[newRow][newCol] &&grid[newRow][newCol]) exploreIslands(newRow,newCol,grid,visited);
        }
        return ;
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid={{1,0,1,0}};
    cout<<s.minDays(grid)<<endl;
}
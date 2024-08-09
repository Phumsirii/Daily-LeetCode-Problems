#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size()<3 || grid[0].size()<3) return 0;
        int cnt=0;
        int rows=grid.size(),cols=grid[0].size();
        //iterate through all top left cell of 3x3 squares
        for(int row=0;row<rows-2;++row){
            for(int col=0;col<cols-2;++col){
                int firstRowSum=grid[row][col]+grid[row][col+1]+grid[row][col+2];
                //for row sum
                if (grid[row+1][col]+grid[row+1][col+1]+grid[row+1][col+2]!=firstRowSum) continue;
                else if (grid[row+2][col]+grid[row+2][col+1]+grid[row+2][col+2]!=firstRowSum) continue;
                //for col sum
                else if (grid[row][col]+grid[row+1][col]+grid[row+2][col]!=firstRowSum) continue;
                else if (grid[row][col+1]+grid[row+1][col+1]+grid[row+2][col+1]!=firstRowSum) continue;
                else if (grid[row][col+2]+grid[row+1][col+2]+grid[row+2][col+2]!=firstRowSum) continue;
                else if (grid[row][col]+grid[row+2][col+2]!=grid[row+2][col]+grid[row][col+2]) continue;
                vector<bool> checkNumbers(9,false);
                bool success=true;
                for(int i=0;i<3;++i){
                    for(int j=0;j<3;++j){
                        if (grid[row+i][col+j]==0 || grid[row+i][col+j]>9 || checkNumbers[grid[row+i][col+j]-1]){
                            success=false;
                            break;
                        }
                        checkNumbers[grid[row+i][col+j]-1]=true;
                    }
                }
                if (success) ++cnt;
            }
        }
        return cnt;
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid={{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    cout<<s.numMagicSquaresInside(grid);
}
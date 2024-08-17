#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows=points.size(),cols=points[0].size();
        vector<long long> prevRow(cols);
        for(int col=0;col<cols;++col) prevRow[col]=points[0][col];
        //find the bect for the remaining rows
        for(int row=1;row<rows;++row){
            vector<long long> currentRow(cols);
            vector<long long> leftMax(cols);
            vector<long long> rightMax(cols);
            //take the prev (needs to  deduct 1 point) or use the current col
            leftMax[0]=prevRow[0];
            for(int i=1;i<cols;++i) leftMax[i]=max(leftMax[i-1]-1,prevRow[i]);
            rightMax[cols-1]=prevRow[cols-1];
            for(int i=cols-2;i>=0;--i) rightMax[i]=max(rightMax[i+1]-1,prevRow[i]);
            //generate the best for the current row
            for(int col=0;col<cols;++col) currentRow[col]=points[row][col]+max(leftMax[col],rightMax[col]);
            //finalise this row
            prevRow=currentRow;
        }
        long long maxPoints=0;
        for(int col=0;col<cols;++col) maxPoints=max(maxPoints,prevRow[col]);
        return maxPoints;
    }
};
int main(){
    Solution s;
    vector<vector<int>> points = {{1,2,3},{1,5,1},{3,1,1}};
    cout<<s.maxPoints(points);
}
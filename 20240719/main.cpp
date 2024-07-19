#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int noOfRows=matrix.size(),noOfCols=matrix[0].size();
        vector<int> minimumInEachRow(noOfRows);
        for(int i=0;i<noOfRows;++i){
            int idx=0;
            for(int j=1;j<noOfCols;++j){
                if (matrix[i][j]<matrix[i][idx]) idx=j;
            }
            minimumInEachRow[i]=idx;
        }
        vector<int> result;
        for(int i=0;i<noOfRows;++i){
            //see if it's the maximum in the col
            bool found=false;
            for(int j=0;j<noOfRows;++j){
                if (matrix[j][minimumInEachRow[i]]>matrix[i][minimumInEachRow[i]]){
                    found = true;
                    break;
                }
            }
            if (!found) result.push_back(matrix[i][minimumInEachRow[i]]);
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,10,4,2},{9,3,8,7},{15,16,17,12}};
    vector<int> result=s.luckyNumbers(matrix);
    for(int &x:result) cout<<x<<" ";
    cout<<endl;
}
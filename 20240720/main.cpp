#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rowN=rowSum.size(),colN=colSum.size();
        vector<vector<int>> result(rowN,vector<int> (colN,0));
        for(int i=0;i<rowN;++i) result[i][0]=rowSum[i];
        int rowIt=0;
        //make each column balance
        for(int i=1;i<colN;++i){
            int target=colSum[i];
            while(target>0){
                if (target<=result[rowIt][0]){
                    result[rowIt][0]-=target;
                    result[rowIt][i]+=target;
                    target=0;
                }else{
                    target-=result[rowIt][0];
                    result[rowIt][i]+=result[rowIt][0];
                    result[rowIt][0]=0;
                    rowIt=(rowIt+1)%rowN;
                }
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> rowSum = {5,7,10}, colSum = {8,6,8};
    vector<vector<int>> result=s.restoreMatrix(rowSum,colSum);
    for(vector<int> &x:result){
        for(int &i:x) cout<<i<<" ";
        cout<<endl;
    }
}
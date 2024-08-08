#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        //this is number of layers, let the starting point be layer 0
        int noOfLayers=max({cols-cStart-1,cStart,rows-rStart-1,rStart});
        int currentLayer=2; //start at the second layer, the first is manually done
        vector<vector<int>> result(rows*cols,vector<int> (2,99));
        result[0][0]=rStart;
        result[0][1]=cStart;
        int cnt=1;
        //the first layer start at the mid
        if (noOfLayers>=1){
            if (cStart+1<cols){
                result[cnt][0]=rStart;
                result[cnt++][1]=cStart+1;
            }
            //bottom right to bottom left
            for(int i=1;i>=-1;--i){
                if (rStart+1>=rows) break;
                if (cStart+i<cols && cStart+i>=0){
                    result[cnt][0]=rStart+1;
                    result[cnt++][1]=cStart+i;
                }
            }
            if (cStart-1>=0){
                result[cnt][0]=rStart;
                result[cnt++][1]=cStart-1;
            }
            //top left to top right
            for(int i=-1;i<=1;++i){
                if (rStart-1<0) break;
                if (cStart+i<cols && cStart+i>=0){
                    result[cnt][0]=rStart-1;
                    result[cnt++][1]=cStart+i;
                }
            }
        }
        //the rest layer starts at the top left
        while(currentLayer<=noOfLayers){
            //moving from top right to bottom right
            for(int i=-currentLayer+1;i<currentLayer;++i){
                //too far to the right
                if (cStart+currentLayer>=cols) break;
                if (rStart+i<rows && rStart+i>=0){
                    result[cnt][0]=rStart+i;
                    result[cnt++][1]=cStart+currentLayer;
                }
            }
            //moving from right to left
            for(int i=currentLayer;i>=-currentLayer;--i){
                //too low
                if (rStart+currentLayer>=rows) break;
                if (cStart+i<cols && cStart+i>=0){
                    result[cnt][0]=rStart+currentLayer;
                    result[cnt++][1]=cStart+i;
                }
            }
            //moving from bottom left to top left
            for(int i=currentLayer-1;i>=-currentLayer;--i){
                //too far left
                if (cStart-currentLayer<0) break;
                if (rStart+i>=0 && rStart+i<rows){
                    result[cnt][0]=rStart+i;
                    result[cnt++][1]=cStart-currentLayer;
                }
            }
            //moving from top left to top right
            for(int i=-currentLayer+1;i<=currentLayer;++i){
                //too high
                if (rStart-currentLayer<0) break;
                if (cStart+i>=0 && cStart+i<cols){
                    result[cnt][0]=rStart-currentLayer;
                    result[cnt++][1]=cStart+i;
                }
            }
            ++currentLayer;
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<vector<int>> result=s.spiralMatrixIII(3,3,0,0);
    for(vector<int> &x:result){
        cout<<x[0]<<" "<<x[1]<<endl;
    }
}
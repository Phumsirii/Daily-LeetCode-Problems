#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int result=0,n=rating.size();
        for(int mid=1;mid<n-1;++mid){
            int leftSmaller=0,leftLarger=0,rightSmaller=0,rightLarger=0;
            for(int i=0;i<mid;++i){
                if (rating[mid]<rating[i]) ++leftLarger;
                else ++leftSmaller;
            }
            for(int i=mid+1;i<n;++i){
                if (rating[mid]<rating[i]) ++rightLarger;
                else ++rightSmaller;
            }
            result+=(leftSmaller*rightLarger+leftLarger*rightSmaller);
        }
        return result;
    }
};
int main(){
    Solution s;
    //all ratings are always unique
    vector<int> rating = {2,5,3,4,1};
    cout<<s.numTeams(rating);
}
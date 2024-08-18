#include <iostream>
#include <queue>
#include <set>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> pushed;
        pushed.insert(1);
        for(int i=1;i<n;++i){
            long current=*(pushed.begin());
            pushed.erase(pushed.begin());
            pushed.insert(current*2);
            pushed.insert(current*3);
            pushed.insert(current*5);
        }
        return *(pushed.begin());
    }
};
int main(){
    Solution s;
    cout<<s.nthUglyNumber(10)<<endl;
}
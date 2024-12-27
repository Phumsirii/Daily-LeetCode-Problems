#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int valueI = values[0];
        int ans = 0;
        for(int i = 1; i < n ; ++i){
            --valueI;
            ans = max(ans, valueI + values[i]);
            valueI = max(valueI, values[i]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> values = {8,1,5,2,6};
    cout<< "Ans: " << endl;
    cout << sol.maxScoreSightseeingPair(values) << endl;
    cout << "End" << endl;
    return 0;
}
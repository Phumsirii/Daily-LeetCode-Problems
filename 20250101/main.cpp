#include <iostream>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int oneCount = 0;
        for(char &c:s){
            if(c == '1') ++oneCount;
        }      
        int result = 0;
        int leftZero = 0;
        for(int i = 0; i < n - 1; ++i){
            if (s[i] == '0') ++leftZero;
            else --oneCount;
            result = max(result, leftZero + oneCount);
        }
        return result;
    }
};
#include <iostream>
#include <vector>   

using namespace std; 

class Solution {
public:
    vector<int> dp;
    int moduloNumber = (1e9) + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high + 1,-1);
        int result = 0;
        for(int i = low; i <= high; ++i) {
            result += recur(zero,one,i);
            result %= moduloNumber;
        }
        return result;
    }
    int recur(int &zero, int &one,int length){
        if (length < min(zero, one)) return 0;
        if (dp[length] >= 0) return dp[length];
        int result = 0;
        if (zero == length) ++result;
        if (one == length) ++result;
        result += recur(zero,one,length - zero);
        result %= moduloNumber;
        result += recur(zero,one,length - one);
        result %= moduloNumber;
        return dp[length] = result;
    }
};
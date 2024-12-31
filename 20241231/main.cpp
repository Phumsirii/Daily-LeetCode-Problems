#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> dp;
    int n;

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(),-1);
        n = days.size();
        return recur(0,days,costs);    
    }
    
    // days[currentDayPointer] is currently the first day uncovered
    int recur(int currentDayPointer,vector<int> &days,vector<int> &costs){
        if (currentDayPointer >= n) return 0;
        if (dp[currentDayPointer] != -1) return dp[currentDayPointer];
        int oneDayCost = costs[0] + recur(currentDayPointer+1,days,costs);
        int cover7Days = days[currentDayPointer] + 6;
        int tmp = currentDayPointer;
        while(tmp < n && days[tmp] <= cover7Days) ++tmp;
        int sevenDayCost = costs[1] + recur(tmp,days,costs);
        tmp = currentDayPointer;
        int cover30days = days[currentDayPointer] + 29;
        while(tmp < n && days[tmp] <= cover30days) ++tmp;
        int thirtyDayCost = costs[2] + recur(tmp,days,costs);
        return dp[currentDayPointer] = min(oneDayCost,min(sevenDayCost,thirtyDayCost));
    }
};
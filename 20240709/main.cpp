#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currenttime=0,it=0,n=customers.size();
        double totaltime=0.0;
        for(int i=0;i<n;++i){ //for all customers
            //starting time of this customer
            currenttime=max(currenttime,customers[i][0]);
            int finishtime=currenttime+customers[i][1];
            currenttime=finishtime;
            totaltime+=(finishtime-customers[i][0]);
        }
        return totaltime/n;    
    }
};
int main(){
    Solution s;
    vector<vector<int>> v1={{1,2},{2,5},{4,3}};
    vector<vector<int>> v2={{5,2},{5,4},{10,3},{20,1}};
    cout<<s.averageWaitingTime(v1)<<endl;
    cout<<s.averageWaitingTime(v2)<<endl;
}
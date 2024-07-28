#include <bits/stdc++.h>
using namespace std;
class timeStamp{
    public:
    int time;
    int location;
    timeStamp(){};
    timeStamp(int t,int dest){
        time=t;
        location=dest;
    }
    bool operator<(const timeStamp &other) const{
        return time>other.time;
    }
};
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        //change is the change of green-red
        priority_queue<timeStamp> pq;
        int minTime=INT_MAX,secMinTime=INT_MAX;
        vector<vector<int>> neighbors(n);
        for(const vector<int> &x:edges){
            neighbors[x[0]-1].push_back(x[1]-1);
            neighbors[x[1]-1].push_back(x[0]-1);
        }
        pq.push(timeStamp(0,0));
        while(!pq.empty()){
            int arrivaltime=pq.top().time;
            int location=pq.top().location;
            pq.pop();
            if (arrivaltime>=secMinTime) break;
            int waitTime=0;
            if ((arrivaltime/change)%2){
                waitTime=change-(arrivaltime%change);
            }
            int newArrivingTime=arrivaltime+waitTime+time;
            if (newArrivingTime>=secMinTime) break;
            //see all neighbors
            for (const int &neighbor:neighbors[location]){
                if (neighbor == n - 1) {
                    if (newArrivingTime < minTime) {
                        secMinTime = minTime;
                        minTime = newArrivingTime;
                    } else if (newArrivingTime > minTime && newArrivingTime < secMinTime) {
                        secMinTime = newArrivingTime;
                    }
                }
                pq.push(timeStamp(newArrivingTime,neighbor));
            }
        }
        return secMinTime;
    }
};
int main(){
    Solution s;
    int n = 5, time = 3, change = 5;
    vector<vector<int>>  edges = {{1,2},{1,3},{1,4},{3,4},{4,5}};
    cout<<s.secondMinimum(n,edges,time,change);
}
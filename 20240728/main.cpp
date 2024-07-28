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
        vector<vector<int>> neighbors(n);
        vector<int> freq(n,0),minDist(n,1e9),secMinDist(n,1e9);
        for(const vector<int> &x:edges){
            neighbors[x[0]-1].push_back(x[1]-1);
            neighbors[x[1]-1].push_back(x[0]-1);
        }
        pq.push(timeStamp(0,0));
        while(!pq.empty()){
            int arrivaltime=pq.top().time;
            int location=pq.top().location;
            freq[location]++;
            if (location==n-1 && freq[location]==2) return arrivaltime;
            pq.pop();
            int waitTime=0;
            if ((arrivaltime/change)%2){
                waitTime=change-(arrivaltime%change);
            }
            int newArrivingTime=arrivaltime+waitTime+time;
            //see all neighbors
            for (const int &neighbor:neighbors[location]){
                if (freq[neighbor]==2) continue;
                if (newArrivingTime<minDist[neighbor]){
                    secMinDist[neighbor]=minDist[neighbor];
                    minDist[neighbor]=newArrivingTime;
                }else if (newArrivingTime>minDist[neighbor] && newArrivingTime<secMinDist[neighbor]){
                    secMinDist[neighbor]=newArrivingTime;
                }else continue;
                pq.push(timeStamp(newArrivingTime,neighbor));
            }
        }
        return 0;
    }
};
int main(){
    Solution s;
    int n = 5, time = 3, change = 5;
    vector<vector<int>>  edges = {{1,2},{1,3},{1,4},{3,4},{4,5}};
    cout<<s.secondMinimum(n,edges,time,change);
}
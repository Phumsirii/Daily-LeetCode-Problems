#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int numQueries = queries.size();
        int numBuildings = heights.size();
        vector<int> result(numQueries, -1);
        vector<int> tallestBuildings(numBuildings, 0);
        set<pair<int,int>> heightToIndex;
        tallestBuildings[numBuildings-1] = heights[numBuildings-1];
        //index and height
        heightToIndex.insert({numBuildings-1, heights[numBuildings-1]});
        for(int i=numBuildings-2; i>=0; --i){
            tallestBuildings[i] = max(tallestBuildings[i+1], heights[i]);
            heightToIndex.insert({i, heights[i]});
        }
        for(int i = 0;i<numQueries; ++i){
            if (queries[i][0] == queries[i][1]){
                result[i] = queries[i][0];
                continue;
            }
            int currentRightPosition = max(queries[i][0], queries[i][1]);
            if (heights[queries[i][0]] > heights[queries[i][1]]) {
                swap(queries[i][0], queries[i][1]);
            }
            int currentMaxHeight = heights[queries[i][1]];
            if (heights[currentRightPosition] == currentMaxHeight && (currentMaxHeight > heights[queries[i][0]] || currentMaxHeight > heights[queries[i][1]])){
                result[i] = currentRightPosition;
                continue;
            }
            //never reach the taller building
            if (tallestBuildings[currentRightPosition] <= currentMaxHeight){
                continue;
            }
            ++currentRightPosition;
            //find the first building which is taller than currentMaxHeight
            auto it = heightToIndex.upper_bound({currentRightPosition, 0});
            while(it != heightToIndex.end()){
                if (it->second > currentMaxHeight){
                    result[i] = it->first;
                    break;
                }
                ++it;
            }
        }
        return result;
    }
};
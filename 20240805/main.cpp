#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        //value will be -1 when the first one is edited
        unordered_map<string,int> string_position;
        int n=arr.size();
        vector<bool> isDistinct(n,true);
        for(int i=0;i<n;++i){
            //first string x found
            if (string_position.find(arr[i])==string_position.end()){
                string_position[arr[i]]=i;
            }else{
                isDistinct[i]=false;
                if (string_position[arr[i]]!=-1) isDistinct[string_position[arr[i]]]=false;
                string_position[arr[i]]=-1;
            }
        }
        for(int i=0;i<n;++i){
            if (isDistinct[i]) --k;
            if (k==0) return arr[i];
        }
        return "";
    }
};
int main(){

}
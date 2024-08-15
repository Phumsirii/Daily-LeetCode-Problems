#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // number of 5 10 change at a time
        int changeNote5=0,changeNote10=0;
        for(int &x:bills){
            if (x==5) ++changeNote5;
            else if (x==10){
                if (changeNote5<=0) return false;
                --changeNote5;
                ++changeNote10;
            }else{ //receiving a 20 note
                if (changeNote10>0 && changeNote5>0){
                    --changeNote10;
                    --changeNote5;
                }else if (changeNote5>=3) changeNote5-=3;
                else return false;
            }
        }
        return true;
    }
};
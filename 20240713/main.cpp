#include <bits/stdc++.h>
using namespace std;
class Robot{
    public:
    int position;
    int id;
    int health;
    bool moveright;
    Robot(){};
    Robot(int id,int position,int health,bool moveright){
        this->id=id;
        this->position=position;
        this->health=health;
        this->moveright=moveright;
    }
};
class Solution {
public:
    bool endGame(vector<Robot> &board,int &n){
        if (n<=1) return true;
        bool rightfound=false,leftfound=false;
        for(Robot &r:board){
            //the robot died
            if (r.health==0) continue;
            if (r.moveright) rightfound=true;
            else leftfound=true;
            if (rightfound && leftfound) break;
        }
        if (rightfound xor leftfound) return true;
        int leftmaxpostion=-1e9,rightminposition=1e9;
        for(Robot &r:board){
            if (r.health==0) continue;
            if (r.moveright) rightminposition=min(rightminposition,r.position);
            else leftmaxpostion=max(leftmaxpostion,r.position);
        }
        return leftmaxpostion<rightminposition;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<Robot> board(positions.size());
        map<int,int> position_id;
        int n=positions.size();
        for(int i=0;i<n;++i){
            position_id[positions[i]]=i;
            board[i].position=positions[i];
            board[i].health=healths[i];
            board[i].id=i;
            board[i].moveright=(directions[i]=='R');
        }    
        while(true){
            //for all robots
            for(Robot &r:board){
                if (r.health==0) continue;
                int initialposition=r.position;
                int finalposition=r.position;
                if (r.moveright) ++finalposition;
                else --finalposition;
                //check if there's no robot in the final position
                if (position_id.find(finalposition)==position_id.end() || board[position_id[finalposition]].moveright==r.moveright){
                    position_id[finalposition]=r.id;
                    position_id.erase(initialposition);
                    r.position=finalposition;
                }else{
                    //check if r has higher health
                    if (r.health>board[position_id[finalposition]].health){
                        //kill the one here
                        int idkilled=position_id[finalposition];
                        board[idkilled].health=0;
                        board[idkilled].position=(1e9)+1;
                        position_id[finalposition]=r.id;
                        position_id.erase(initialposition);
                        r.position=finalposition;
                        r.health=r.health-1;
                        --n;
                    } else if (r.health==board[position_id[finalposition]].health){ 
                        //both are killed
                        int idkilled=position_id[finalposition];
                        board[idkilled].health=0;
                        board[idkilled].position=(1e9)+1;
                        position_id.erase(finalposition);
                        position_id.erase(initialposition);
                        r.health=0;
                        r.position=(1e9)+1;
                        n-=2;
                    }else{
                        //kill r
                        position_id.erase(initialposition);
                        r.health=0;
                        r.position=(1e9)+1;
                        --n;
                        board[position_id[finalposition]].health=board[position_id[finalposition]].health-1;
                    }
                }
            }
            if (endGame(board,n)) break;
        }
        vector<int> result;
        for(Robot &r:board){
            if (r.health>0)result.push_back(r.health);
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> positions = {1,2,5,6}, healths = {10,10,11,11};
    string directions = "RLRL";
    vector<int> r=s.survivedRobotsHealths(positions,healths,directions);
    if (r.empty()){
        cout<<"empty"<<endl;
        return 0;
    }
    for(int &x:r){
        cout<<x<<" ";
    }
    cout<<endl;
}
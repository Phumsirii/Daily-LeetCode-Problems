#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findParent(int input,string &formula){
        int balance=0;
        int n=formula.size();
        for(int i=input+1;i<n;++i){
            if (balance==0 && formula[i]==')') return i;
            if (formula[i]=='(')++balance;
            if (formula[i]==')')--balance;
        }
        return -1; //no parent
    }
    string getAtomName(int start,string &formula){
        string result;
        result+=formula[start];
        int it=start+1,n=formula.size();
        while(it<n && formula[it]>='a' && formula[it]<='z'){
            result+=formula[it];
            ++it;
        }
        return result;
    }
    int getLocalCoef(int start,string &formula){
        int it=start+1,n=formula.size();
        string tmp;
        while(it<n && formula[it]>='0' && formula[it]<='9'){
            tmp+=formula[it];
            ++it;
        }
        return tmp.empty() ? 1 : stoi(tmp);
    }
    string countOfAtoms(string formula) {
        map<string,int> result;
        map<int,int> parentcoef;
        int n=formula.size();
        //get coef. for each parenthesis
        for(int i=n-1;i>=0;--i){
            if (formula[i]!=')') continue;
            int localCoef=getLocalCoef(i,formula);
            int parentNumber=findParent(i,formula);
            if (parentNumber==-1) parentcoef[i]=localCoef;
            else parentcoef[i]=localCoef*parentcoef[parentNumber];
        }
        int it=0;
        while(it<n){
            //cout<<it<<" ";
            //if this is not the begining of an atom name
            if (!(formula[it]>='A' && formula[it]<='Z')){
                ++it;
                //cout<<endl;
                continue;
            }
            string currentAtom=getAtomName(it,formula);
            //cout<<currentAtom<<" ";
            int atomNameLength=currentAtom.size();
            int tmp=it+atomNameLength-1; //last char of atom name
            int localCoef=getLocalCoef(tmp,formula);
            //cout<<localCoef<<" ";
            int parentN=findParent(tmp,formula);
            if (parentN==-1) result[currentAtom]+=localCoef; //No parent
            else result[currentAtom]+=(localCoef*parentcoef[parentN]);
            it=tmp+1;//start from the first it which does not belongs to this atom's name
            //cout<<it<<endl;
        }
        string resultStr="";
        for(auto &x:result){
            resultStr+=x.first;
            if (x.second>1) resultStr+=to_string(x.second);
        }
        return resultStr;
    }
};
int main(){
    Solution s;
    cout<<s.countOfAtoms("K4(ON(SO3)2)2");
}
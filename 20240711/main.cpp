#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        string cur;
        stack<string> st;
        for(char &x:s){
            if (x=='('){
                st.push(cur);
                cur="";
            }else if(x==')'){
                reverse(cur.begin(),cur.end());
                cur=st.top()+cur;
                st.pop();
            }else{
                cur+=x;
            }
        }
        return cur;
    }
};
int main(){
    Solution s;
    cout<<s.reverseParentheses("(abcd)")<<endl;
    cout<<s.reverseParentheses("(u(love)i)")<<endl;
    cout<<s.reverseParentheses("(ed(et(oc))el)")<<endl;
}
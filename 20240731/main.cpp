#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> books,dp;
    int shelfWidth;
    int noOfBooks;
    Solution(){this->books={};this->dp={};}
    int recur(int it,int widthLeft,int currentLevelHeight){
        if (it>=noOfBooks) return currentLevelHeight;
        if (dp[it][widthLeft]!=-1) return dp[it][widthLeft];
        //needs to start a new level
        if (widthLeft<books[it][0]){
            return dp[it][widthLeft]=currentLevelHeight+recur(it+1,shelfWidth-books[it][0],books[it][1]);
        }
        int newHeight=max(books[it][1],currentLevelHeight);
        //start a new level or continue current level
        return dp[it][widthLeft]=min(currentLevelHeight+recur(it+1,shelfWidth-books[it][0],books[it][1]),recur(it+1,widthLeft-books[it][0],newHeight));
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int totalHeight=0;
        this->books=books;
        this->shelfWidth=shelfWidth;
        this->noOfBooks=books.size();
        this->dp=vector<vector<int>> (noOfBooks,vector<int> (shelfWidth+1,-1));
        return recur(0,shelfWidth,0);
    }
};
int main(){
    Solution s;
    vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    int shelfWidth = 4;
    cout<<s.minHeightShelves(books,shelfWidth);
}
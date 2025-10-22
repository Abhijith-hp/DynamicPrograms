class Solution {
  public:
    bool isPalindrome(int start,int end,string &s){
        while(start<end){
         if( s[start++]!=s[end--])
             return false;
        }
        return true;
    }
    int minCuts(int i,string &s,vector<int>&dp){
       
        int n = s.size();
        if(i==n) return 0;
         if(dp[i]!=-1) return dp[i];
       
        int mini = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
               int cost = 1 + minCuts(j+1,s,dp);
               mini = min(mini,cost);
            }
        }
        return dp[i]= mini;
    }
    int palPartition(string &s) {
       vector<int>dp(s.size(),-1);
       return minCuts(0,s,dp)-1;
        
    }
};
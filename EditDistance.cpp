class Solution {
public:
    int helper(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
           dp[i][j]=helper(i-1,j-1,s1,s2,dp);
        else
          dp[i][j]=min(min(1+helper(i,j-1,s1,s2,dp),1+helper(i-1,j,s1,s2,dp)),1+helper(i-1,j-1,s1,s2,dp));
        return dp[i][j];
         
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return helper(word1.size()-1,word2.size()-1,word1,word2,dp);
    }
};
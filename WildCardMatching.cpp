class Solution {
public:

    bool helper(int i,int j,string &p,string &s,vector<vector<int>>&dp){

      if(i<0 && j<0) return true;
      if(i<0 && j>=0) return false;
      if(i>=0 && j<0){
        for(int k=0;k<=i;k++){
            if(p[k]!='*'){
               return false;
               break;
            }
        } 
        return true;
      } 
      if(dp[i][j]!=-1) return dp[i][j];
      if(p[i]==s[j] || p[i]=='?')
        return dp[i][j]=helper(i-1,j-1,p,s,dp);
      if(p[i]=='*')
         return dp[i][j] =  (helper(i-1,j,p,s,dp) || helper(i,j-1,p,s,dp));
      return dp[i][j]=false;
        
    }
    bool isMatch(string s, string p) {
        int m =p.size();
        int n = s.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(p.size()-1,s.size()-1,p,s,dp);
    }
};
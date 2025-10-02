class Solution {
  public:
    int ans =0;
    int lengthOfSubStr(int i,int j,string& s1,string& s2,vector<vector<int>>&dp){
        int curr = 0;
        if(i<0 || j<0) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            dp[i][j] =   1+lengthOfSubStr(i-1,j-1,s1,s2,dp);
            ans =max(ans,dp[i][j]);
            
        }else
          dp[i][j]=0;
        lengthOfSubStr(i-1,j,s1,s2,dp);
        lengthOfSubStr(i,j-1,s1,s2,dp);
        return dp[i][j];
    
    }
    int longestCommonSubstr(string& s1, string& s2) {
        vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
        lengthOfSubStr(s1.size()-1,s2.size()-1,s1,s2,dp);
        return ans;
        
    }
};
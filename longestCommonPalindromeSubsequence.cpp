class Solution {
public:
    int helper(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
       if(i<0 || j<0) return 0;
       if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
           dp[i][j]=1+helper(i-1,j-1,s1,s2,dp);
        else
            dp[i][j]=max(helper(i-1,j,s1,s2,dp),helper(i,j-1,s1,s2,dp));
        return dp[i][j];

    }
    int longestPalindromeSubseq(string s) {
        int length = s.size();
        string s1 = s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(length,vector<int>(length,-1));
        return helper(length-1,length-1,s1,s,dp);
    }
};
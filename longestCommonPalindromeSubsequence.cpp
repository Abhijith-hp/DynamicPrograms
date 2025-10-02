class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int length = s.size();
        string s1 = s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(length+1,vector<int>(length+1,0));

        for(int i=1;i<=length;i++){
            for(int j=1;j<=length;j++){
                if(s1[i-1]==s[j-1])
                    dp[i][j] = 1+ dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[length][length];
        
    }
};
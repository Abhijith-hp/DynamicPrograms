class Solution {
public:

    bool isMatch(string s, string p) {
        int m =p.size();
        int n = s.size();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        for(int j=1;j<=n;j++) dp[0][j] = false;
        for(int i=1;i<=m;i++) {
            bool flag = true;
            for(int k=0;k<i;k++){
                if(p[k]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[i][0]=flag;
        }

            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if(p[i-1]==s[j-1] || p[i-1]=='?')
                       dp[i][j]=dp[i-1][j-1];
                    else if(p[i-1]=='*')
                        dp[i][j] =  dp[i-1][j] || dp[i][j-1];
                    else dp[i][j]=false; 
                }
            }
        
        return dp[m][n];
    }
};
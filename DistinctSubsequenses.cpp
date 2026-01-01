class Solution {
public:
    
    int distinctSubseqII(string s) {

        int n =s.size();
        int MOD = 1e9 + 7;
        vector<int>last(26,-1);
        vector<int>dp(n,0);
        dp[0] = 2;
        last[s[0]-'a'] = 0;

        for(int i=1;i<n;i++){
            int j = last[s[i]-'a'];
            dp[i] = (2 * dp[i-1]) % MOD;
            if(j!=-1){
                if(j==0)
                    dp[i] = (dp[i]-1 + MOD) % MOD;
                else dp[i] = (dp[i] - dp[j-1] + MOD) % MOD;
                
            }
            last[s[i] - 'a'] = i;
        }
       return (dp[n - 1] - 1 + MOD) % MOD;
    }
};
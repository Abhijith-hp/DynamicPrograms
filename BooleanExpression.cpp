class Solution {
public:
    int countWays(string &s) {
        int n = s.size();
     
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                for (int isTrue = 0; isTrue <= 1; isTrue++) {

                    if (i == j) {
                        if (isTrue) dp[i][j][isTrue] = (s[i] == 'T') ? 1 : 0;
                        else dp[i][j][isTrue] = (s[i] == 'F') ? 1 : 0;
                        continue;
                    }

                    long long ways = 0;
                    for (int ind = i + 1; ind <= j - 1; ind += 2) {
                        long long lT = dp[i][ind - 1][1];
                        long long lF = dp[i][ind - 1][0];
                        long long rT = dp[ind + 1][j][1];
                        long long rF = dp[ind + 1][j][0];

                        char op = s[ind];

                        if (op == '&') {
                            if (isTrue)
                                ways += lT * rT;
                            else
                                ways += lF * rT + lT * rF + lF * rF;
                        } 
                        else if (op == '|') {
                            if (isTrue)
                                ways += lT * rT + lT * rF + lF * rT;
                            else
                                ways += lF * rF;
                        } 
                        else { 
                            if (isTrue)
                                ways += lT * rF + lF * rT;
                            else
                                ways += lT * rT + lF * rF;
                        }
                    }

                    dp[i][j][isTrue] = ways;
                }
            }
        }
        return static_cast<int>(dp[0][n - 1][1]);
    }
};

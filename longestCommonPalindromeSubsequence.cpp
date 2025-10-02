class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int length = s.size();
        string s1 = s;
        reverse(s.begin(),s.end());
        vector<int>prev(length+1,0);
        vector<int>curr(length+1,0);

        for(int i=1;i<=length;i++){
            for(int j=1;j<=length;j++){
                if(s1[i-1]==s[j-1])
                    curr[j] = 1+ prev[j-1];
                else
                    curr[j] = max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[length];
        
    }
};
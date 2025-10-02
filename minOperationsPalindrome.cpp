class Solution {
public:
    bool isPalindrome(string&s){
        int left = 0;
        int right = s.size()-1;

        while(left<=right){
            if(s[left]!=s[right])
                  return false;
            left++;
            right--;
            
        }
        return true;
        
    }
    int minInsertions(string s) {
        if(isPalindrome(s))
              return 0;
        int size = s.size();
        string s1= s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(size+1,vector<int>(size+1,0));
        for(int i=1;i<=size;i++){
            for(int j=1;j<=size;j++){
                if(s1[i-1]==s[j-1])
                    dp[i][j]= 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

            }
        }
        return size - dp[size][size];
        

    }
};
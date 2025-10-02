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
    int lengthofCommonPalindromeSubsequence(int i,int j,string s1,string s2,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
            dp[i][j]= 1+ lengthofCommonPalindromeSubsequence(i-1,j-1,s1,s2,dp);
        else
            dp[i][j]= max(lengthofCommonPalindromeSubsequence(i-1,j,s1,s2,dp),lengthofCommonPalindromeSubsequence(i,j-1,s1,s2,dp));
        return dp[i][j];
    }
    int minInsertions(string s) {
        if(isPalindrome(s))
              return 0;
        int size = s.size();
        string s1= s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(size,vector<int>(size,-1));
        return size - lengthofCommonPalindromeSubsequence(size-1,size-1,s1,s,dp);
        

    }
};
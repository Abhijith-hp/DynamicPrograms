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
    int lengthofCommonPalindromeSubsequence(int i,int j,string s1,string s2){
        if(i<0 || j<0) return 0;

        if(s1[i]==s2[j])
             return 1+ lengthofCommonPalindromeSubsequence(i-1,j-1,s1,s2);
        return max(lengthofCommonPalindromeSubsequence(i-1,j,s1,s2),lengthofCommonPalindromeSubsequence(i,j-1,s1,s2));
    }
    int minInsertions(string s) {
        if(isPalindrome(s))
              return 0;
        int size = s.size();
        string s1= s;
        reverse(s.begin(),s.end());
        return size - lengthofCommonPalindromeSubsequence(size-1,size-1,s1,s);
        

    }
};
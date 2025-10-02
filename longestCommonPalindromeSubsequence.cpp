class Solution {
public:
    int helper(int i,int j,string &s1,string &s2){
       if(i<0 || j<0) return 0;

        if(s1[i]==s2[j])
           return 1+helper(i-1,j-1,s1,s2);
        return max(helper(i-1,j,s1,s2),helper(i,j-1,s1,s2));

    }
    int longestPalindromeSubseq(string s) {
        int length = s.size();
        string s1 = s;
        reverse(s.begin(),s.end());
        return helper(length-1,length-1,s1,s);
    }
};
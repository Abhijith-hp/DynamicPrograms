class Solution {
  public:
    int ans =0;
    int lengthOfSubStr(int i,int j,string& s1,string& s2){
        int curr = 0;
        if(i<0 || j<0) return 0;
        if(s1[i]==s2[j]){
            curr =  1+lengthOfSubStr(i-1,j-1,s1,s2);
            ans =max(ans,curr);
            
        }
        lengthOfSubStr(i-1,j,s1,s2);
        lengthOfSubStr(i,j-1,s1,s2);
        return curr;
    
    }
    int longestCommonSubstr(string& s1, string& s2) {
        lengthOfSubStr(s1.size()-1,s2.size()-1,s1,s2);
        return ans;
        
    }
};
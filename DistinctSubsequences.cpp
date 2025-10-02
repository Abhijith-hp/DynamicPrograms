class Solution {
public:
    int helper(int i,int j,string &s,string &t){

        if(j<0) return 1;
        if(i<0) return 0;
        
        if(s[i]==t[j])
          return helper(i-1,j-1,s,t)+helper(i-1,j,s,t);
        return helper(i-1,j,s,t);
        
    }
    int numDistinct(string s, string t) {
        return helper(s.size()-1,t.size()-1,s,t);
    }
};
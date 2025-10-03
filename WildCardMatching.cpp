class Solution {
public:

    bool helper(int i,int j,string &p,string &s){

      if(i<0 && j<0) return true;
      if(i<0 && j>=0) return false;
      if(i>=0 && j<0){
        for(int k=0;k<=i;k++){
            if(p[k]!='*'){
               return false;
               break;
            }
        } 
        return true;
      } 
      if(p[i]==s[j] || p[i]=='?')
        return helper(i-1,j-1,p,s);
      if(p[i]=='*')
         return (helper(i-1,j,p,s) || helper(i,j-1,p,s));
      return false;
        
    }
    bool isMatch(string s, string p) {
        int m =p.size();
        int n = s.size();
        return helper(p.size()-1,s.size()-1,p,s);
    }
};
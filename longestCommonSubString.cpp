class Solution {
  public:
    
    int longestCommonSubstr(string& s1, string& s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        
        //lengthOfSubStr(s1.size()-1,s2.size()-1,s1,s2,dp);
        vector<int>prev(s2.size()+1,0);
        vector<int>curr(s2.size()+1,0);
        int ans = 0;
        for(int i =1;i<=s1.size();i++ ){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 1+prev[j-1];
                    ans = max(ans,curr[j]);
                    
                }else
                   curr[j]=0;
                
            }
            prev=curr;
        }
        return ans;
        
    }
};
class Solution {
  public:
    bool isPalindrome(int start,int end,string &s){
        while(start<end){
         if( s[start++]!=s[end--])
             return false;
        }
        return true;
    }
    int minCuts(int i,string &s){
        int n = s.size();
        if(i==n) return 0;
        int mini = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
               int cost = 1 + minCuts(j+1,s);
               mini = min(mini,cost);
            }
        }
        return mini;
    }
    int palPartition(string &s) {
       return minCuts(0,s)-1;
        
    }
};
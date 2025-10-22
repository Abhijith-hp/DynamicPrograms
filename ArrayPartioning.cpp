class Solution {
  public:
 
    int solve(int n, int k, vector<int>& arr) {
        vector<int>dp(n+1,0);
        for(int index=n-1;index>=0;index--){
           int len = 0; 
           int maxi = INT_MIN, maxOfSum = INT_MIN;
           for(int i=index;i<min(index+k,n);i++){
           len++;
           maxi = max(maxi,arr[i]);
           int sum= maxi*len + dp[i+1];
           maxOfSum = max(sum,maxOfSum);
           
        }
        dp[index]=maxOfSum;
        }
        return dp[0];
        
    }
};
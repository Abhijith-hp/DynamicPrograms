class Solution {
  public:
    int helper(int index,int k,vector<int>&arr,vector<int>&dp){
        int n = arr.size();
        if(index==n) return 0;
        int len = 0; 
        int maxi = INT_MIN, maxOfSum = INT_MIN;
        if(dp[index]!=-1) return dp[index];
        for(int i=index;i<min(index+k,n);i++){
           len++;
           maxi = max(maxi,arr[i]);
           int sum= maxi*len + helper(i+1,k,arr,dp);
           maxOfSum = max(sum,maxOfSum);
           
        }
        return dp[index] =  maxOfSum;
    }
    int solve(int n, int k, vector<int>& arr) {
        vector<int>dp(n,-1);
        return helper(0,k,arr,dp);
        
    }
}
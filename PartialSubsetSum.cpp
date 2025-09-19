class Solution {
  public:
    
    bool partition(int k,vector<int>&arr){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        
        for(int i=0;i<n;i++)
            dp[i][0]=true;
        if(arr[0] <= k )
            dp[0][arr[0]]=true;
            
        for(int index = 1;index<n;index++){
            for(int target =1;target<=k;target++){
                bool nonTake = dp[index-1][target];
                bool take = false;
                if(arr[index]<=target)
                    take = dp[index-1][target-arr[index]];
                    
                dp[index][target] = take || nonTake;
            }
           
        }
         return dp[n-1][k];
    }
      
    
    bool equalPartition(vector<int>& arr) {
       
       int sum = 0;
       for(int i=0;i<=arr.size()-1;i++)
            sum+=arr[i];
            
        if(sum%2!=0) return false;
        return partition(sum/2,arr);
        
    }
};
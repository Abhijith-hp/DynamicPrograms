class Solution {
  public:
    int helper(int index,int k,vector<int>&arr){
        int n = arr.size();
        if(index==n) return 0;
        int len = 0; 
        int maxi = INT_MIN, maxOfSum = INT_MIN;
        
        for(int i=index;i<min(index+k,n);i++){
           len++;
           maxi = max(maxi,arr[i]);
           int sum= maxi*len + helper(i+1,k,arr);
           maxOfSum = max(sum,maxOfSum);
           
        }
        return maxOfSum;
    }
    int solve(int n, int k, vector<int>& arr) {
        return helper(0,k,arr);
        
    }
};
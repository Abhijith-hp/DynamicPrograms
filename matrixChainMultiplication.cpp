class Solution {
  public:
    int helper(int i,int j,vector<int>&arr){
        if(i==j) return 0;
        int mini = INT_MAX;
        
        for(int k=i;k<j;k++){
            int steps = (arr[i-1] * arr[k] * arr[j]) + helper(i,k,arr)+helper(k+1,j,arr);
            mini  = min(steps,mini);
        }
       
        return mini;
        
        
    }
    int matrixMultiplication(vector<int> &arr) {
      
      return helper(1,arr.size()-1,arr);
        
    }
};
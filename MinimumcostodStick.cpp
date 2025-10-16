class Solution {
public:
    int helper(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j) return 0;
        int ans = INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int index = i;index <=j ;index++){
            int cost =  cuts[j+1] - cuts[i-1] + helper(i,index-1,cuts,dp)+helper(index+1,j,cuts,dp);
            ans = min(cost,ans);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        std::sort(cuts.begin(),cuts.end());
        int c = cuts.size();
        vector<vector<int>> dp(c-1, vector<int>(c-1, -1)); 
        return helper(1,c-2,cuts,dp);
    }
};
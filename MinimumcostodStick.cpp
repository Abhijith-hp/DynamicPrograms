class Solution {
public:
    int helper(int i,int j,vector<int>&cuts){
        if(i>j) return 0;
        int ans = INT_MAX;
        for(int index = i;index <=j ;index++){
            int cost =  cuts[j+1] - cuts[i-1] + helper(i,index-1,cuts)+helper(index+1,j,cuts);
            ans = min(cost,ans);
        }
        return ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        std::sort(cuts.begin(),cuts.end());
        return helper(1,cuts.size()-2,cuts);
    }
};
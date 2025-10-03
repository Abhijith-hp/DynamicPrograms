class Solution {
public:

    bool isMatch(string s, string p) {
        int m =p.size();
        int n = s.size();
        vector<bool>prev(n+1,false);
        vector<bool>curr(n+1,false);
        prev[0] = true;
        for(int j=1;j<=n;j++) prev[j] = false;
            for(int i=1;i<=m;i++){
                bool flag = true;
                for(int k=0;k<i;k++){
                    if(p[k]!='*'){
                        flag=false;
                        break;
                    }
                }
            curr[0]=flag;
             for(int j=1;j<=n;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='?')
                    curr[j]=prev[j-1];
                else if(p[i-1]=='*')
                    curr[j] =  prev[j] || curr[j-1];
                else curr[j]=false; 
                }
            prev = curr;
            }
        
        return prev[n];
    }
};
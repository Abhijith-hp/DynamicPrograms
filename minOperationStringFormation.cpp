class Solution {

  public:
    
    int minOperations(string &s1, string &s2) {
        int size1 = s1.length();
        int size2 = s2.length(); 
        
        vector<int>prev(size2+1,0),curr(size2+1,0);
        for(int i=1;i<=size1;i++){
            for(int j=1;j<=size2;j++){
                if(s1[i-1]==s2[j-1])
                    curr[j]= 1+prev[j-1];
                else
                    curr[j] = max(prev[j],curr[j-1]);

            }
            prev=curr;
        }
        return size1+size2 - (2* prev[size2]);
    }
};
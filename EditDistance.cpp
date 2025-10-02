class Solution {
public:
    int helper(int i,int j,string &s1,string &s2){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(s1[i]==s2[j])
           return helper(i-1,j-1,s1,s2);
        return min(min(1+helper(i,j-1,s1,s2),1+helper(i-1,j,s1,s2)),1+helper(i-1,j-1,s1,s2));
    }
    int minDistance(string word1, string word2) {
        return helper(word1.size()-1,word2.size()-1,word1,word2);
    }
};
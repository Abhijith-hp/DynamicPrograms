class Solution {
public:
    bool isPalindrome(string&s){
        int left = 0;
        int right = s.size()-1;

        while(left<=right){
            if(s[left]!=s[right])
                  return false;
            left++;
            right--;
            
        }
        return true;
        
    }
    int minInsertions(string s) {
        if(isPalindrome(s))
              return 0;
        int size = s.size();
        string s1= s;
        reverse(s.begin(),s.end());
        vector<int>prev(size+1,0),curr(size+1,0);
        for(int i=1;i<=size;i++){
            for(int j=1;j<=size;j++){
                if(s1[i-1]==s[j-1])
                    curr[j]= 1+prev[j-1];
                else
                    curr[j] = max(prev[j],curr[j-1]);

            }
            prev=curr;
        }
        return size - prev[size];
        

    }
};
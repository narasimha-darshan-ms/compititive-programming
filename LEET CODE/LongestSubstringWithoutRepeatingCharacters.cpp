class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)     return 0;
        if(s.length() == 1)     return 1;
        unordered_map<char,int> alpha; int count = 0;
        
        int i = 0, j = 0, n = s.length();
        
        while(i < n && j < n){
            while(j < n && !alpha[s[j] - 'a'] ){  alpha[s[j] - 'a']++; j++;  }
            count = max(count, j - i);
            while(j < n && alpha[s[j] - 'a'] && i != j && i < n ) {alpha[s[i] - 'a']--; i++;} 
            }        
        
        return count;
    }
};

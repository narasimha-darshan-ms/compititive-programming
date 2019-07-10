class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() , INT_MAX);
        dp[0] = 0;
        int j = 0;
        
        for(int i = 1 ; i < nums.size() ; i++){
            for(j = 0 ; j < i ; j++){
                if(nums[j] + j >= i)
                    dp[i] = min(dp[i] , dp[j] + 1);
            }
        }
        
        return dp[nums.size() - 1];
    }
};

// O(n*n)  solution
//can be further optimised to O(n)

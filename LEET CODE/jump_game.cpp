class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachableIndex = 0;
        
        if(nums.size() == 1)    return true;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(reachableIndex >= nums.size() - 1)   return true;
            if(i + nums[i] > reachableIndex)
                reachableIndex = nums[i] + i;
            else if(i == reachableIndex && nums[i] + i == reachableIndex)  return false;
        }
        return true;
    }
};

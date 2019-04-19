/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN, i = 0, count = 0;
        bool negative = true;
        while(i < n){    
                if(nums[i] >= 0)  negative = false;    
                count += nums[i];
                if(count < 0)   count = 0;
                max = std::max(max,count);
                i++;                      
        }
        
        if (!negative)   return max;
        return *max_element( nums.begin() , nums.end() );
    }
};

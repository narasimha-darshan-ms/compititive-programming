/*
LEETCODE : Min Cost Climbing stairs.

On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach 
the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

Note:
    cost will have a length in the range [2, 1000].
    Every cost[i] will be an integer in the range [0, 999]
*/

#include <bits/stdc++.h> 
#include<string>

using namespace std;

int main(){
    int n, temp;
    vector<int> cost;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cin>>temp;
        cost.push_back(temp);
    }
    
    int minCost[n];
    minCost[0] = minCost[1] = 0;
    
    for(int i = 2 ; i < n ; i++){
        minCost[i] = std::min(cost[i-1] + minCost[i-1] , cost[i-2] + minCost[i-2]); 
    }
    cout<<std::min(minCost[n-1] + cost[n-1], minCost[n-2] + cost[n-2]);
    cout<<endl;
    
    return 0;
}

/*
SOLUTION FOR LEETCODE PLATFORM :
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int minCost[cost.size()];
        minCost[0] = minCost[1] = 0;
        int n = cost.size();
        for(int i = 2 ; i < cost.size() ; i++){
            minCost[i] = std::min(cost[i-1] + minCost[i-1] , cost[i-2] + minCost[i-2]); 
        }
        return std::min(minCost[n-1] + cost[n-1], minCost[n-2] + cost[n-2]);
    }
};
*/

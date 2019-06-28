/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check = false;
    bool hasPathSum(TreeNode* root, int sum) {
        if(!check){
            if(find(root,sum))  return 0;
            check = 1;
        }  
        if(!root){
            if(sum == 0)    return 1;
            return 0;
        }
        if(sum - root->val < 0) return 0;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
    bool find(TreeNode* root, int sum){
        if(!sum || !root)   return 1;
        return 0;
    }
};

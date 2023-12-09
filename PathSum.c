/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* Note that the tree could be negative. */
/* 本來想要判斷大小加速的但是超麻煩*/
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root == NULL) return false;
    targetSum -= root->val;
    if(targetSum == 0 && root->left == NULL &&\
            root->right == NULL) return true;    
    if(root->left != NULL){
        if (hasPathSum(root->left, targetSum)) return true;
    }
    if(root->right != NULL){
        if (hasPathSum(root->right, targetSum)) return true;
    }
    return false;  
}
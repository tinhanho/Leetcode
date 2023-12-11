/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL) return true;
    else if (p == NULL || q == NULL) return false;
    else{
        if(p->val == q->val) if(isSameTree(p->left, q->left))\
        if(isSameTree(p->right, q->right)) return true;
    }
    return false;
}
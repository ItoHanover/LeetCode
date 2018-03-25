//226. Invert Binary Tree
//将二叉树所有节点反转
//原先为左子节点的则反转为右子节点
//原先为右子节点的则反转为左子节点
//很容易

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
    TreeNode* invertTree(TreeNode* root) {
     if(root == NULL)
         return root;
        
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
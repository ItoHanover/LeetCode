//404. Sum of Left Leaves
//求一棵二叉树所有左叶节点的值的和
//在递归遍历结构上改进即可

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
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        visit(root);
        return sum;
    }
    
    void visit(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->left != NULL && (root->left->left == NULL && root->left->right == NULL))
            sum = sum + root->left->val;
        visit(root->left);
        visit(root->right);

    }
    int sum;
};
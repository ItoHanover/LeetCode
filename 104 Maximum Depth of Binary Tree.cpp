//104. Maximum Depth of Binary Tree
//寻找二叉树最大深度
//很简单 迭代时多代入参数比对即可

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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int maxDepth = 1;
        visitNode(root,1,maxDepth);
        return maxDepth;
    }
    
    void visitNode(TreeNode* rNode,int iDepth,int& maxDepth)
    {
        if(rNode == NULL)
            return;
        
        visitNode(rNode->left,iDepth+1,maxDepth);
        visitNode(rNode->right,iDepth+1,maxDepth);
        
        if(iDepth>maxDepth)
            maxDepth = iDepth;
    }
};
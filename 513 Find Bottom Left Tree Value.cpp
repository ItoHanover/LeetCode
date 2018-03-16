//513. Find Bottom Left Tree Value
//给定一棵二叉树
//要求返回该棵二叉树最底一层中最左端的节点
//迭代方式解决

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
    int findBottomLeftValue(TreeNode* root) {
        int leftValue = 0;
        visitNode(root,1,leftValue);
        
        return leftValue;
    }
    
    void visitNode(TreeNode* rNode,int iHight,int& leftValue)
    {
        if(rNode == NULL)
            return;
        
        if(rNode->left == NULL && rNode->right == NULL && iHight>maxHight)
        {
            leftValue = rNode->val;
        }
        
        visitNode(rNode->left,iHight+1,leftValue);  
        visitNode(rNode->right,iHight+1,leftValue);
        
        if(iHight > maxHight)
        {
            maxHight = iHight;
        }

    }
private:
    int maxHight = 0;
};
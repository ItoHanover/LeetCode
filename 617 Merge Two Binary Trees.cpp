//617. Merge Two Binary Trees
//给定两棵二叉树，将其对应结点合并
//相同位置的结点值相加
//如果树某位置不存在结点，而另一棵树存在，则将结点移植过来

//本题可以通过改造树的前序遍历的递归形式来完成

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1)
            return t2;
        if(!t2)
            return t1;

        TreeNode* t3 = new TreeNode(t1->val+t2->val);
        t3->left = mergeTrees(t1->left,t2->left);
        t3->right = mergeTrees(t1->right,t2->right);
        
        return t3;
        }
};
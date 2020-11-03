/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class RangeSum
{
public:
    RangeSum(int i,int j)
    {
        this->L = i;
        this->R = j;
        this->sum = 0;
    }
    
    int L;
    int R;
    int sum;
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        
        RangeSum res = RangeSum(L,R);
        visit(root,res);
        
        return res.sum;
    }
    
    void visit(TreeNode* cur,RangeSum& res)
    {
        if(cur!= nullptr)
        {
            if(cur->val <= res.R && cur->val >= res.L)
            {
                res.sum = res.sum + cur->val;
            }
            
            visit(cur->left,res);
            visit(cur->right,res);
        }
    }
};
//654. Maximum Binary Tree
//要求使用给定数组生成一棵二叉树
//根节点为数组中最大元素 而这个最大元素将二维数组划分为两部分
//左子树根节点左半部分的最大元素 右子树节点为右半部分的最大元素
//迭代求解 考虑三种边界情况

class Solution {
public:
	
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		TreeNode* MainRoot = NULL;
		vector<int>::iterator MaxIter = max_element(nums.begin(), nums.end());
		MainRoot = GetSubNode(nums.begin(), nums.end()-1, MaxIter, MainRoot);

		return MainRoot;

	}

	TreeNode* GetSubNode(vector<int>::iterator LIter, vector<int>::iterator RIter, vector<int>::iterator MaxIter, TreeNode* RootPtr)
	{	
		//数组仅有一个元素
		if (LIter == RIter)
		{ 
			RootPtr = new TreeNode(*LIter);
			return RootPtr;
		}

		//数组最左端元素为最大元素 左子树不存在
		if (LIter == MaxIter)
		{

			RootPtr = new TreeNode(*LIter);
			vector<int>::iterator RMaxIter = max_element(LIter + 1, RIter + 1);
			RootPtr->right = GetSubNode(LIter + 1, RIter, RMaxIter, RootPtr->right);
			return RootPtr;
		}

		//数组最右端元素为最大元素 右子树不存在
		if (RIter == MaxIter)
		{

			RootPtr = new TreeNode(*RIter);
			vector<int>::iterator LMaxIter = max_element(LIter, RIter);
			RootPtr->left = GetSubNode(LIter, RIter - 1, LMaxIter, RootPtr->left);
			return RootPtr;
		}


		vector<int>::iterator LMaxIter = max_element(LIter, MaxIter);
		vector<int>::iterator RMaxIter = max_element(MaxIter+1, RIter + 1);

		RootPtr = new TreeNode(*MaxIter);

		RootPtr->left = GetSubNode(LIter, MaxIter-1, LMaxIter, RootPtr->left);
		RootPtr->right = GetSubNode(MaxIter+1, RIter, RMaxIter, RootPtr->right);

		return RootPtr;
	}

};
//413. Arithmetic Slices
//给定一个数组 要求判断其中有多少个等差数列
//单个等差数列内元素数量不能少于3

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size()<3) 
			return 0;
		int count = 0;
		int sub = 0;
		for (vector<int>::iterator iter = A.begin(); iter != A.end()-1; iter++)
		{
			vector<int>::iterator endIter = iter + 1;
			sub = *endIter - *iter;
			for (; endIter != A.end()-1; endIter++)
			{
				if (*(endIter + 1) - *endIter != sub)
					break;
				else
					count = count + 1;
			}

		}
		return count;
	}
};
//283. Move Zeroes
//要求将一个数组内的0全部移到末尾
//注意std::vector.erase(x)的用法;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() == 0)
			return;
		int i = 0;
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end();)
		{
			if (*iter == 0)
			{
				iter = nums.erase(iter);
				i = i + 1;
			}
			else
			{
				iter++;
			}

			if (iter == nums.end())
				break;
			
		}

		for (int flag = 0; flag<i; flag++)
		{
			nums.push_back(0);
		}
	}
};
//1. Two Sum
//给定一个数组 在其中寻找两个元素相加得到target
//要求两个元素不能相同

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int x = 0 ; x<nums.size();x++)
        {
            for(int y = 0; y<nums.size();y++)
            {
                if(x != y &&nums[x] + nums[y] == target)
                {
                    res.push_back(x);
                    res.push_back(y);
                    return res;
                }
            }
        }
        return res;
    }
};
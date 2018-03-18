//136. Single Number
//给定一个数组 其中的元素都为成对出现 但是有一个单个出现的元素
//寻找这个元素 要求不使用额外空间 线性复杂度

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i=i+2)
        {
            if(nums[i]!=nums[i+1])
                return nums[i];
        }
        return nums[nums.size()-1];
    }
};
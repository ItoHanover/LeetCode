//268. Missing Number
//在一个连续数列当中 缺少了一个数字
//要求寻找出这个数字
//桶排序

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> res(nums.size()+1);
        for(int i = 0;i<res.size();i++)
        {
            res[i] = -1;
        }
        
        for(int i = 0;i<nums.size();i++)
        {
            res[nums[i]] = nums[i];
        }
        
        for(int i = 0;i<res.size();i++)
        {
            if(res[i]==-1)
                return i;
        }
        return 0;
        
}
    
};
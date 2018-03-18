//442. Find All Duplicates in an Array
//要求找出一个数组内所有出现两次的数字
//数组内的数字大小均小于数组大小
//要求O(n)内解决 且不使用额外的空间

//利用排序 但耗时超过O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        
        if(nums.size()==0)
            return res;
        
        for(int i = 0;i<nums.size()-1;i++)
        { 
            if(nums[i]==nums[i+1])
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};

//归位法 利用数组大小大于数字大小
//另所有数字归位 不在位上的数字就是重复数字

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> endRes;
        
        for(int i = 0; i<nums.size();i++)
        {
            if(res[nums[i]-1]!=nums[i])
                res[nums[i]-1] = nums[i];
            else
                endRes.push_back(nums[i]);
            
        }

        return endRes;
    }
};
//561. Array Partition I
//给出一个含有2n个数的数组
//将数组内的元素2个2个搭配，取所有搭配里最小的元素求和，要求这个和为最大值。
//返回这个最大值

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        
        for(int i = 0;i<nums.size();i=i+2)
        {
            sum = sum + getmin(nums[i],nums[i+1]);
        }
        return sum;
	}

    
    int getmin(int x,int y)
    {
        if(x<y)
            return x;
        else if(x>y)
            return y;
        else if(x==y)
            return x;
    }
    
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> resV;
        if(nums.size()==0)
            return resV;
        
        sort(nums.begin(),nums.end());
        
        for(int target = 0;target<nums.size();target++)
        {
            int left = target + 1;
            int right = nums.size() - 1;
            
            if(target != 0 && nums[target] == nums[target - 1])
                continue;
        
            while(left < right)
            {
                if(nums[target] + nums[left] + nums[right] == 0)
                {
                    resV.push_back({nums[target],nums[left],nums[right]});
                    left++;
                    right--;
                    
                    while(left < right && nums[left] == nums[left - 1])
                        left++;
                    
                    while(left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (nums[target] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        
        return resV;
    }
};
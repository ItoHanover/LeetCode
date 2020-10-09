class Solution {
    public int removeElement(int[] nums, int val) {
        int n = 0;
        int j = 0;
        for(int i = 0 ; i < nums.length;i++)
        {
            if(nums[j] == val)
            {
                int temp = nums[nums.length - n - 1];
                nums[nums.length - n - 1] = nums[j];
                nums[j] = temp;
                
                n = n + 1;
                j--;
            }
            j++;
        }
        
        return nums.length - n;
    }
}
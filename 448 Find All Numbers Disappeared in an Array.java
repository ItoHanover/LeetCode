//JAVA
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int[] tempNum = new int[nums.length];
        List<Integer> tarList = new ArrayList<Integer>();
        for(int i = 0;i<nums.length;i++)
        {
            tempNum[i] = 0;
        }
        
        for(int i = 0;i<nums.length;i++)
        {
            tempNum[nums[i] - 1] = 1;
        }
        
        for(int i =0;i<nums.length;i++)
        {
            if(tempNum[i] == 0)
            {
                tarList.add(i + 1);
            }
        }
        return tarList;
    }
}
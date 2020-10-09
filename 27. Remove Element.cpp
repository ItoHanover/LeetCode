class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        
        int n = 0;
        auto j = nums.begin();
        for(auto i = nums.begin(); i!=nums.end() ;i++)
        {
            if(*i != val)
            {
                *j = *i;
                
                j++;
                n++;
            }

        
        }
        return n;
    }
};
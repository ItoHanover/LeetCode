class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int maxWaterSize = 0;
        for(int leftS = 0;leftS < height.size()-1; leftS++)
        {
            for(int rightS = leftS + 1;rightS < height.size();rightS++)
            {
                int iWaterSize = min(height[leftS],height[rightS]) * (rightS - leftS);
                if(iWaterSize > maxWaterSize)
                    maxWaterSize =iWaterSize;
            }
        }
        
        return maxWaterSize;
    }
};
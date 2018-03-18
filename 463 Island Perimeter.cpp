//463. Island Perimeter
//要求计算岛屿周长
//先统计陆地的数量 每块陆地应有4条边
//陆地与陆地接邻 则会减少2条边

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int count=0, repeat=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0; j<grid[i].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        count ++;
                        if(i!=0 && grid[i-1][j] == 1) repeat++;
                        if(j!=0 && grid[i][j-1] == 1) repeat++;
                    }
                }
        }
        res = 4*count-2*repeat;
        return res;

    }
};
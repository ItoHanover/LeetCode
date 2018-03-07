//419. Battleships in a Board
//给定一个NxN的二维数组 包含'X'和'.'两种字符
//横向或纵向连贯的一组'X'可以被看作"战舰"
//数出所有"战舰"数量
//不存在相邻的战舰

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int res = 0;
        
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[i].size();j++)
            {
			//遍历所有的元素，左方和上方没有'X'的，值为'X'的元素，便是要找的"战舰"
                if( board[i][j]=='X' && ((i==0 || board[i-1][j]!='X') && (j==0 || board[i][j-1]!='X')))
                {
                    res =res + 1;
                }
            }
        }
        return res ;
    }
};
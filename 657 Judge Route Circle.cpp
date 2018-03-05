//657. Judge Route Circle
//题目不清晰
//判断一系类包含LRUD四类动作的动作集完成之后，目标是否回到原点

class Solution {
public:
	bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        
        for (int j = 0; j<moves.length(); j++)
		{
        	if (moves[j] == 'L')
			{
				x = x - 1;
			}
			else if (moves[j] == 'R')
			{
				x = x + 1;
			}
			else if (moves[j] == 'U')
			{
				y = y + 1;
			}
			else if (moves[j] == 'D')
			{
				y = y - 1;
			}
        }
        
        if(x == 0 && y == 0)
            return true;
        else
            return false;
	}

};
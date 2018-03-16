//766. Toeplitz Matrix
//给定一个矩阵 判断是否是Toeplitz
//即矩阵中每条自左上至右下的斜线上的元素是否相同


class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		vector<int>::iterator iter_row_up;
		for (vector<vector<int>>::iterator iter_col = matrix.begin(); iter_col != matrix.end() - 1; iter_col++)
		{
			iter_row_up = iter_col->begin();
			
			for (vector<int>::iterator iter_row_down = ((iter_col + 1)->begin()) + 1;
				iter_row_down != (iter_col + 1)->end();
				iter_row_down++)
			{
				if (*iter_row_down != *iter_row_up)
					return false;
				iter_row_up++;
			}
		return true;
		}
			
	}
};
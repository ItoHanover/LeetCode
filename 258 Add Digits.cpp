//258. Add Digits
//这题太辣鸡了。。
//给出一个int 要求将其各位相加 如果结果位数多于一 则再相加
//直到只剩一位为止 返回这个数
//
//	1	2	3	4	5	6	7	8	9	10	11	12	13	
//	1	2	3	4	5	6	7	8	9	1	2	3	4
//找规律可得 结果=(1+num-1)%9


class Solution {
public:
    int addDigits(int num) {
        return 1 + (num-1)%9; 
    }
};
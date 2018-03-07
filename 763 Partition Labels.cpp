//763. Partition Labels
//给出一个全部由小写字母组成的字符串
//将该字符串尽可能多的分割为子串
//要求每个字母仅同时出现在同一个子串当中，

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> LabelsEnd(26);
        vector<int> res;
        for(int i = 0;i<S.length();i++)
        {
            LabelsEnd[S[i] - 'a'] = i;
        }
		//将每个字符出现的最后位置放入数组
		//由题意可知，每个分割出的字符串尾部字符必定是某字符最后出现位置
        
        int sFront = -1;//每个字符串的头部标记，第一个字符串从第一个元素开始，因此头部标记为-1
        int sRear = 0;//每个字符串的尾部标记，从0开始
        
        for(int i = 0;i<S.length();i++)
        {
			//判断i位置的字符在字符串中出现的最后位置是否大于当前字符串的尾部
			//如果大于，即当前字符串尾部并非，则字符串尾部移动到i位置的字符在字符串中出现的最后位置
			//如果不大于，则字符串尾部无需变化
            if(LabelsEnd[S[i] - 'a'] > sRear)
                sRear = LabelsEnd[S[i] - 'a'];
            else
                sRear = sRear;
            
            if(sRear == i)	//当当前字符串的尾部与i相等时，表明当前字符串的尾部的字符位于最后出现位置，可以切割
            {
                res.push_back(sRear - sFront);	//将结果放入结果数组
                sFront = sRear;	//将头部标记置于下一个字符串的开始处的前一位，也就是当前字符串的尾部
            }
        }
        return res;
        
    }
};
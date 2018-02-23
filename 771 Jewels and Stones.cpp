//771 Jewels and Stones
//要求在字符串中S内匹配所有字符串J中的字符
//暴力方法解决


class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        int JLen = J.length();
        int SLen = S.length();
        
        int JewNum = 0;
        
        for(int i = 0;i<SLen;i++)
        {
            for(int j = 0;j<JLen;j++)
            {
                if(J[j]==S[i])
                {
                    JewNum = JewNum + 1;
                }
                
            }
            
        }
        
        return JewNum;
    }
};
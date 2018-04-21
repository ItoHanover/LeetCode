//389. Find the Difference
//给出字符串A与B，其中B是由A添加一个字母后乱序排成
//要求判断多出的字母是什么
//简单统计字母出现次数即可

class Solution {
public:
    char findTheDifference(string s, string t) {
        char tarS[26];
        char tarT[26];
        for(int i = 0;i<26;i++)
		{
		    tarS[i] = 0;
            tarT[i] = 0;
		}

        
        for(int i=0;i<s.length();i++)
            tarS[s[i]-'a']++;
        for(int i=0;i<t.length();i++)
            tarT[t[i]-'a']++;
        
        for(int i = 0;i<26;i++)
        {
            if(tarS[i]!=tarT[i])
                return 'a'+i;
        }
    }
};
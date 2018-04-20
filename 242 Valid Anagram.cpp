//242. Valid Anagram
//要求判断一个字符串是否是另一个字符串重新排列而成的
//统计字母出现字数即可

class Solution {
public:
    bool isAnagram(string s, string t) {
        char allChar[26];
        char tarChar[26];
        for(int i = 0;i<26;i++)
        {
            allChar[i]=0;
            tarChar[i]=0;
        }
            
        for(int i = 0;i<s.length();i++)
            allChar[s[i] -'a']=allChar[s[i] -'a'] + 1;
        for(int i = 0;i<t.length();i++)
            tarChar[t[i] -'a']=tarChar[t[i] -'a'] + 1;
        
        for(int i = 0;i<26;i++)
        {
            if(allChar[i] != tarChar[i])
                return false;
        }
        return true;
    }
    
    
};
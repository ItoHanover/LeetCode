//520. Detect Capital
//给出一个字符串 判断符合下列条件则返回TRUE
//全为大写
//全为小写
//仅首字母大写

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()==0)
            return false;
        
        int count = 0;
        for(string::iterator x = word.begin();x!=word.end();x++)
        {
            if('A'<= *x && *x<='Z')
                count = count + 1;
        }
        
        if(count == 0)
            return true;
        if(count == word.length())
            return true;
        if(count == 1 && ('A'<= word[0] && word[0]<='Z'))
            return true;
        
        return false;
        
    }
};
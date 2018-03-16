//344. Reverse String
//颠倒字符串 注意处理空字符串("")

class Solution {
public:
    string reverseString(string s) {
        string t;
        if(s.length()==0)
            return s;
        for(string::iterator iter_s = s.end()-1;iter_s != s.begin();iter_s--)
        {
            t.push_back(*iter_s);
        }
        t.push_back(*(s.begin()));
        return t;
    }
};
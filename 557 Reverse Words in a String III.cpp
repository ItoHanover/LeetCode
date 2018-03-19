//557. Reverse Words in a String III
//给定一个被空格分割的字符串 将其各部分旋转
//例如
//Input: "Let's take LeetCode contest"
//Output: "s'teL ekat edoCteeL tsetnoc"

class Solution {
public:
    string reverseWords(string s) {
        string::iterator startIter = s.begin();
        string::iterator iter = s.begin();
        string::iterator endIter;
        string res;
        
        if(s.length()==0)
            return s;
        
        while(iter!=s.end())
        {
            if(*iter == ' ')
            {
                for(endIter = iter-1;endIter!=startIter;endIter--)
                {
                    res.push_back(*endIter);
                }
                res.push_back(*startIter);
                res.push_back(' ');
                iter++;
                startIter = iter;
            }
            iter ++ ;
            
        }
        
		//处理最后一串字符
        if(iter==s.end())
        {
                for(endIter = iter-1;endIter!=startIter;endIter--)
                {
                    res.push_back(*endIter);
                }
                res.push_back(*startIter);
        }
        
        return res;
    }
};
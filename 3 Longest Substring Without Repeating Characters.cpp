//3. Longest Substring Without Repeating Characters
//寻找无重复字符的最长子串

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256);
        int res = 0;
        for(int i = 0;i < 256;i++)
        {
            dict[i] = -1;
        }
        int count = 0;
        for(string::iterator cptr = s.begin();cptr!=s.end();cptr++)
            for(string::iterator sptr = cptr;sptr!=s.end();sptr++)
            {
            
                if(dict[int(*sptr)]==-1)
                {
                    count = count + 1;
                
                    if(count > res)
                    res = count;
                
                    dict[int(*sptr)] = 1;
                }
                else
                {
                    count = 0;
                    for(int i = 0;i < 256;i++)
                    {
                        dict[i] = -1;
                    }
                    break;
                    //dict[int(*sptr)] = 1;
                }
            }
        
        return res;
    }
};
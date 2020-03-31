class Solution {
public:
    string longestPalindrome(string s) 
    {
        string resStr = "";
        int resStrSize = 0;

        for(string::iterator iterBegin = s.begin();iterBegin != s.end();iterBegin++)
        {
            for(string::iterator iterEnd = s.end();iterEnd != iterBegin; iterEnd--)
            {
                string tempStr = string(iterBegin,iterEnd);
                
                if(isPalindromicStr(tempStr) && tempStr.size() > resStrSize)
                {
                resStr = tempStr;
                resStrSize = tempStr.size();
                }
                
            }
        }
        
        return resStr;
    }
    
    //if tarStr is a palindromic string
    //return true
    //else return false
    bool isPalindromicStr(string tarStr)
    {
        int halfSize = 0;
        if(tarStr.size() % 2 == 1)
        {
            halfSize = (tarStr.size() /2 + 1);
        }
        else
        {
            halfSize = (tarStr.size() /2);
        }
        
        for(int i = 0; i < halfSize ;i++)
        {
                if(tarStr[i] != tarStr[tarStr.size() - (i+1)])
                {
                    return false;
                }
        }
        
        return true;
    }
};
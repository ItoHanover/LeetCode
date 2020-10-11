class Solution {
public:
    int lengthOfLastWord(string s) {
        
        if(s == " ")
            return 0;
        
        for(int j = s.size()-1; j >=0 ; j--)
        {
            if(s[j] != ' ')
            {
                
                for(int i = j; i>=0 ; i--)
                {
                    if(s[i] == ' ')
                        return j - i;
                }
                
                return j + 1;
            }
        }
        
            return 0;
    }
};
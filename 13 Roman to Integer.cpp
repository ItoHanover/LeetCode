class Solution {
public:
    int romanToInt(string s) {
        
        map<char,int> romanIndex = 
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        
        int resInt = 0;
        s.push_back('O');
        
        for(int i = 0;i<s.size()-1;i++)
        {

                if(s[i] == 'I')
                {
                    if(s[i+1] == 'V')
                    {
                        resInt = resInt + 4;
                        i = i + 1;
                    }
                    else if(s[i+1] == 'X')
                    {
                        resInt = resInt + 9;
                        i = i + 1;
                    }
                    else 
                    {
                        resInt = resInt + 1;
                    }
                        
                }
                else if(s[i] == 'X')
                {
                    if(s[i+1] == 'L')
                    {
                        resInt = resInt + 40;
                        i = i + 1;
                    }
                    else if(s[i+1] == 'C')
                    {
                        resInt = resInt + 90;
                        i = i + 1;
                    }
                    else
                    {
                        resInt = resInt + 10;
                    }
                }
                else if(s[i] == 'C')
                {
                    if(s[i+1] == 'D')
                    {
                        resInt = resInt + 400;
                        i = i + 1;
                    }
                    else if(s[i+1] == 'M')
                    {
                        resInt = resInt + 900;
                        i = i + 1;
                    }
                    else
                    {
                        resInt = resInt + 100;
                    }
                }
                else
                {
                    resInt = resInt + romanIndex[s[i]];
                }


            
        }
        
        return resInt;
        
    }
};
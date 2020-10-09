class Solution {
public:
    bool isValid(string s) 
    {
        int flag = 0;
        vector<char> vec;
        
        if(s.size()==0)
            return false;
        
        for(auto i = s.begin(); i != s.end() ; i++)
        {
            if(*i == '(')
            {
                vec.push_back(')');
            }
            else if(*i == '[')
            {
                vec.push_back(']');
            }
            else if(*i == '{')
            {
                vec.push_back('}');
            }
            else
            {
                if(vec.size()==0)
                    return false;
                
                if(vec[vec.size() - 1] != *i)
                {
                    return false;
                    break;
                }
                else
                {
                    vec.pop_back();
                }
                
            }
        }
        
        if(vec.size() != 0)
            return false;
        else
            return true;
        
    }
    
    
};
class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> vec;
        GetParenthesis(vec,"",n,0);
        
        return vec;
        
    }
    
    void GetParenthesis(vector<string>& vec,string str, int leftParenthesis,int rightParenthesis)
    {
        if(leftParenthesis == 0 && rightParenthesis == 0)
        {
            vec.push_back(str);
            return;
        }
        
        if(rightParenthesis > 0)
        {
            GetParenthesis(vec,str+')',leftParenthesis, rightParenthesis - 1);
        }
            
        if(leftParenthesis > 0)
        {
            GetParenthesis(vec,str+'(',leftParenthesis - 1, rightParenthesis + 1);
        }
        
    }
};
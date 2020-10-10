class Solution {
    public boolean isValid(String s) 
    {
        Stack<Character> sta = new Stack<Character>();
            
        
        
        if(s.length() == 0)
            return false;
        
        for(int i = 0; i < s.length(); i++)
        {
            
            if(s.charAt(i) == '(')
            {
                sta.push(')');
            }
            else if(s.charAt(i) == '[')
            {
                sta.push(']');
            }
            else if(s.charAt(i) == '{')
            {
                sta.push('}');
            }
            else
            {
                if(sta.empty())
                    return false;
                
                if(sta.peek().charValue() != s.charAt(i))
                {
                    return false;
                }
                else
                {
                    sta.pop();
                }
                
            }
        }
        
        if(sta.empty())
            return true;
        else
            return false;
    }
}
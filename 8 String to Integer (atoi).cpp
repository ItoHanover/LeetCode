class Solution {
public:
    int myAtoi(string str) 
    {
        
        int i=0;
        int minusFlag = 1;

        long long int n = 0;
        
        while(str[i]==' ' && str[i]!='\0') 
        {
            ++i;
         };
        
        if(str[i]=='-') 
        {
            minusFlag = -1;
            ++i;
        }
        else if(str[i]=='+')
        {
            ++i;
        }
        
        while(str[i]>='0' && str[i]<='9')
        {
            n = (n<<3) + (n<<1) + (str[i]-'0');
            if(n*minusFlag<INT_MIN) return INT_MIN;
            if(n*minusFlag>INT_MAX) return INT_MAX;
            ++i;
        }
        return n*minusFlag;
    }
};
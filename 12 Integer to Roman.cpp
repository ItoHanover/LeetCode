class Solution {
public:
    string intToRoman(int num) {
        map<int,string> nMap = 
        { 
            {1,"I"},
            {4,"IV"},
            {5,"V"},
            {9,"IX"},
            {10,"X"},
            {40,"XL"},
            {50,"L"},
            {90,"XC"},
            {100,"C"},
            {400,"CD"},
            {500,"D"},
            {900,"CM"},
            {1000,"M"}
        };
        
        vector<int> nVec={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string resStr;
        
        for(int i = 0;i<nVec.size();i++)
        {
            int t = num/nVec[i];
            if(t != 0)
            {
                for(int k = 0;k < t;k++)
                {
                    resStr = resStr + nMap[nVec[i]];
                }
                
                if(num % nVec[i] != 0)
                    num = num % nVec[i];
                else
                    num = 0;
            }
            
        }
        
        return resStr;
        
    }
};
class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows==1)
		    return s;
        
	   string tarStr="";
        
	   int n=s.length();
	   int cycle=2*numRows-2;
	   
	   for(int i=0;i<numRows;i++)
	   {
		   for(int j=0;j+i<n;j= j + cycle) 
           {
			   tarStr.push_back(s[j+i]);
               
			   if(i != 0 && i != numRows-1 && (j + cycle - i)<n)
				   tarStr.push_back(s[j+cycle-i]);
		   }
	   }
        
	return tarStr;
    }
};
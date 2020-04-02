class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
            return false;

		vector<int> numVec = vector<int>();
		for (int i = 10; x != 0; x=x/10)
		{
			int tempInt = x % i;
            numVec.push_back(tempInt);
			x = (x - tempInt);
		
		}
        if(PalindromeJudge(numVec))
            return true;
        else
            return false;
        
    }
    
    bool PalindromeJudge(vector<int> tarV)
    {
        int halfSize = 0;
        if(tarV.size() % 2 == 1)
        {
            halfSize = (tarV.size() /2 + 1);
        }
        else
        {
            halfSize = (tarV.size() /2);
        }
        
        for(int i = 0; i < halfSize ;i++)
        {
                if(tarV[i] != tarV[tarV.size() - (i+1)])
                {
                    return false;
                }
        }
        
        return true;
    }
};
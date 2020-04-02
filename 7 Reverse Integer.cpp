class Solution {
public:
	int reverse(int x)
	{
		long long int resInt = x;

		if (x == 0)
			return resInt;
		else
			resInt = 0;

		vector<int> numVec = vector<int>();
        int numFlag = 0;
		for (int i = 10; x != 0; x=x/10)
		{
			int tempInt = x % i;
            if(numFlag!=0 || tempInt!=0)
            {
                numVec.push_back(tempInt);
			    x = (x - tempInt);
                numFlag = 1;
            }
			
		}

		for (int i = 0; i < numVec.size(); i++)
		{
			resInt = resInt + (numVec[numVec.size() - (i + 1)] * pow(10,i));
		}
        
        if(resInt < INT_MAX && resInt > INT_MIN)
		    return resInt;
        else
            return 0;
	}
};
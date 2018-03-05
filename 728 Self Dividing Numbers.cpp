//728. Self Dividing Numbers
//若一个数是Self Dividing数，则它必须被它各位上的数字整除

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> tarVector;
        for(int i =left;i<=right;i++)
        {
            int tarVal = i;
            int flag = 1;
            int tempNum = 0;
            while(tarVal != 0)
            {
                tempNum = tarVal % 10;
                
                if(tempNum == 0)
                {
                    flag = 0;
                    break;
                }

                
                tarVal = tarVal /10;
                
                if(i%tempNum!=0)
                    flag = 0;
                    
            }
            if(flag == 1)
                tarVector.push_back(i);
            
        }
        return tarVector;
    }
    

};
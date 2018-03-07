//338. Counting Bits
//给出一个数N，计算0~N间各整数的二进制表示中，值是1的位的数量。
//并输出
//将所有数转为二进制string 然后一个个统计

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        string tempStr;
        int count = 0;
        for(int i=0;i<=num;i++)
        {
            tempStr = getStrBinary(i);
            
			//逐位计数
            for(int j = 0;j<tempStr.length();j++)
            {
                if(tempStr[j]=='1')
                {
                    count = count + 1;
                }
            }
            res.push_back(count);
            count = 0;
        }
        return res;
    }
    
	//把整数转换为二进制形式
    string getStrBinary(int tarInt)
	{
		int TempNum;
		string MainStr;
		while (1)
		{
			if (tarInt == 1 || tarInt == 0)
			{
				MainStr.insert(0, Int_to_String(tarInt));
				break;
			}

			TempNum = tarInt % 2;
			tarInt = tarInt / 2;
			MainStr.insert(0, Int_to_String(TempNum));

		}
		return MainStr;
	}
    
	//把整数转换为字符串
    string Int_to_String(int n)
	{
		ostringstream stream;
		stream << n;
		return stream.str();
	}
};

Follow up:
//利用位运算

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};
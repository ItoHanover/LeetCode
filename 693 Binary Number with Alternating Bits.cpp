//693. Binary Number with Alternating Bits
//给定一个数 判断其二进制形式是否交错出现1和0

class Solution {
public:
    bool hasAlternatingBits(int n) {
        string str = getStrBinary(n);
        for(string::iterator iter = str.begin();iter!=str.end()-1;iter++)
        {
            if(*iter==*(iter+1))
                return false;
        }
        return true;
    }
    
    //将数转换为二进制字符串
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
    
    //将int转换为字符串
	string Int_to_String(int n)
	{
		ostringstream stream;
		stream << n;
		return stream.str();
	}
};
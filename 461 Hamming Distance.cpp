//461. Hamming Distance
//要求计算两个数之间的Hamming距离
//Hamming距离，指的是两个长度相等的字符串在相同位置上不同的字符的个数
//本题中，两个数的Hamming距离为这两个数的二进制形式里各对应位上不同的字符个数
//当二进制数位的数量不同时，较短的二进制数在前方补零

//例如1和4的Hamming距离
//1   (0 0 0 1)
//4   (0 1 0 0)
//Hamming距离为2

class Solution {
public:
	int hammingDistance(int x, int y)
	{
		string Xstr = getStrBinary(x);
		string Ystr = getStrBinary(y);
		int dis = 0;

		if (Xstr.length() == Ystr.length())
		{
			for (int i = Xstr.length(); i>0; i--)
			{
				if (Xstr[i - 1] != Ystr[i - 1])
					dis = dis + 1;
			}
		}
		else if (Xstr.length() > Ystr.length())
		{
			int temp = Xstr.length() - Ystr.length();
			for (int i = Ystr.length(); i>0; i--)
			{
				if (Xstr[temp + i - 1] != Ystr[i - 1])
					dis = dis + 1;
			}
            for (int j = 0;j<temp;j++)
            {
                if(Xstr[j]=='1')
                {
                    dis = dis + 1;
                }
            }
			
		}
		else if (Xstr.length() < Ystr.length())
		{
			int temp = Ystr.length() - Xstr.length();
			for (int i = Xstr.length(); i>0; i--)
			{
				if (Xstr[i - 1] != Ystr[temp + i - 1])
					dis = dis + 1;
			}
			            
            for (int j = 0;j<temp;j++)
            {
                if(Ystr[j]=='1')
                {
                    dis = dis + 1;   
                }

            }
		}

		return dis;


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
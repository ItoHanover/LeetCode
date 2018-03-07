//537. Complex Number Multiplication
//虚数相乘
//很简单 大部分时间浪费在处理字符串

struct ComplexNum
{
	int RealPart;
	int ImagPart;

};

class Solution {
public:
	string complexNumberMultiply(string a, string b) {

		ComplexNum lVal = GetComplexNum(a);
		ComplexNum rVal = GetComplexNum(b);

		ComplexNum tarVal;
		tarVal.RealPart = lVal.RealPart*rVal.RealPart + (-1) * lVal.ImagPart * rVal.ImagPart;
		tarVal.ImagPart = lVal.ImagPart*rVal.RealPart + lVal.RealPart*rVal.ImagPart;

		string res;
		res = IntToString(tarVal.RealPart) + "+" + IntToString(tarVal.ImagPart) + "i";
		return res;
	}

	ComplexNum GetComplexNum(string tarStr)
	{
		ComplexNum comNum;
		int FirstFlag = 0;
		int flag = 1;

		if (tarStr[0] == '-')
			FirstFlag = 1;

		string::iterator tarIter = tarStr.begin() + FirstFlag;

		for (;*tarIter != '+'; tarIter++);
		string tempStr(tarStr.begin() + FirstFlag, tarIter);
		comNum.RealPart = atoi(tempStr.c_str());

		if (tarStr[0] == '-')
			comNum.RealPart = -comNum.RealPart;

		string::iterator nextIter = tarIter + 1;
		if (*nextIter == '-')
		{
			nextIter = nextIter + 1;
			tarIter = tarIter + 1;
			flag = 0;
		}


		for (tarIter = tarIter + 2; *tarIter != 'i'; tarIter++);
		string nexttempStr(nextIter, tarIter);
		comNum.ImagPart = atoi(nexttempStr.c_str());

		if (flag == 0)
			comNum.ImagPart = -comNum.ImagPart;

		return comNum;
	}

	string IntToString(int n)
	{
		ostringstream stream;
		stream << n;
		return stream.str();
	}
};
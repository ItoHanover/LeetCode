class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string resStr = "";
		//string searchStr = "";

		if (strs.size() == 0)
			return "";

		if (strs.size() == 1)
			return strs[0];

		if (strs[0] == "")
			return "";

		for (int i = 0; i < strs.begin()->size(); i++)
		{
			string searchStr((*strs.begin()), 0, i + 1);
            

			for (vector<string>::iterator iterCurrent = strs.begin() + 1; iterCurrent != strs.end(); iterCurrent++)
			{
                int curFlag = 0;

				for (int flag = 0; flag < iterCurrent->size() && flag < searchStr.size(); flag++)
				{
					if ((*iterCurrent)[flag] != searchStr[flag])
					{
						searchStr = "";
						break;
					}
					curFlag = curFlag + 1;
				}
                searchStr = string(searchStr,0,curFlag);

			}

			if (searchStr.size() > resStr.size())
			{
				resStr = searchStr;
			}

		}

		return resStr;
	}
};
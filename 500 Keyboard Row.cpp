//500. Keyboard Row
//判断一个字符串里所有字符是否属于键盘上同一排

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,int> row;
        
        row.insert(pair<char,int>('q',1));
        row.insert(pair<char,int>('w',1));
        row.insert(pair<char,int>('e',1));
        row.insert(pair<char,int>('r',1));
        row.insert(pair<char,int>('t',1));
        row.insert(pair<char,int>('y',1));
        row.insert(pair<char,int>('u',1));
        row.insert(pair<char,int>('i',1));
        row.insert(pair<char,int>('o',1));
        row.insert(pair<char,int>('p',1));
        
        row.insert(pair<char,int>('a',2));
        row.insert(pair<char,int>('s',2));
        row.insert(pair<char,int>('d',2));
        row.insert(pair<char,int>('f',2));
        row.insert(pair<char,int>('g',2));
        row.insert(pair<char,int>('h',2));
        row.insert(pair<char,int>('j',2));
        row.insert(pair<char,int>('k',2));
        row.insert(pair<char,int>('l',2));
        
        row.insert(pair<char,int>('z',3));
        row.insert(pair<char,int>('x',3));
        row.insert(pair<char,int>('c',3));
        row.insert(pair<char,int>('v',3));
        row.insert(pair<char,int>('b',3));
        row.insert(pair<char,int>('n',3));
        row.insert(pair<char,int>('m',3));

        int flag = 0;
        bool temp = true;
        vector<string> res;
        for (int x = 0;x< words.size();x++)
		{
			flag = row.find(tolower(*words[x].begin()))->second;
			for (int y=0; y < words[x].length();y++)
			{
				if (flag != (row.find(tolower(words[x][y]))->second))
				{
					temp = false;
					break;
				}
			}
			if (temp == true)
				res.push_back(words[x]);
            temp = true;
		}
        return res;
        
    }
};
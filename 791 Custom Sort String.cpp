//791. Custom Sort String
//给出一个仅含小写字母的字符串A
//再给出一个字符串B，要求将字符串B按之前所给出的字符串A中字母的顺序排序
//在A中，越靠近左侧的字符越大，越靠近右侧的字符越小
//如果B中出现A中未出现的字符 则这个字符摆在任意位置均可
//利用lambda表达式与std::sort()

//使用unordered_map的版本
class Solution {
public:
	string customSortString(string S, string T) {
		unordered_map<char, int> indexMap;
		for (int i = 0; i < S.length(); i++)
		{
			indexMap[S[i]] = i + 1;
		}

		sort(T.begin(), T.end(),
			[&indexMap](char a, char b){return indexMap[a] < indexMap[b];}
		);

		return T;
	}
};

//使用map的版本
class Solution {
public:
	string customSortString(string S, string T) {
		map<char, int> indexMap;
		for (int i = 0; i < S.length(); i++)
		{
			indexMap.insert(pair<char, int>(S[i], i + 1));
		}

		sort(T.begin(), T.end(),
			[&indexMap](char a, char b){return indexMap[a] < indexMap[b];}
		);

		return T;
	}
};
//575. Distribute Candies
//给定一个有N个数字的数组 将数组内的数字分为2组
//要求每组内出现的数字的种类最多 并返回这个最大值
//利用unordered_map

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int res = 0;
        int candiesNum = candies.size();
        unordered_map<int,int> u_map(20000);
        for( auto x : candies)
        {
            u_map[x]++;
            if(u_map[x]==1 && res < candiesNum/2)
                res = res + 1;

        }
        return res;
    }
};
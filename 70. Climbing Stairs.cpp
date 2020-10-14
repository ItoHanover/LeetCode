class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        
        vector<int> v = vector<int>(n,0);
        
        v[0] = 1;
        v[1] = 2;
        
        for(int i = 2; i<n; i++)
        {
            v[i] = v[i-1] + v[i-2];
        }
        
        return v[v.size() - 1];
    }
};
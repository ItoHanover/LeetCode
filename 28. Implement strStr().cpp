class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle == "")
            return 0;
        
        
        if(haystack.find(needle) == haystack.npos)
            return -1;
        else
            return haystack.find(needle);
    }
};
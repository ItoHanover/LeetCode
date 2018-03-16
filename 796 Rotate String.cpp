//796. Rotate String
//给定一个字符串A
//若A可以通过不断将A最左侧字符移动到最右侧的方式变换为B 则返回TRUE
//不能则返回FALSE

//解法仍有有优化空间

class Solution {
public:
    bool rotateString(string A, string B) {
        
        string C = A;
        C.push_back(*C.begin());
        C.erase(C.begin());
        if(C==B)
            return true;
        for(string::iterator iterA = C.begin();C!=A;)
        {
            C.push_back(*C.begin());
            C.erase(C.begin());
            if(C==B)
                return true;
        }
        return false;
    }
};
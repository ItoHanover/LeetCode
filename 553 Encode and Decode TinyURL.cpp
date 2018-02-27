//553 Encode and Decode TinyURL
//要求将一个URL转换为短URL
//采用发号方式
//未全部完善 encode返回的string并非url格式

class Solution {
public:
    
    Solution()
    {
        CurrentNum = 0;
        
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        CurrentNum = CurrentNum + 1;
        UrlMap.insert(pair<int,string>(CurrentNum,longUrl));
        string tarUrl = IntToString(CurrentNum);
        return tarUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        //shortUrl.erase(shortUrl.begin(),shortUrl.begin()+17);
        int UrlKey = atoi(shortUrl.c_str());

        return UrlMap[UrlKey];
    }
    
private:
    map<int,string> UrlMap;
    int CurrentNum;
    
	//将int型转换为string的函数
    string IntToString(int n)
    {
    ostringstream stream;
    stream<<n;
    return stream.str();
    }
    
    
};
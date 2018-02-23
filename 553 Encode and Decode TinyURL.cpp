//553 Encode and Decode TinyURL
//要求将一个URL转换唯物短URL
//采用发号方式

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
        string tarUrl = Int_to_String(CurrentNum);
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
    
    string Int_to_String(int n)
    {
    ostringstream stream;
    stream<<n;
    return stream.str();
    }
    
    
};
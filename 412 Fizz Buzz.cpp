//412. Fizz Buzz
//很容易

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> Svector;
        string fStr = "Fizz";
        string bStr = "Buzz";
        string fbStr = "FizzBuzz";
        for(int i =1;i<=n;i++)
        {
            if(i % 3 == 0 && i % 5 !=0)
            {
                Svector.push_back(fStr);
            }
            if(i % 5 == 0 && i % 3 !=0)
            {
                Svector.push_back(bStr);
            }
            if(i % 5 == 0 && i % 3 == 0)
            {
                Svector.push_back(fbStr);
            }
            if(i % 3 !=0 && i % 5 !=0)
            {
                Svector.push_back(Int_to_String(i));
            }
                
            
        }
        return Svector;
    }
    
    string Int_to_String(int n)
	{
		ostringstream stream;
		stream << n;
		return stream.str();
	}
};
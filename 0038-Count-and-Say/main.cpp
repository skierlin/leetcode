
class Solution {
public:
    string countAndSay(int n) {

        string s = "1";
        if(n == 1)
            return s;

        for(int i = 2; i <= n; i ++)
            s = next(s);
        return s;
    }

private:
    string next(const string& s){

        string ret = "";
        int start = 0;
        for(int i = start + 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){
                ret += to_string(i - start) + s[start];
                start = i;
            }
        return ret;
    }
};


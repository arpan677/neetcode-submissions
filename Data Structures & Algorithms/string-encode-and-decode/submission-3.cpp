class Solution {
public:

    string encode(vector<string>& strs) {
           string ans = "";

        for (string s : strs) {
            ans += to_string(s.size());
            ans += "#";
            ans += s;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        while(i<s.size()){
            int len=0;
            while(s[i]!='#'){
                len=len*10+(s[i]-'0');
                i++;
            }
            i++;
            string curr=s.substr(i,len);
            ans.push_back(curr);
            i+=len;
        }

        return ans;
    }
};

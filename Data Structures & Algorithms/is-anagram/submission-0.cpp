class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a1(26, 0);
        vector<int> a2(26, 0);

        for(int i = 0; i < s.size(); i++) {
            int l = s[i] - 'a';
            a1[l]++;
        }

        for(int i = 0; i < t.size(); i++) {
            int l = t[i] - 'a';
            a2[l]++;
        }

        return a1 == a2;
    }
};
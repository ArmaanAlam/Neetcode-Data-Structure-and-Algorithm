class Solution {
public:

    string encode(vector<string>& strs) {

        if (strs.empty()) {
            return "";
        }

        string res = "";

        for (int i = 0; i < strs.size(); i++) {
            int n = strs[i].size();
            res += to_string(n);
            res += ",";
        }

        res += "#";

        for (int i = 0; i < strs.size(); i++) {
            res += strs[i];
        }

        return res;
    }

    vector<string> decode(string s) {

        if (s.empty()) {
            return {};
        }

        vector<int> length;
        vector<string> res;

        int i = 0;

        while (s[i] != '#') {

            int j = i;
            while (s[j] != ',') {
                j++;
            }

            length.push_back(stoi(s.substr(i, j - i)));
            i = j + 1;
        }

        i++;

        for (int size : length) {

            res.push_back(s.substr(i, size));

            i += size;
        }

        return res;
    }
};
class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char, char> mp = {
            {'(',')'},
            {'{','}'},
            {'[',']'}
        };

        stack<char> st;

        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                char topchar = st.top();
                if(ch != mp[topchar]){
                    return false;
                }
                st.pop();
            }
        }

        if(st.empty()) return true;

        return false;
    }
};

class Solution {

    int operation(int a, int b, string str){
        if(str == "+"){
            return a + b;
        }
        if(str == "*"){
            return (long)a * (long)b;
        }
        if(str == "-"){
            return a - b;
        }
        else{
            return a / b;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size();
        stack<int> st;

        for(string str : tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int res = operation(b, a, str);
                st.push(res);
            }
            else{
                st.push(stoi(str));
            }
        }

        return st.top();
    }
};

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(auto opp : operations){
            if(opp == "+"){
                int top = st.top();
                st.pop();
                int newtop = top + st.top();
                st.push(top);
                st.push(newtop);
            }
            else if(opp == "C"){
                st.pop();
            }
            else if(opp == "D"){
                int topdoub = 2 * st.top();
                st.push(topdoub);
            }
            else{
                st.push(stoi(opp));
            }
        }

        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        return res;
    }
};
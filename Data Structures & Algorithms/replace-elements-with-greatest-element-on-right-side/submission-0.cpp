class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> ans(n, 0);
        ans[n-1] = -1;

        stack<int>st;
        st.push(arr[n-1]);

        for(int i = n-2; i >= 0; i--){
            ans[i] = st.top();
            if(st.top() < arr[i]){
                st.push(arr[i]);
            }
        }

        return ans;
    }
};
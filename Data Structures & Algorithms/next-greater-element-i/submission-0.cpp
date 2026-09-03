class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, int> mp;
        stack<int> st;

        for(int i = m-1; i >= 0; i--){

            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }

            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            else{
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }


        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = mp[nums1[i]];
        }

        return ans;

    }
};
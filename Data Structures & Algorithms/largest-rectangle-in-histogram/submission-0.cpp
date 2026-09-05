class Solution {


vector<int> prev(vector<int>& heights, int n){ 
    vector<int> ans(n); 
    stack<int> st; 

    for(int i = 0; i < n; i++){ 

        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop(); 
        } 

        if(st.empty()){ 
            ans[i] = -1; 
        } 
        else{ 
            ans[i] = st.top(); 
        }

        st.push(i);
    } 

    return ans; 
}


vector<int> next(vector<int>& heights, int n){ 
    vector<int> ans(n); 
    stack<int> st; 

    for(int i = n - 1; i >= 0; i--){ 

        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop(); 
        } 

        if(st.empty()){ 
            ans[i] = n; 
        } 
        else{ 
            ans[i] = st.top(); 
        }

        st.push(i);
    } 

    return ans; 
}


public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> prefix = prev(heights, n);
        vector<int> suffix = next(heights, n);

        int area = 0;

        for(int i = 0; i < n; i++){
            area = max(area, 
                       (suffix[i] - prefix[i] - 1) * heights[i]);
        }

        return area;
    }
};
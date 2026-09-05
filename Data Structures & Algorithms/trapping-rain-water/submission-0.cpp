class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> pref(n);
        vector<int> suff(n);

        pref[0] = height[0];
        suff[n-1] = height[n-1];

        int water = 0;

        for(int i = 1; i < n; i++){
            pref[i] = max(height[i], pref[i-1]);
        }

        for(int i = n-2; i >= 0; i--){
            suff[i] = max(height[i], suff[i+1]);
        }

        for(int i = 0; i < n; i++){
            water += min(suff[i], pref[i]) - height[i];
        }

        return water;
    }
};
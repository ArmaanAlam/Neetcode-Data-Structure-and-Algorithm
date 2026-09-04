class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];

        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + nums[i];
        }

        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(pre[i] == k){
                cnt++;
            }
            for(int j = 0; j < i; j++){
                if(pre[i] - pre[j] == k){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
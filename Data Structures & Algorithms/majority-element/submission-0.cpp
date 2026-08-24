class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        int element = 0;

        for(int i = 0; i < n; i++){
            if(cnt == 0){
                element = nums[i];
                cnt = 1;
            }
            else if(element == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        cnt = 0;
        for(int i = 0; i < n; i++){
            if(element == nums[i]){
                cnt++;
            }
        }

        if(cnt > n/2) return element;

        return -1;
    }
};
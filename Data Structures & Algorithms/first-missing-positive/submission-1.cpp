class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int target = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] < target) continue;

            if(target == nums[i]){
                target++;
            }
            else{
                break;            }
        }

        return target;
    }
};
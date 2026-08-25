class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int zero = 0;
        int point = 0;
        int two = n-1;

        while(point <= two){
            if(nums[point] == 0){
                swap(nums[point], nums[zero]);
                zero++;
                point++;
            }
            else if(nums[point] == 2){
                swap(nums[point], nums[two]);
                two--;
            }
            else{
                point++;
            }
        }
    }
};
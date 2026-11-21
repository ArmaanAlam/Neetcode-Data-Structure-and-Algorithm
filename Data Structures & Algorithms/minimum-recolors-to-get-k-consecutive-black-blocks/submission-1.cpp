class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int left = 0;
        int right = 0;
        int mincolor = INT_MAX;
        int white = 0;

        while(right < blocks.size()){

            if(blocks[right] == 'W'){
                white++;
            }

            if(right - left + 1 > k){
                if(blocks[left] == 'W'){
                    white--;
                }
                left++;
            }

            if(right - left + 1 == k){
                mincolor = min(mincolor, white);
            }

            
            right++;
        }

        return mincolor;
        
    }
};
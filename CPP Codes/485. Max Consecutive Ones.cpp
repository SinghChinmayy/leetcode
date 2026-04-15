// Runtime: 1 ms — Beats 25.14% | Memory: 50.30 MB — Beats 33.41%

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0;
        int counter = 0;
       for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            counter++;
        }
        if(nums[i] != 1){
            //update max ones
            if(max_ones < counter){
                max_ones = counter;
            }
            //reset counter
            counter = 0;
        }
       }
       if(max_ones < counter){
        return counter;
       }
       return max_ones;e
    }
};

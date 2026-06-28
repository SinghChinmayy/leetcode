class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest_sum = nums[0];
        if (nums.size() == 1)
            return nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum < 0){
                sum = 0;
            }
            sum += nums[i];
            if (sum > largest_sum)
                largest_sum = sum;
        }
        return largest_sum;
    }
};
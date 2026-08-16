class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        int a = 0;
        while(a < nums.size() -2 && nums[a] <= 0){
            int left = a + 1;
            int right = nums.size() - 1;
            // apply 2 sum on left and right pointers
            while(left < right){
                int sum = nums[a] + nums[left] + nums[right];
                if(sum == 0){
                    result.push_back({nums[a], nums[left], nums[right]});
                    left++;
                    while(left < right && nums[left] == nums[left - 1])left++;//check if after increment the current value equals old value
                    right--;
                    while(left < right && nums[right] == nums[right + 1])right--;//check if after increment the current value equals old value
                }
                if(sum < 0)left++;
                if(sum > 0)right--;
            }
            a++;
            while(a < left && nums[a] == nums[a-1])a++;
        }
        return result;
    }
};
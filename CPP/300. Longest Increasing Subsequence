class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

    //    initialize vector for caching
        vector<int> LIS(nums.size(), 1);

    //    loop elements and find maximum subsequence

        for(int i = nums.size() - 1; i >= 0; i--){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] < nums[j]){
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }
        return *max_element(LIS.begin(), LIS.end());
    }
}
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> count;
        std::pair<int, int> max = {-1, -1};
        for(int i = 0; i < nums.size(); i++){
            count.insert({nums[i], (++count[nums[i]])});
            if(count[nums[i]] > max.second){
                // update max
                max.first = nums[i];
                max.second = count[nums[i]];
            }
       } 
       
        return max.first;
    }
};
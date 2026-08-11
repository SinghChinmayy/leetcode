class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right = numbers.size() -1;
        int left = 0;
        while(right > left && !(numbers[left] + numbers[right] == target)){
            int cur_sum = numbers[left] + numbers[right];
            if(cur_sum > target) right--;
            if(cur_sum < target) left++;

        }
        return vector<int> {left+1, right+1};
    }
};
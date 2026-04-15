// every element appears twice except for one.
// USing XOR property
// ```
// XOR gives 0 ^ 0 = 0 and 1 ^ 0 = 1 
// | Expression      | Result  |
// | --------------- | ------- |
// | `a ^ a`         | 0       |
// | `a ^ a ^ b`     | b       |
// | `a ^ b ^ a`     | b       |
// ```
// a ^ a = 0
// a ^ 0 = a
// a ^ b ^ a = b

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int single = 0;
       for(int i = 0; i < nums.size(); i++){
        single = nums[i] ^ single;
       } 
       return single;
    }
};

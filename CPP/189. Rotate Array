class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    //
    //slower approch
        // int i = 0;
        // while(i < k){
        //     int last_element = nums.back();
        //     nums.insert(nums.begin(),last_element);
        //     nums.pop_back();
        //     i++;
        // }
    //
    //effective rotation 
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k );
    reverse(nums.begin() + k, nums.end());
    }
};


//tracing
//  k = 2 | n = 4
// k = k % n = 2
// [-1,-100,3,99]
// 99, 3, -100, -1
// 

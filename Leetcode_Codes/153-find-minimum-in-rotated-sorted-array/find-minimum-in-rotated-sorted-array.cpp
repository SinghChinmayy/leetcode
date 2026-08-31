class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() -1;

        while( l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] > nums[r]){
                l = mid + 1;//since mid cant be smallest
            }
            else{//this checks equal condition too so to reach l==r condtion
                r= mid;
            }

        }
        // l == r is the answer
        return nums[l];
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 31;
        auto result = 0;
        while(n > 0){
            // grab forst bit of n
            auto temp = n & 1; 
            n = n >>1;
            // insert it in result
            result = result | (temp << i--);
        }
        return result;
    }
};

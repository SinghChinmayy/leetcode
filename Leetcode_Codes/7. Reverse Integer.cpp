class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        
        while( x != 0){
            // edge cases
            // 
            // INT_MAX =  2147483647
            // INT_MIN = -2147483648
            // 
            int temp = x%10; 
            if(rev == INT_MAX/10 && temp > 7) return 0;
            if(rev == INT_MIN/10 && temp < -8 ) return 0;
            if(rev <= INT_MAX/10 && rev >= INT_MIN/10){
                rev = rev * 10 + temp;
                x = x/10;
            }else return 0;
        }
        return rev;
    }
};
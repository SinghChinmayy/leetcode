class Solution {
public:
    bool isPalindrome(int x) {
        //when not a palindrom
        // -ve numbers are not palindrome
        // numbers ending with 0 excluding case where x is 0 itself
        if( x < 0 || ( x%10 == 0 && x != 0)) return false;

        // reverse and check
        int rev = 0; 
        while(rev < x){
            rev = rev * 10 + x%10;
            x = x/10;
        }
        return (rev == x || rev/10 == x);
    }
}
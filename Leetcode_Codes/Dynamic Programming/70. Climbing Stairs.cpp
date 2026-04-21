// Recursion Solution

class Solution {
public:
    int climbStairs(int n) {
        //to reach the nth level 
        // either reached from n-1 or n-2
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        int steps = climbStairs(n-1) + climbStairs(n-2);
        return steps;
    }
}



// optimal time with O(n) complexity

class Solution {
public:
    int solve(int n, vector<int> &dp){
        
        if(n == 1){
            return 1;
        }
        
        if(n == 2){
            return 2;
        }

        //compute if not computed yet
        if(dp[n] == -1){
            dp[n] = solve(n-1, dp) + solve(n-2, dp);
        }
        return dp[n];
    }

    int climbStairs(int n) {

        // caching to save computation
        vector<int> steps (n + 1, -1);
        steps[1] = 1;
        if(n >= 2){
            steps[2] = 2;
        }
        solve(n, steps);
        return steps[n]; 
    }
}
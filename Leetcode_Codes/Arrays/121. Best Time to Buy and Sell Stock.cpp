class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //    only one date
    if(prices.size() <= 1){
        return 0;
    }

       int l = 0;
       int max_profit  = 0;
       int profit = 0;
       for(int r = 1; r < prices.size(); r++){
        // if left < right 
        // calculate profit
        if(prices[l] < prices[r]){
            profit = prices[r] - prices[l];
        }
        // if right is less than left => there can be a lower low
        if(prices[r] < prices[l]){
            // make right the new left
            l = r;
            continue;
        }

        // update max_profit
        if(profit > max_profit){
            max_profit = profit;
        }
       }

       return max_profit;
    }
};
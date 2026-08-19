class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int v = 0; v <= n; v++){
            result.push_back(No1s(v));
        }
        return result;
    }
    int No1s(int n){
        if(n == 0) return 0;
        int result = 0;
        while(n > 0){
            if(n&1 == 1)result++;
            n = n>>1;
        }
        return result;
    }
};

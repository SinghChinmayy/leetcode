class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>flag = {0,0,0};
        for(int i = 0; i < triplets.size(); i++){
            // check if to completly check array or ignore
            if(
                triplets[i][0] > target[0] ||
                triplets[i][1] > target[1] ||
                triplets[i][2] > target[2]
            ){
                continue;
            }
            for(int j = 0; j < 3; j++){
               if(triplets[i][j] == target[j]){
                flag[j] = 1;
               }
            }
        }
        
        if(flag == vector<int>{1,1,1})return true;
        return false;
    }
};
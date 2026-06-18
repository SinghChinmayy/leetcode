class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        // start with second row
        for(int i = 1; i < numRows; i++){
            vector<int> temp;
            vector<int> add;
            temp.push_back({0});
            temp.insert(temp.end(),result[i-1].begin(), result[i-1].end());
            temp.push_back({0});
            int p1 = 0;
            int p2 = 1;
            while(p2 < temp.size()){
                int val = temp[p1] + temp[p2];
                add.push_back(val);
                p1++;
                p2++;
            }
            result.push_back(add);
        }
        return result;
    }
};
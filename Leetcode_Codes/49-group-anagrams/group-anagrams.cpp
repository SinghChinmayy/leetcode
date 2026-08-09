class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map< string, vector<string>> res;
        
        for( auto s : strs){
            auto s_sorted = s;
            sort(s_sorted.begin(), s_sorted.end());
            res[s_sorted].push_back(s);
        }
        vector<vector<string>> result;
        for(auto [key, val] : res){
            result.push_back(val);
        }
        return result;
    }
};
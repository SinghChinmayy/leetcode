class Solution {
public:
    bool isAnagram(string s, string t) {
    //    insert s in hash table/unordered map
    unordered_map<char, int> chars;
    for(char c : s){
        chars[c] += 1;        
    }
    // validate t with s 
    for(char c : t){
        chars[c] -= 1;
    }
    for(auto[key, value] : chars){
        if(value != 0){
            return false;
        }
    }
    return true;
    }
};
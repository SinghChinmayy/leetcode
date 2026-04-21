// My solution 
// it is not most optimal
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 1;
         if (s.length() == 0) {
            return 0;
         }
        
        if (s.length() == 1) {
            return 1;
        }

        for (int i = 0; i < s.length() - 1; i++) {
            unordered_set<int> h;
            h.insert(s[i]);
            int length = 1;
            // find largest pattern
            for (int j = i + 1; j < s.length(); j++) {
                if (h.find(s[j]) == h.end()) {
                    h.insert(s[j]);
                    length++;
                } else
                    break;
            }
            // update max_length
            if (length > max_length) {
                max_length = length;
            }
        }
        return max_length;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // take in vector->convert it to set
        std::unordered_set<int> s;
        for(auto n : nums){
            s.insert(n);
        }
        int longest_seq = 0;
        // we ittereate through each element of vector and try to find the longest sequence
        for(auto n: s){
            if(s.find(n - 1) == s.end()){
                //this is the starting element
                // create longest possible sequence
                int seq_count = 0;
                while( s.find(n) != s.end()){
                    // element exist in sequence
                    seq_count++;
                    n++;
                }
                if(seq_count > longest_seq){
                    longest_seq = seq_count;
                }
            }
        }
        return longest_seq;
    }
};
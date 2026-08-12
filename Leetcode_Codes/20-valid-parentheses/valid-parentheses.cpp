class Solution {
public:
    bool isValid(string s) {
        // use stack for implementation
         stack<char>track;
         if(s.length() == 1)return false;
         for(auto c : s){
            if(c == '(' || c == '[' || c == '{'){
                track.push(c);
            }else if(c == ')' || c == ']' || c == '}'){
                if(track.empty())return false;
                char prev = track.top();
                track.pop();
                if(prev == '(' && c != ')') return false;
                if(prev == '[' && c != ']') return false;
                if(prev == '{' && c != '}') return false;
            }
         }
        //  if stack is not emty then false
        if(!track.empty())return false;
         return true;
    }
};
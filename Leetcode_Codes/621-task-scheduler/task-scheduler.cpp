class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int, vector<int>, less<int>>maxHeap;
        unordered_map<char, int> freq;
        // calculate the frequency
        for(auto task : tasks){
            freq[task]++;
        }
        
        // create maxHeap
        for(auto [key, value] : freq){
            maxHeap.push(value);
        }
        
        // calculate #cycles needed
        int cycle = 0; 

        //1. Move all cooldown tasks whose availableTime <= time
        //    back into maxHeap.

        // 2. If maxHeap isn't empty:
        //        take largest frequency
        //        decrement it

        //        if frequency > 0:
        //            put it into cooldown

        // 3. Otherwise:
        //        CPU is idle

        // 4. time++

        // pair of freq and cooldown time
        queue<pair<int, int>> cooldown;

        while(maxHeap.size() != 0 || cooldown.size() != 0){
            while(!cooldown.empty() && cooldown.front().second <= cycle){
                // move from cooldown to maxHeap
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
            if(!maxHeap.empty()){
                int active = maxHeap.top();
                maxHeap.pop();
                active--;
            if(active > 0){
                cooldown.push({active, cycle + n + 1});
            }
            }



            cycle++;
        }
        return cycle;
    }
};
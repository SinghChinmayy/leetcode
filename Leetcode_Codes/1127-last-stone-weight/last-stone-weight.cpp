class Solution {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;

public:
    int lastStoneWeight(vector<int>& stones) {
        //insert all stones into heap
        for(auto stone : stones){
                maxHeap.push(stone);
        }
        // calculating top 2 stones weight
        // 
        while(maxHeap.size() > 1){
            // get top 2 elements
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            if(x == y){
                continue;
            }
            if(x != y){
                y = y - x;
                maxHeap.push(y);
            }
        }
        if(maxHeap.size() == 0)return 0;
        return maxHeap.top();
    }
};
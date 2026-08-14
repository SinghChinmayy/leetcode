struct Compare{
    bool operator()(const pair<int, vector<int>>& a,
        const pair<int, vector<int>>& b
    ){
        return a.first< b.first;
    }
};

class Solution {
private:
    priority_queue<
    pair<int, vector<int>>,
    vector< pair< int, vector<int> > > , 
    Compare >
    maxHeap;

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(auto point : points){
            int dis = (point[0]*point[0]) + (point[1]*point[1]);
            maxHeap.push({dis, point});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> result;
        for(int i = 0; i < k; i++){
            if(maxHeap.size() > 0){
                result.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
        }
        return result;
    }
};
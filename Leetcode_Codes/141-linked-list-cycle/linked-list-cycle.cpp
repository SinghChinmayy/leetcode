/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // handle empty case
        if(head == nullptr)return false;
        unordered_set<ListNode*>track;
        bool found = 0;
        while(head->next != nullptr && found == 0){
            // if next element exists in the set=>loop
            if( track.find(head->next) != track.end()){
                found = 1;
            }
            // if next element dne=> keep going
            if( track.find(head->next) == track.end()){
                // update head and track set
                track.insert(head);
                head = head->next;
            }
        }
        if(found) return true;
        return false;
    }
};

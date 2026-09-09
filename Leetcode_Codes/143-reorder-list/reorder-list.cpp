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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast->next != nullptr) fast = fast->next;

        ListNode* mid = slow;
        ListNode* end = fast;
        // reverse the pointers
        ListNode* p2 = mid->next;
        mid->next = nullptr;
        ListNode*prev = nullptr;
    
        while(p2 != nullptr){
            ListNode* temp = p2->next;
            p2->next = prev;
            prev = p2;
            p2 = temp;
        }

        p2 = prev;//start of pointer p2
        ListNode* p1 = head;
        // merge 2 lists
        while(p2 != nullptr){
            ListNode* mid = p2;
            p2 = p2->next;
            ListNode* p1_end = p1->next;
            p1->next = mid;
            mid->next = p1_end;
            p1 = p1_end;
        }
    }
};
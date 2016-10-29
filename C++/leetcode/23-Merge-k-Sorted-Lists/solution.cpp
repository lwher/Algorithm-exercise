/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Compare_class{
    bool operator ()(ListNode* A, ListNode* B){
    	return A -> val > B -> val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode *head = NULL, *last = NULL;
     	int K = lists.size();
     	priority_queue<ListNode*, vector<ListNode*>, Compare_class> Q;
     	for(int i = 0; i < K; i++){
     		if(lists[i] != NULL)
     			Q.push(lists[i]);
     	}
     	while(!Q.empty()){
     		ListNode *p = Q.top();
     		Q.pop();
     		if(head == NULL) head = new ListNode(*p), last = head;
     		else last -> next = new ListNode(*p), last = last -> next;
     		if(p -> next != NULL)
     			Q.push(p -> next);
     	}
     	return head;
    }
};
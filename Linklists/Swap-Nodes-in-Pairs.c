//Problem 24
//Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* swapPairs(struct ListNode* head) 
{
    if(head == NULL ||head->next == NULL) return head;
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    head = curr->next;

    while(curr !=NULL && curr->next !=NULL)
    {
        struct ListNode * nextp = curr->next->next;
        struct ListNode * second = curr->next;

        second -> next = curr;
        curr->next = nextp;

        if(prev != NULL) prev->next = second;

        prev = curr;
        curr = nextp;
    }
    return head;
}
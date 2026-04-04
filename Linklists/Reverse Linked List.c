//Problem 206
struct ListNode* reverseList(struct ListNode* head) 
{
    if(head == NULL) return head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr= next;
    }
    head = prev;
    return head;
}
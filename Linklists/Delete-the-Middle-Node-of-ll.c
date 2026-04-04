//Problem 2095
 //Definition for singly-linked list.
struct ListNode {
      int val;
      struct ListNode *next;
};
 
struct ListNode* deleteMiddle(struct ListNode* head) 
{
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }
    struct ListNode*temp = head;
    int n=0;
    while(temp!=NULL)
    {
        temp = temp->next;
        n++;
    }
    int currentpos = 1;
    temp = head;
    while(temp!=NULL && currentpos<n/2)
    {
        temp = temp->next;
        currentpos++;
    }
    struct ListNode*nodetodelete = temp->next;
    temp->next = nodetodelete->next;
    free(nodetodelete);
    return head;
}
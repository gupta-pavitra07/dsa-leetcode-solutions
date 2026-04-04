//Problem 203
struct ListNode* removeElements(struct ListNode* head, int val) 
{
    if(head == NULL) return head;
    while(head != NULL && head->val == val)
    {
        struct ListNode*x=head;
        head = head->next;
        free(x);
    }
    struct ListNode*temp = head;
    while(temp!= NULL && temp->next!=NULL)
    {
        if(temp->next->val == val)
        {
        struct ListNode*nodetodelete = temp->next;
        temp->next = nodetodelete->next;
        free(nodetodelete);
        }
        else
        {
            temp=temp->next;
        }
    }
    return head;
}
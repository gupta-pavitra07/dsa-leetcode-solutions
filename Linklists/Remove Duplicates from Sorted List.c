//Problem 83
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode *temp = head;
    if(head == NULL) return head;
    while(temp->next != NULL)
    {
        if(temp->val == temp->next->val)
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
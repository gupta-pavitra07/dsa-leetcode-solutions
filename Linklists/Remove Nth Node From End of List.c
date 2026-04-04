//Problem 19
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    if(head->next == NULL)
    {
        head = NULL;
        return head;
    }
    struct ListNode*temp = head;
    int len = 0;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    if (n==len)
    {
        struct ListNode *newhead =  head->next;
        free(head);
        return newhead;
    }
    int currentpos = 1;
    temp = head;
    while(temp !=NULL && currentpos < len-n)
    {
        currentpos++;
        temp = temp->next;
    }
    struct ListNode * nodetobedeleted = temp->next;
    temp->next = nodetobedeleted->next;
    free(nodetobedeleted);
    return head;
}
//Problem 876
struct ListNode* middleNode(struct ListNode* head) 
{
    struct ListNode* temp = head;
    int n =0;
    while(temp!=NULL)
    {
        n++;
        temp = temp->next;
    }
    int currentpos = 1;
    temp =head;
    while(temp!=NULL && currentpos <= n/2)
    {
        temp =temp->next;
        currentpos++;
    }
    return temp;    
}
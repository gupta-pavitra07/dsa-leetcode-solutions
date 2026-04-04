 //Problem 2
 struct ListNode* createnode(int val)
 {
    struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->val = val;
    new->next = NULL;
    return new;
 }
 void insertatend(struct ListNode **head,int val)
 {
    struct ListNode* new = createnode(val);
    if(*head == NULL)
    {
        *head = new;
        return ;
    }
    struct ListNode*temp = *head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
 }
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;
    int n1=0 , n2=0; ;
    while(temp1!=NULL)
    {
        n1++;
        temp1 = temp1->next;
    }
    while(temp2!=NULL)
    {
        n2++;
        temp2 = temp2->next;
    }
    if(n1>n2)
    {
        int diff = n1 - n2;
        while(diff)
        {
            insertatend(&l2,0);
            diff--;
        }
    }
    if(n2>n1)
    {
        int diff = n2 - n1;
        while(diff)
        {
            insertatend(&l1,0);
            diff--;
        }
    }
    int sum;
    int carry = 0 ;
    struct ListNode * l3 = NULL;
    temp1 = l1 , temp2 = l2;
    while(temp1!=NULL && temp2!=NULL)
    {
        sum = temp1->val + temp2 ->val + carry;
        if(sum > 9) 
        {
            carry = 1 ;
            insertatend(&l3,sum-10);

        }
        else
        {
            carry = 0 ;
            insertatend(&l3,sum);
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(carry!=0)
    {
        insertatend(&l3,1);
    }
    return l3;
}
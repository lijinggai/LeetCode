/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head)
{
    //看板书
    struct Node* cur = head;
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        //让每个节点后面都有一个相同的节点  
        copy->next = cur->next;
        cur->next = copy;
        //++
        cur = copy->next;
    }
    cur = head;
    while (cur)//根据原节点，处理copy的random
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
            copy->random = NULL;
        else
            copy->random = cur->random->next;
        cur = copy->next;
    }
    struct Node* copyHead = NULL, * copyTail = NULL;
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        if (copyTail == NULL)
        {
            copyHead = copyTail = copy;
        }
        else
        {
            copyTail->next = copy;
            copyTail = copy;
        }
        cur->next = next;
        cur = next;
    }
    return copyHead;
}
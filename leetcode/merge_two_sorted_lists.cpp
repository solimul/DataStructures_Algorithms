/**
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

 

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode * h1 =l1, *h2=l2, *new_list, *new_head, *temp;
        int k=0;
        
        while(h1!=NULL && h2!=NULL) 
        {
            if(h1->val <= h2->val)
            {
                new_list=h1;
                h1=h1->next;
                new_list->next=h2;
            } 
            else
            {
                new_list=h2;
                h2=h2->next;
                new_list->next=h1;
            }
            if(k==0)
                new_head = new_list;
            k++;
        }
        if(h1==NULL)
        {
            while(h2!=NULL)
            {
                new_list=h2;
                h2=h2->next;
            }
        }
        if(h2==NULL)
        {
            while(h1!=NULL)
            {
                new_list=h1;
                h1=h1->next;
            }
        }
        if(k==0)
            new_head = new_list;
        
        return new_head;

    }
};

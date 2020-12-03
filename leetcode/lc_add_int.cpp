/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example1
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example2
Input: l1 = [0], l2 = [0]
Output: [0]

Example3
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


*/

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
 using namespace std;
 class Solution {
     ListNode * reverse(ListNode * L, int & len)
     {
         ListNode * forward=L, * current=L, *previous=NULL;
         while(current!=NULL)
         {
             forward=forward->next;
             current->next=previous;
             previous=current;
             current=forward;
             len++;
         }
         return previous;
     }
 public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         int len =0;
         ListNode *head, *current;
         l1=reverse(l1,len);
         int len_l1=len;
         len=0;
         l2=reverse(l2,len);
         int len_l2=len;
         int s=0, c=0, i=0;
         int min_len=len_l1<len_l2?len_l1:len_l2;
         while(i<=min_len)
         {
             int sum = l1->val+l2->val;
             s=sum+c>=10?0:sum+c;
             ListNode* l = new ListNode(s);
             if(i==0)   
             {
                 head=l;
                 current = head;
             }
             else
             {
                 current->next = l;
                 current=current->next;
             }
             c=sum+c>=10?1:0;
             i++;
             l1=l1->next;
             if(!l1)
                 break;
             l2=l2->next;
             if(!l2)
                 break;
                 
         }
         return head;
     }
 };
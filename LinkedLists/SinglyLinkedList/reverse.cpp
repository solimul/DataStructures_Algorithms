#include <iostream>
#include <string>

class LinkedList
{
      
    struct ListNode
    {
        int data;
        struct ListNode *next;
    };
    
    ListNode *head;
    public:
    LinkedList()
    {
        head=NULL;    
    }
    void insert_item(int data, int position);
    void delete_item(int position);
    void print_list();
    void reverse_indexed(ListNode *start_prev, ListNode* end_prev)
    {
        
        ListNode *start = start_prev->next, *end = end_prev->next;
        ListNode *previous = NULL, * current = start, *forward = start;
        //end->next=NULL;
        while(current!=NULL)
        {
            forward=forward->next;
            current->next=previous;
            previous=current;
            //std::cout<<"|"<<current->next->data;
            current=forward;
        }
        start_prev->next = previous;
        //std::cout<<"\n";
    }
    
    void reverse(int m, int n)
    {
        ListNode *p=head;
        ListNode *start, *end;
        
        int i=0, j=0;
        while(i<n)
        {
            if(i==m-1) 
                start=p;
            if(i==n-1)
                end=p;
            p=p->next;
            i++;
        }
        ListNode * temp1 = end->next->next;
        ListNode * temp2 = start->next->next;
        end->next->next = NULL;
        //start=NULL;
        reverse_indexed(start,end);
        end->next->next = temp1;
        //start->next = temp2;
    }
    
    void reverse_whole()
    {
        ListNode *current=head, *forward = head , *previous=NULL;
        while(current!=NULL)
        {
            // Traverse the whole ListNode
            // reverse the pointer direction
            forward=forward->next; // In the first call, both forward and current points to 'head' and previous points to NULL. 
                                   // if forward=forward->next is placed in the next or next to next line then forward->next (or head->next) would point to 
                                   // previous (or NULL), due to the assignment current->next=previous and the whole linked list will be broken.
            current->next=previous;
            previous=current;
            current=forward;
        }
        head=previous;
    }

};

void LinkedList::delete_item(int position)
{
    ListNode *p,*prev;
    int pos_count=1;
    p=head;
    if(position==1)
    {
        head=head->next;
        free(p);
        return;
    }
    while(pos_count<position)
    {
        pos_count++;
        prev=p;
        p=p->next;
    }
    if(p!=NULL)
    {
        prev->next=p->next;
        free(p);
    }
}

void LinkedList::print_list()
{
    std::cout<<"\n*********\n";
    ListNode *p;
    p=head;
    int i=0;
    while(p!=NULL)
    {
        std::cout<<p->data<<" ";
        p=p->next;
        if(i>6)
            break;
        i++;
    }
    std::cout<<"\n";
}

void LinkedList::insert_item(int data, int position)
{
    //print();
    int pos_counter=1;
    ListNode *p,*q, *new_node;
    new_node=new ListNode();
    new_node->data = data;
    p=head;
     
    if(position==1) // insert in the first position
    {
        new_node->next=p;
        head=new_node;
    }
    else
    { // else traverse the list to find a position.
        while (pos_counter<position)
        {
            pos_counter++;
            q=p;
            p=p->next;
        }

        q->next=new_node;
        new_node->next=p;
    }
    
}

int main()
{
  LinkedList ls; 
  ls.insert_item(5,1);
  ls.insert_item(4,2);
  ls.insert_item(3,3);
  ls.insert_item(2,4);
  ls.insert_item(1,5);
  ls.insert_item(8,6);
  ls.print_list();
  ls.reverse_whole();
  //ls.reverse(1, 4);
  //ls.delete_item(5);
  //std::cout<<"=\n";
  ls.print_list();
}


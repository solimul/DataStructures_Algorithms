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
    while(p!=NULL)
    {
        std::cout<<p->data<<"\n";
        p=p->next; 
    }
    
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
  ls.insert_item(1,2);
  
  ls.print_list();
  ls.delete_item(5);
  ls.print_list();
}


#include <iostream>
#include <string>

class DoublyLinkedList
{
      
    struct ListNode
    {
        int data;
        struct ListNode *next, *prev;
    };
    
    ListNode **head;
    public:
    DoublyLinkedList()
    {
        *head=NULL;
    }
    
    void insert_item(int data, int position);
    void delete_item(int position);
    void print_list();
};


void DoublyLinkedList::delete_item(int position)
{
    ListNode *p;
    int pos_count=1;
    p=*head;
    if(position==1)
    {
        *head=(*head)->next;
        if(*head)
            (*head)->prev=NULL;
        free(p);
        return;
    }
    while(p->next!=NULL && pos_count<position)
    {
        pos_count++;
        p=p->next;
    }
    if(p->prev)
        p->prev->next=p->next;
    if(p->next)
        p->next->prev=p->prev;
    free(p);
    return;
}

void DoublyLinkedList::print_list()
{
    std::cout<<"\n*********\n";
    ListNode *p;
    p=*head;
    while(p!=NULL)
    {
        std::cout<<p->data<<"\n";
        p=p->next; 
    }
    
}

void DoublyLinkedList::insert_item(int data, int position)
{
    //print();
    int pos_counter=1;
    ListNode *p, *new_node;
    new_node=new ListNode();
    new_node->data = data;
    p=*head;
     
    if(position==1)
    {
        new_node->next=p;
        new_node->prev=NULL;
        if(*head)
            (*head)->prev=new_node;
        *head=new_node;
        return;
    }
    else
    {
        while ((p->next!=NULL) && (pos_counter<position-1))
        {
            pos_counter++;
            p=p->next;
        }
        new_node->next=p->next;
        new_node->prev=p;
        if(p->next)
            p->next->prev=new_node;
        p->next=new_node;
    }
}

int main()
{
  DoublyLinkedList dls; 
  dls.insert_item(5,1);
  dls.insert_item(4,2);
  dls.insert_item(3,3);
  dls.insert_item(2,4);
  dls.insert_item(1,2);
  
  dls.print_list();
  dls.delete_item(2);
  dls.print_list();
}


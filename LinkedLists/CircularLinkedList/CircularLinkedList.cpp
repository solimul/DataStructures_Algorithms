#include <iostream>
#include <string>

class CircularLinkedList
{
      
    struct ListNode
    {
        int data;
        struct ListNode *next;
    };
    
    ListNode **head;
    public:
    CircularLinkedList()
    {
        *head=NULL;    
    }
    void insert_item(int data, int position);
    void delete_item(int position);
    int count_items();
    void print_list();
};

void CircularLinkedList::delete_item(int position)
{
    ListNode *current,*prev;
    int pos_count=1;
    current=*head;
    if(position==1)
    {
        do
        {
            prev=current;
            current=current->next;
        } while(current!=*head); // get the last node, so that it can point to the new head
        
        *head=(*head)->next; // new head is the next node of the current head.
        prev->next=*head; // prev node is the last node in the list, must point to the new head
        free(current);
        return;
    } 
    else
    {
        do
        {
            pos_count++;
            prev=current;
            current=current->next;
        } while(current!=*head && pos_count<position);
        if(current==*head) // deleting from the end of the list, so, the prev->next node must point to the head
            prev->next = *head;
        else // deleting from the middle of the list, so, prev->next must point to next of p. 
            prev->next=current->next;
        free(current);
        return;
    }
}

void CircularLinkedList::print_list()
{
    std::cout<<"\n*********\n";
    ListNode *p;
    p=*head;
    if(p==NULL){
        std::cout<<"**No data to print\n";    
    }
    do
    {
        std::cout<<p->data<<"\n";
        p=p->next; 
    } while(p!=*head);
    
}

void CircularLinkedList::insert_item(int data, int position)
{
    //print();
    int pos_counter=1;
    ListNode *current,*prev, *new_node;
    new_node=new ListNode();
    new_node->data = data;
    current=*head;
    if(*head == NULL) // insert in the first position
    {
        *head=new_node;
        new_node->next=*head; // first node in the list, circulrly point to itself
    }
    else
    { // else traverse the list to find a position.
        do 
        {
            pos_counter++;
            prev=current;
            current=current->next; 
        } while ((current!=*head) && (pos_counter<position));
        
        prev->next=new_node; // prev node must point to the new_node  
        new_node->next=current; // new_node must point to current
    }
    
}

int CircularLinkedList::count_items()
{
    ListNode *p;
    p=*head;
    int count=0;
    if(p==NULL)
        return count;
    do
    {
        count++;
        p=p->next;
    } while(p!=*head);
    return count;
}

int main()
{
  CircularLinkedList cls; 
  
  cls.insert_item(5,1);
  cls.insert_item(4,2);
  cls.delete_item(2);
  cls.insert_item(3,3);
  cls.insert_item(2,4);
  cls.insert_item(1,2);
  
  cls.print_list();
  cls.delete_item(3);
  cls.insert_item(4,2);
  cls.print_list();
  std::cout<<"\nNum Items: "<<cls.count_items()<<" ";
}



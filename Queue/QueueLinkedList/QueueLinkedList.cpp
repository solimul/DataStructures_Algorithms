#include <iostream>
#include <string>

class QueueLinkedList
{
    public:
        struct Element
        {
          int value;
          struct Element *next;
        };
        
        struct Element *ba;
        struct Element *front;
        QueueLinkedList()
        {
             ba=NULL;
             //std::cout<<ba;
             front=NULL;
        }
        
        bool is_full();
        bool is_empty();
        void  enqueue(int elem);
        int dequeue(); 
        void print_queue();
};


bool QueueLinkedList::is_full()
{
    return true;
}

bool QueueLinkedList::is_empty()
{
    return front==NULL;
}

void QueueLinkedList::enqueue(int elem)
{
    Element *elm = new Element();
    elm->value=elem;
    elm->next=NULL;
    if(ba!=NULL) //There is an element in the back, so the new Element should be next to current back.
        ba->next = elm;
    ba = elm; // new Element is the correct back.
    
    if(front==NULL)
    {
        front=elm;
    } 
}

int QueueLinkedList::dequeue()
{   
    if(!is_empty())
    {
        Element *temp;
        temp = front;
        int temp_val = temp->value;
        front = temp->next;
        free(temp);
        return temp_val;
    }
    else 
    {
        std::cout<<"Queue is empty!";
        return -1;
    }
}

void QueueLinkedList::print_queue()
{
  Element *current=front;
  while(current!=NULL)
  {
      std::cout<<current->value<<" ";
     current=current->next;
  }
  std::cout<<"\n";
}

int main()
{
    QueueLinkedList Queue;
    Queue.enqueue(2);
    Queue.enqueue(3);
    Queue.enqueue(4);
    Queue.enqueue(5);
    Queue.dequeue();
    Queue.dequeue();
    Queue.dequeue();
    Queue.print_queue();
    
    return 0;
}
#include <iostream>
#include <string>

class QueueCircularArray
{
    public:
        int  queue [5];
        int front, end;
        int queue_size;
   
        QueueCircularArray()
        {
            front=0;
            end=-1;
            queue_size = 5;
        }
        
        bool is_full();
        bool is_empty();
        void  enqueue(int elem);
        int dequeue(); 
        void print_queue();
};


bool QueueCircularArray::is_full()
{
    return end==queue_size-1;
}

bool QueueCircularArray::is_empty()
{
    return end == -1;
}

void QueueCircularArray::enqueue(int elem)
{
    if(!is_full())
    {
        end++;
        queue[end] = elem;        
    }
    else 
    {
        std::cout<<"Queue is full!\n";
    }
}

int QueueCircularArray::dequeue()
{   
    if(!is_empty())
    {
        int el = queue[front];
        for(int i=front;i<end;i++)
        {
            queue[i]=queue[i+1];
        }
        end--;
        return el;
        //queue[end] = elem;        
    }
    else 
    {
        std::cout<<"Queue is empty!\n";
        return -1;
    }
}

void QueueCircularArray::print_queue()
{
    std::cout<<front<<" "<<end<<"\n";
    if(is_empty())
    {
        std::cout<<"Queue is empty!";
    }
    else 
    {
        for(int i = front; i<=end;i++)
        {
            std::cout<<queue[i]<<" ";
        }
        std::cout<<"\n";
    }
}

int main()
{
    QueueCircularArray Queue;
    Queue.enqueue(2);
    Queue.enqueue(3);
    Queue.enqueue(4);
    Queue.enqueue(5);
    Queue.enqueue(6);
    Queue.enqueue(7); //should give a queue full message
    //Queue.print_queue();
    int elem = Queue.dequeue();
   
    //std::cout<<"dequeued "<<elem<<"\n";
    //Queue.print_queue();
    Queue.enqueue(7);
    Queue.print_queue(); 
    Queue.dequeue();
    Queue.dequeue();
    Queue.dequeue();
    Queue.print_queue();
    Queue.dequeue();
    Queue.dequeue(); 
    Queue.print_queue();
    Queue.dequeue(); // should give a queue empty message
    return 0;
}

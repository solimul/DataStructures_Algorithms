#include <iostream>
#include <string>

class StackStaicArray
{
    public:
        int max_size;
        int *stack;
        int num_elements;
        void take_input();
        bool is_empty();
        bool is_full();
        void push(int elem);
        int pop();
        void delete_elem();
        void print();
        void input_elems();
        void get_stack_size();
        void increase_stack_size();
        StackStaicArray()
        {
            max_size=1;
            num_elements=0;
        }
    
};




int StackStaicArray::pop()
{
    int *top; 
    top=stack+num_elements-1;
    num_elements--;
    std::cout<<(*top);
    //delete [] top; // cannot delete it as it top is an element of a static array. 
}

bool StackStaicArray::is_empty()
{
    return num_elements==0;
}

bool StackStaicArray::is_full()
{
    return num_elements>=max_size;
}

void StackStaicArray::push(int input)
{
     stack[num_elements++]=input;
}


void StackStaicArray::print()
{
    std::cout<<"\n*** Printing Stack **** "<<num_elements<<"\n";
    for(int i=0; i<num_elements;i++)
    {
        std::cout<<stack[i]<<" ";
    }
    std::cout<<"\n";
}

void StackStaicArray::increase_stack_size()
{
    int * new_stack = new int [max_size*2];
    for(int i=0; i<max_size;i++)
        new_stack[i] = stack[i];
    max_size*=2;
    delete [] stack;
    stack = new_stack;
}

void StackStaicArray::take_input()
{
    int input;
    {
        if(is_full())
        {   
            increase_stack_size();
        }
        std::cout<<"Please Enter a Positive Number. ";
        std::cin>>input;
        push(input);
    } 
}

void StackStaicArray::get_stack_size()
{
     std::cout<<"Please Enter Maximum Stack Size: ";
     std::cin>>max_size;
     stack = new int [max_size];
}

void StackStaicArray::delete_elem()
{
    if(!is_empty())
    {
        pop();
    }
    else 
    {
        std::cout<<"Stack is empty!";    
    }
}

int main()
{
    StackStaicArray ssa;   
    ssa.get_stack_size();
    ssa.take_input();
    ssa.print();
    ssa.take_input();
    ssa.print();
    ssa.take_input();
    ssa.print();
    ssa.take_input();
    ssa.print();
    ssa.take_input();
    ssa.print();
    ssa.delete_elem();
    ssa.print();
    return 0;
}




#include <iostream>
using namespace std;

class heap
{
    int * array;
    int capacity;
    int type;
    int count;

    
    int leftchild(int node_pos)
    {
        int left = 2*node_pos + 1;
        if (left>=count)
            return -1;
        return left;
    }
    
    int rightchild(int node_pos)
    {
        int right = 2*node_pos + 2;
        if (right>=count)
            return -1;
        return right;
    }
    
    int parent(int child_pos)
    {
        if(child_pos<=0 || child_pos>=count)
            return -1;
        return (child_pos-1) /2; 
    }
    
    int get_max()
    {
        if(count==0)
            return -1;
        else 
            return array[0];
    }
    
    inline int max(int a, int b)
    {
        return a>b ? a :b ;
    }
    
    void perlocate_down(int node_ind)
    {
        int left = leftchild(node_ind);
        int right = rightchild(node_ind);
        int data = array[node_ind];
        int temp, temp_index = node_ind;

        if(left!=-1 && data < array[left])
            temp_index = left;
        
        if(right!=-1 && array[temp_index]<array[right])
            temp_index=right;
        
            
        if(temp_index!=node_ind) 
        {
            temp = array[node_ind];
            array[node_ind] = array[temp_index];
            array[temp_index] = temp;
            perlocate_down(temp_index);
        }
    }
    
    void perlocate_up(int node_ind)
    {
        int temp = array[node_ind];
        int par = parent(node_ind);
        while(par!=-1 && array[node_ind] > array[par])
        {
            array[node_ind] = array[par];
            array[par] = temp;
            node_ind = par;
            par=parent(node_ind);
        }
    }
    
    
    public:
    
    
    heap(int cap, int type)
    {
        capacity=cap;
        array = new int[capacity];
        count = 0;
        type = 0;        
    }
    
    inline int elem(int i)
    {
        return array[i];        
    }
    
    inline int size()
    {
        return count;
    }
    
    void insert(int data)
    {
        if(count==capacity)
            return;
        array[++count - 1] = data;
        perlocate_up(count-1);
    }
    
    int remove_top()
    {
        int data;
        if(count==0)
            return -1;
        data = array[0];
        array[0]=array[count-1];
        count--;
        perlocate_down(0);
        return data;
    }
};

int main ()
{
    heap heap_obj(10, 0);
    heap_obj.insert(120);
    heap_obj.insert(130);
    heap_obj.insert(100);
    heap_obj.insert(110);
    heap_obj.insert(131);
    heap_obj.insert(105);
 
    int top = heap_obj.remove_top();


    for(int i=0;i<heap_obj.size();i++)
        cout<<heap_obj.elem(i)<<" ";
    return 0;
}
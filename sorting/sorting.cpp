/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class sorting
{
    void bubble()
    {
        /**
         * Bubble Sort is the simplest sorting algorithm that works by 
         * repeatedly swapping the adjacent elements if they are in wrong order.
         * Worst Case TC  O(n^2)
         * Best Case TC O(n) (if without 'swapped' flag, then O(n^2))
         * Average Case TC (Basic version, without flag, O(n^2) 
         * Worst case SC O(1)
         An Example 
         First Pass:
            ( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
            ( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
            ( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
            ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

            Second Pass:
            ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
            ( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
            ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
            ( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
            Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.

            Third Pass:
            ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
            ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
            ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
            ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
         * **/
        int swapped=1;
        for(int i=0; i< n-1 && swapped ==1  ;i++)
        {

            swapped=0;

            for(int j=0;j<n-i-1;j++)
            {
                if(data[j]>data[j+1])
                {
                    int temp = data[j+1];
                    data[j+1] = data[j];
                    data[j] = temp;
                    swapped=1;
                }
            }
        }
    }

    /**
     *  * Worst Case TC  O(n^2)
         * Average Case TC O(n^2)
         * Best Case TC O(n^2)
         * Worst case SC O(1)
    The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

        1) The subarray which is already sorted.
        2) Remaining subarray which is unsorted.

    In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
    **/
    void selection()
    {
        int min, temp;
        for(int i=0;i<n-1;i++)
        {
            min=i;
            for(int j=i+1;j<n;j++)
            {
                if(data[j]<data[min])
                    min=j;
            }
            temp = data[min];
            data[min] = data[i];
            data[i] = temp;
        }
    }
     /**
         * Every repeatation of insertion sort removes an element from the input data, and inserts it into the correct
         * position in the already sorted list, until no element left.
         * After k iterations, the first k+1 elements are sorted.
         *  _ _ _ _ _ Sorted _ _ _ _ _ _ _ _ _ _Unsorted_ _ _ _ _ _ _  
         * |    <=x      |    >x     ||     x     |    .....         |      (before processing x)
         * 
         *  _ _ _ Sorted_ _ _ _ _ _ _ _ _ _Unsorted_ _ _ _ _ _ _  
         * |    <=x     | x |  >x     |         .....           |      (after processing x)
         *  
         * * Worst Case TC  O(n^2)
         * Average Case TC O(n^2)
         * Best Case TC O(n)
         * Worst case SC O(1)
         **/
    void insertion()
    {
       int value, temp, j;
       for(int i=1; i<n;i++)
       {
           value = data[i];
           j=i;
           while(data[j-1] > value 
                && j>=1)
           {
               data[j] = data[j-1]; // if data[j-1] is greater than 'value', then put data[j-1] to data [j]
               j--;
           }
           data[j] = value; // put value in data[j]. 
                            // best case i=j (value is already greater than every element in data[0] ... data[j])
                            // Worst case j=0, every element in data[0] ... data[j] is greater than value. 
       }
    }
    
    public:
        int n;
        int *data;
        int method;
        sorting(int size, int *d)
        {
            n=size;
            data = new int [size];
            for(int i=0;i<n;i++)
                data[i] = d[i];
        }
        void sort(int mth)
        {
            method = mth;
            switch(mth)
            {
                case 0:
                    bubble();
                    break;
                case 1:
                    selection();
                    break;
                case 2:
                    insertion();
                    break;
                default:
                    break;
            }
        }
        void show_data(bool before)
        {
            switch(method)
            {
                case 0:
                    cout<<"\n*****Sorting by Bubble Sort*****\n";
                    break;
                case 1:
                    cout<<"\n*****Sorting by Selection Sort*****\n";
                    break;
                case 2:
                    cout<<"\n*****Sorting by Insertion Sort*****\n";
                    break;
                default:
                    break;
            }
            if(before) cout<<"Before Sorting: ";
            else cout<<"After Sorting: ";
            for(int i=0;i<n;i++)
                cout<<data[i]<<" ";
        }
};

int main()
{
    int data [] = {2,-1,0,5,11,3,8,-6};
    sorting s(8,data);
    s.show_data(true);
    s.sort(2);
    s.show_data(false);
    return 0;
}


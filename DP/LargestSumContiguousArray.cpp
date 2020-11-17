
#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;


class LSCA // Largest Sum Contiguous Subarray
{   
    int data [8] =   {-2, -3, 4, -1, -2, 1, 5, -3};
    int data_all_neg [8] =   {-25, -24 , -4, -2, -4, -5, -6, -3};
    public:
        int kadane() // Requires at least one positive number in the data
        {
            int max_so_far=0, sum_upto_this=0;
            int first_ind=-1, last_ind=-1;
            for(int i=0;i<8;i++)
            {
                sum_upto_this+=data[i];
                if(first_ind==-1) // Set first_ind to i, it will be reset to -1 if sum_upto_this becomes negative.
                    first_ind = i;
                if(max_so_far<sum_upto_this)
                {
                    max_so_far=sum_upto_this;
                    last_ind = i; // last index for which sum_upto_this replaces max_so_far
                }
                if(sum_upto_this<0) // whenever sum_upto_this goes below 0, restore sum_upto_this to 0 and we reset the sub-sequence.
                {
                    sum_upto_this=0;
                    first_ind = -1;
                    last_ind = -1;
                }
            }
            cout<<first_ind<<" "<<last_ind<<"\n";
            return max_so_far;
        }
        
        int lsca_all_negative() // It will essentially to find the max elemnt (hence sub-sequence is singleton) in data. 
        {
            int max_so_far=-INT_MAX, sum_upto_this=0;
            int first_ind=-1, last_ind=-1;
            for(int i=0;i<8;i++)
            {
                sum_upto_this+=data_all_neg[i];
                
                if(sum_upto_this<data_all_neg[i])
                {
                    sum_upto_this=data_all_neg[i];
                    if(max_so_far < sum_upto_this)
                        max_so_far = sum_upto_this;
                }
            }
            return max_so_far;
        }
};


int main ()
{
    LSCA lsca;
    cout<<lsca.kadane();
    return 0;
}



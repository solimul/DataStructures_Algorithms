
#include <iostream>
#include<vector>
#include<climits>
#include<string>
#include<cstring>
using namespace std;

class fibonacci
{
    int compute_fibnacci_number(int n);
    public:
        int end_point;
        fibonacci(int n)
        {
            end_point=n;
        }
};

class fibonacci_recursion:public fibonacci
{       // Divide and Conquer solution: Time complexity is O(2^n)
        int compute_fibnacci_number(int n)
        {
            if(n==0)
                return 0;
            if(n==1 || n==2)
                return 1;
            return compute_fibnacci_number(n-1) + compute_fibnacci_number(n-2);
        }
    public:
        fibonacci_recursion(int n):fibonacci(n)
        {
            
        }
        
        int compute_fib()
        {
            compute_fibnacci_number(end_point);
        }
        
};

class fibonacci_dp1:public fibonacci
{       int * arr; 
        // DP solution with memoization: Time complexity is O(n), space complexity O(n)
        int compute_fibnacci_number_bottom_up(int n)
        {
            arr[0]=arr[1] = 1;
            for(int i=2;i<end_point;i++)
                arr[i] = arr[i-1]+arr[i-2];
            return arr[end_point-1];
        }
        
        int compute_fibnacci_number_top_down(int n)
        {
            if(n==0)
                return 0;
            if(n==1 || n==2)
                return 1;
            if(arr[n] != 0)
                return arr[n];
            return arr[n] = compute_fibnacci_number_top_down(n-1) + compute_fibnacci_number_top_down(n-2);
        }
        
        // DP with smart memoization: time complexity O(n) space complexity O(1)
        int compute_fibnacci_number_constant_space(int n)
        {
            int a=0,b=1,sum;
            for(int i=1;i<n;i++)
            {
                sum=a+b;
                a=b;
                b=sum;
            }
            return sum;
        }
    public:
        fibonacci_dp1(int n):fibonacci(n)
        {
            arr= new int [end_point];
            for(int i=0;i<end_point;i++)
                arr[i]=0;
        }
        
        int compute_fib()
        {
            compute_fibnacci_number_constant_space(end_point);
        }
        
};

int main ()
{
    fibonacci_dp1 f_dp1(8);
    cout<<f_dp1.compute_fib()<<"\n";
    return 0;
}



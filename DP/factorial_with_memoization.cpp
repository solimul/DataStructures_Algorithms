
#include <iostream>
#include<vector>
#include<climits>
#include<string>
#include<cstring>
using namespace std;


class factorial
{       // Divide and Conquer solution: Time complexity is O(n)
        int *fact;
        int end_point;
        int compute_fact_non_dp(int n)
        {
            if(n==0 || n==1)
                return 1;
            return n*compute_fact_non_dp(n-1);
        }
        int compute_fact_dp(int n)
        {
            if(n==0 || n==1)
                return 1;
            if(fact[n]!=0)
                return fact[n];
            return fact[n] = n*compute_fact_non_dp(n-1);
        }
    public:
        factorial(int n)
        {
            end_point = n;
            fact = new int [n];
            for(int i=0;i<n;i++)
                fact[i]=0;
            fact[0]=fact[1]=1;
        }
        
        int compute_factorial(int type)
        {
            if(type==0) compute_fact_non_dp(end_point);
            else compute_fact_dp(end_point);
        }
        
};


int main ()
{
    factorial fact(4);
    cout<<fact.compute_factorial(1)<<"\n";
    return 0;
}



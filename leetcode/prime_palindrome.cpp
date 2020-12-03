/*Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.

 

Example 1:

Input: 6
Output: 7
Example 2:

Input: 8
Output: 11
Example 3:

Input: 13
Output: 101*/

#include <iostream>  
#include<string>  
class Solution {
    bool is_prime(int n)
    {
        for(int i=3;i<n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    bool is_palindrome(string s)
    {
        //cout<<"\n"<<s;
        int i=0, j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                break;
            else
            {
                i++;
                j--;
            }
        }
        bool ret = s.length()%2==0 ? i-j==1 : i==j; 
        
        return ret;
    }
public:
    int primePalindrome(int N) 
    {
          string s; 
          //N=20000;
          int num=N+1, prime_pal;
          while(true)
          {
              if(num%2!=0) 
              {
                  if(is_prime(num))
                  {
                     if(is_palindrome(to_string(num)))
                     {
                         prime_pal = num;
                         break;
                     }
                  }
              }
              num++;
          }
          return prime_pal;
    }
};

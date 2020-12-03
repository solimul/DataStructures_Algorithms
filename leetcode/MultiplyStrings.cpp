/*
#43
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"*/

class Solution {
public:
    string multiply(string num1, string num2) 
    {
        num1 = "123"; num2 = "456";
        int n1=0, n2=0;
        int l1=num1.length(), l2=num2.length();
        int base =10;
        for(int i=0;i<l1;i++)
        {
            n1+=((int)num1[i]-48)*(pow(10,l1-1-i)); 
        }
        for(int i=0;i<l2;i++)
            n2+=((int)num2[i]-48)*(pow(10,l1-1-i));
    
        int resInt = n1*n2;
        // string ret="";
        // int num_digits=1, div_res=resInt;
        // while(div_res>10)
        // {
        //     div_res=div_res/10;
        //     ret+= (char) r;
        //     num_digits++;
        // } 
        return to_string(n1*n2);
    }
};

/*
%7 
Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
*/

class Solution {
public:
    int reverse(int x)
    {
        string s=to_string(x), temp;
        for(int i=s.length()-1;i>=0;i--)
            temp+=s[i];
        return stoi(temp);
    }
};

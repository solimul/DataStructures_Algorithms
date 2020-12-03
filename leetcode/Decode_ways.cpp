/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with '0'. We cannot ignore a zero when we face it while decoding. So, each '0' should be part of "10" --> 'J' or "20" --> 'T'.
Example 4:

Input: s = "1"
Output: 1
*/


#include <iostream> 
#include <string> 
using namespace std;
class Solution {
public:
    int numDecodings(string s) 
    {
        //s="22613";
        int hash [26];
        for(int i=0;i<26;i++)
            hash[i]=0;
        
        int num, ways=0;
        if(s!="0")
            ways++;
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length()-1;j++)
            {
                string s1="",s2="";
                s1.append(1,s[j]);
                s2.append(1,s[j+1]);
                num=stoi(s1+s2);
                //cout<<num<<"\n";
                if(num<=26 && hash[num-1]<1)
                {
                    ways++;
                    hash[num-1]++;
                }
            }
        }
        return ways;
    }
};

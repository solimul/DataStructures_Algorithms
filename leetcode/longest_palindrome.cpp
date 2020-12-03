/**
Given a string s, return the longest palindromic substring in s.
Example:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"

**/
class Solution {
    bool check_palindrome(string s)
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
    string longestPalindrome(string s) {
        //s="cbbd";
        string subst;
        int j=0, max=-1, l;
        for(int i=0;i<s.length();i++)
        {  
            j=i;
            while(j<s.length())
            {
                int k = i==j?j+1:j;
                if(check_palindrome(s.substr(i,k)))
                {
                    l = s.substr(i,k).length();
                    //cout<<"\n"<<s.substr(i,k)<<" "<<i<<" "<<j;
                    if(max<=l) 
                    {
                        max=l;
                        subst = s.substr(i,k);
                    }
                }
                j++;
            }
        }
        cout<<subst<<"\n";
        return subst;
    }
};

/**
Given a string s, find the length of the longest substring without repeating characters.
Example: 
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
**/
class Solution {
public:
    
    int * arr;
    bool check_repeatation(string s)
    {
        set_arr();
        bool repeat=false;
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]]++;
            if(arr[s[i]]>1)
                return true;
        }
        return false;
    }
    
    Solution()
    {
        arr = new int [256];
        set_arr();
    }
    
    void set_arr()
    {
        for(int i=0;i<256;i++)
            arr[i] =0;
    }
    
    int lengthOfLongestSubstring(string s) 
    {
        string subst;
        int j=0, max=-1;
        for(int i=0;i<s.length();i++)
        {  
            j=i+1;
            while(j<s.length())
            {
                if(check_repeatation( s.substr(i,j)))
                {
                    if(max<j-i-1) {max=j-i-1; subst =s.substr(i,j-1);}
                    break;
                }
                else 
                    j++;
            }
        }
        cout<<subst<<"\n";
        return max;
    }
};
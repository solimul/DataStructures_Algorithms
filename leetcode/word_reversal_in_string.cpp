/**Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
Example 4:

Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"
Example 5:

Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"**/


class Solution {
    string rev(string s)
    {
        
        string out;
        int len=s.length();
        int k=0;
        for(int i=len-1;i>=0;i--)
            out+=s[i];
        return out;
    }
    string remLeadSpace(string s)
    {
        int end_ = s.length();
        int i=end_;
        char chr= s[end_];
        int k=0;
        while(chr==' ')
        {   
            chr=s[i--];
            k++;
        }
        cout<<s<<"|"<<end_<<" "<<k<<"\n";
        return s.substr(0,end_-k-1);
    }
public:
    string reverseWords(string s) {
        //s = "  hello world  ";
        string out_temp="",out="";
        int len=s.length();
        bool flag=false;
        int _end = len-1, i = len-1,j=0;
        while(i>=0)
        {
            if(s[i]==' ')
            {   
                if(out_temp!="") 
                    out+=rev(out_temp)+" ";      
                out_temp="";
            }
            else
                out_temp+=s[i];
            if(i==0)
                out+=rev(out_temp);
            i--;
        }
        //out = remLeadSpace(out);
        return out;
    }
};

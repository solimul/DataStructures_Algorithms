/**
242. Valid Anagram
Easy

1975

155

Add to List

Share
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
**/

class Solution {
    string sort_str(string &s)
    {
        sort(s.begin(),s.end());
        return s;
    }
public:
    bool isAnagram(string s, string t) 
    {
        s = "rat"; t = "car";
        if(s.length()!=t.length())
            return false;
        string sorted_s=sort_str(s), sorted_t=sort_str(t);
        return sorted_s==sorted_t;
    }
};

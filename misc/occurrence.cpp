/******************************************************************************

Write a program that accepts a string of letters, numbers, and spaces, and a letter, and then outputs the number of occurrences of the letter in the input string. not case sensitive.

Enter description:
Enter a string of letters, numbers and spaces on the first line, and enter a letter on the second line.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class solution
{
    public:
    int compute_occurence(string s, char c)
    {
        int hash = 0;
        int len=0;
        int i=s.length()-1;
        while(i>=0){
            if(s[i]==c)
                hash++;
            i--;
        }
        return hash;
    }
};

int main()
{
    string s="hello nowcoder";
    char c='o';
    solution sol;
   
    cout<<  sol.compute_occurence(s,c);
    return 0;
}




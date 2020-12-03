/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class solution
{
    public:
    int compute_length(string s)
    {
        int len=0;
        int i=s.length()-1;
        while(s[i]!=' '){
            len++;
            i--;
        }
        return len;
    }
};

int main()
{
    string s="Hello World";
    solution sol;
    sol.compute_length(s);
    cout<< sol.compute_length(s);
    return 0;
}





#include <iostream>
#include<vector>
#include<climits>
#include<string>
#include<cstring>
using namespace std;

class string_matching
{
    
    char * get_input(int type)
    {
        #define CHUNK 5
        int index=0, size=0;
        char ch;
        char * str = new char [CHUNK];
        char * tmp = NULL;
        switch(type)
        {
            case 0:
                cout<<"Enter the input string: ";
                break;
            case 1:
                cout<<"Enter the substring to find: ";
                break;
            default:
                break;
        }
        while(true)
        {
            ch=getc(stdin);
            if(ch=='\n')
                break;
            if(size<=index)
            {
                size+=CHUNK;
                tmp = new char [size];
                tmp=str;
                str = tmp;
                tmp=NULL;
            }
            if(ch!='\n')
                str[index++]=ch;
        }
        return str; 
    }
    
    
    public:
    
    char * str;
    char * pattern;
    string_matching()
    {
        str = get_input(0);
        pattern = get_input(1);
    }
    
    int find_pattern_brute()
    {
        int res = -1;
        int n = strlen(str);
        int m = strlen(pattern);
        int j=0;
        for(int i=0; i<= n-m; i++)
        {
            j=0;
            while(j<m)
            {
                if(pattern[j] == str[i+j])
                {                    
                    j++;
                    continue;
                }
                else 
                    break;
                
            }
            if(j==m)
                return i;
        }
        return res;
    }
    
    
};

int main ()
{
    string_matching strm;
    int starting_of_pattern = strm.find_pattern_brute();
    if(starting_of_pattern>-1)
        cout<<strm.pattern<<" is found in "<<strm.str<<" that starts at "<<starting_of_pattern<<"\n";
    else 
        cout<<strm.pattern<<" is not found in "<<strm.str<<"\n";
    return 0;
    
}



#include <iostream>
#include<vector>
#include<climits>
#include<string>
#include<cstring>
using namespace std;

class hash_table
{
    public:
    int * ht;
    string str;
    
    hash_table()
    {
        ht = new int[256];
        for(int i=0;i<256;i++)
            ht[i]=0;
    }
    
    int remove_duplicate()
    {
        int m=0;
        int len = str.length();
        for(int i=0;i<len;i++)
        {
            if(ht[str[i]]<1)
                str[m++] = str[i];
            else
                str[m++]='\0';
            ht[str[i]]++;
        }
    }
    
    
    
};

int main ()
{
    hash_table tab;
    cin>>tab.str;
    tab.remove_duplicate();
    cout<<"\n"<<tab.str;
    return 0;
}


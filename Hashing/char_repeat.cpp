
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
    
    int detect_repeatation()
    {
        
        for(int i=0;i<str.length();i++)
        {
            if(ht[str[i]]==1)
                return str[i];        
            else 
                ht[str[i]]++;    
        }
        return -1;
    }
    
    
    
};

int main ()
{
    hash_table tab;
    cin>>tab.str;
    int repeat = tab.detect_repeatation();
    if(repeat==-1)
        cout<<"No Repeatation!\n";
    else 
        cout<<(char) repeat<<" is repeated!\n";
    return 0;
}


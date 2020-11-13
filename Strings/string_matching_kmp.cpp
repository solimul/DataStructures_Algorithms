
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
    int str_len, pattern_len;
    string_matching()
    {
        str = get_input(0);
        pattern = get_input(1);
        str_len = strlen(str);
        pattern_len = strlen(pattern);
    }
    
    int find_pattern();
    
    void print_results(int res)
    {
        if(res>-1)
            cout<<pattern<<" is found in "<<str<<" that starts at position "<<res<<"\n";
        else 
            cout<<pattern<<" is not found in "<<str<<"\n";
    }
    
};

class brute:public string_matching
{
    int find_pattern()
    {
        int j=0;
        for(int i=0; i<= str_len-pattern_len; i++)
        {
            j=0;
            while(j<pattern_len)
            {
                if(pattern[j] == str[i+j])
                {                    
                    j++;
                    continue;
                }
                else 
                    break;
                
            }
            if(j==pattern_len)
                return i;
        }
        return -1;
    }
    public: 
    brute():string_matching()
    {
        cout<<"\n*****Using Brute Force to find a substrig *****\n";
    }
    
    void report_pattern_match()
    {
        print_results(find_pattern());
    }
    
};

class rabin_karp:public string_matching
{
    
    int sub_string_hash;
    int pattern_hash;
    char * sub_str_data;
    int compute_substr_hash(int start)
    {
        if(sub_str_data!=NULL)
            delete [] sub_str_data;
        
        sub_str_data = new char [pattern_len];
        
        int h=0;
        for(int i=start; i<pattern_len+start;i++)             
        {
            sub_str_data[i-start] = str[i];
            h += 10*str[i];
        }
        sub_string_hash = h;
    }
    
    void compute_pattern_hash()
    {
        int h=0;
        for(int i=0;i<pattern_len;i++)
            h+= pattern[i]*10;
        pattern_hash = h;
        //cout<<pattern_hash<<" "<<h<<" aaaa\n";
    }

    int find_pattern()
    {
        for(int i=0; i<=str_len-pattern_len; i++)
        {
            compute_substr_hash(i);
            cout<<i<<" "<<pattern_hash<<" "<<sub_string_hash<<"\n";
            if(pattern_hash == sub_string_hash)
            {
                if(strcmp(pattern,sub_str_data)==0)
                    return i;
            } 
        }
        return -1;
    }    
    
    public:
    
    rabin_karp():string_matching()
    {
        cout<<"\n*****Using Rabin Carp to find a substrig *****\n";
        sub_str_data = NULL;
        compute_pattern_hash();
    }
    
    void report_pattern_match()
    {
        print_results(find_pattern());
    }
};

class kmp:public string_matching
{
    // longest proper prefix which is also suffix.. 
    // A proper prefix is prefix with whole string not allowed. 
    // For example, prefixes of “ABC” are “”, “A”, “AB” and “ABC”. 
    // Proper prefixes are “”, “A” and “AB”. Suffixes of the string are “”, “C”, “BC” and “ABC”.
    int * lps;
    void construct_lps()
    {
        lps[0]=0;
        int head1=0, head2=1;
        for(head2=1;head2<pattern_len; )
        {
            if(pattern[head1]==pattern[head2])
            {
                lps[head2] = head1+1; 
                head2++;
                head1++;                
            } 
            else if(head1>0)
            {
                head1 = lps[head1-1];
            }
            else
            {
                lps[head2] = 0;
                head2++;
            }
        }
    }
    
        
    int find_pattern()
    {
        int j=0;
        for(int i=0;i<str_len;)
        {
            if(str[i]==pattern[j])
            {
                i++;
                j++;
            }
            if(j==pattern_len)
                return i-pattern_len;
            else if(i<str_len && pattern[j]!=str[i])
            {
                if(j>0)
                    j=lps[j-1];
                else
                   i++;    
            }
        }
        return -1;
    }
    
    
    public:
    kmp():string_matching()
    {
        cout<<"\n*****Using KMP to find a substrig *****\n";
        lps = new int [pattern_len];
        construct_lps();
    }

    
    void report_pattern_match()
    {
        print_results(find_pattern());
    }    
    
};

/*void computeLPSArray(char* pat, int M) 
{ 
    int * lps = new int[M];
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    }
    for(int i=0;i<M;i++)
            cout<<" "<<lps[i];
}*/

int main ()
{
    kmp kmp_obj;
    kmp_obj.report_pattern_match();
   
    
    return 0;
}


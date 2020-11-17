
#include <iostream>
#include<vector>
#include<cstring>
using namespace std;


class LCS
{   
    int CHUNK=20;
    char * str1;
    char * str2;
    vector<char> lcs_str;
    int str1_len, str2_len;
    

    char* get_string(int str_id)
    {        
        #define CHUNK 5
        int index=0, size=0;
        char ch;
        char * str = new char [CHUNK];
        char * tmp = NULL;
        const char *i = str_id==0? " first ": " second ";
        cout<< "Enter the"<< i <<"string: "<<"\n";
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
        int len = strlen(str);
        if(str_id)
        {
            str2 = new char [len];
            str2 = str;
            str2_len = len;
        }
        else 
        {
            str1 = new char [len];
            str1 = str;
            str1_len = len;
        }
    }
    inline int max(int a, int b)
    {
        return a>b?a:b;
    }
    
    public:
    void get_input()
    {
        get_string(0);
        get_string(1);
    }
    
    
    /**
     lcs("AXYT", "AYZX")
                       /                \ 
         lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
         /                              /               
    lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")

        ############# lcs("AXY", "AYZ")  is called twice ################## ---> results in many subprolbems being solved many times.
        WC Time complexity O(2*n), the last return statement being called in each recursive call, if no two character matches in the gvien two strings. 
        
     */
    int LCS_recurse(char * strA, int m, char * strB, int n)
    {
        if(m==0 || n==0)
            return 0;
        if(strA[m]==strB[n])
        {
            lcs_str.push_back(strA[m]);
            return 1 + LCS_recurse(strA,m-1,strB,n-1);
        }
        else
            return max(LCS_recurse(strA,m,strB,n-1), LCS_recurse(strA,m-1,strB,n));
    }
    
    int LCS_DP(char * strA, int m, char * strB, int n)
    {
        int lcs_memory [m+1][n+1];   
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    lcs_memory[i][j] = 0;
                else if (strA[i-1]==strB[j-1])
                    lcs_memory[i][j]=lcs_memory[i-1][j-1]+1;
                else
                    lcs_memory[i][j] = max(lcs_memory[i][j-1],lcs_memory[i-1][j]); 
            }
        }
        //return 0;
        // for(int i=0;i<=m;i++)
        // {   
        //     cout<<"\n";
        //     for(int j=0;j<=n;j++)
        //     {
        //         cout<<lcs_memory[i][j]<<" ";
        //         if(i>0 && j>0 && lcs_memory[i][j]>lcs_memory[i][j-1])
        //             lcs_str.push_back(strB[j-1]);
        //     }
        // }
         return lcs_memory[m][n];
    }
    
    int compute_LCS(int method)
    {
        if(!method)
           return LCS_recurse(str1,str1_len,str2,str1_len);
        else
            return LCS_DP(str1,str1_len,str2,str2_len);
    }
    
    void show_lcs(int method)
    {
        //compute_LCS(method);
        cout<<"LCS len : "<<compute_LCS(method);
        cout<<"\n";
        for(int i=0;i<lcs_str.size();i++)
        {
            cout<<lcs_str[i]<<" ";
        }
    }
};


int main ()
{
    LCS lcs;
    lcs.get_input();
    lcs.show_lcs(1);
    return 0;
}



/**
221. Maximal Square
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
**/


class Solution {
    int max(int a, int b)
    {       
        return a> b ?a:b;
    }
     int min(int a, int b)
    {
        return a < b ?a:b;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int dim=-1;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]=='1')
                {
                    if(i==0 || j==0)
                        matrix[i][j]='1';
                    else
                    {
                        int a = min((int)matrix[i-1][j]-48,(int)matrix[i][j-1]-48);
                        int b = min(a,(int) matrix[i-1][j-1] - 48);
                       
                        matrix[i][j] = (char)(1 + b + 48 );
                    }
                }
                dim = max((int) matrix[i][j]-48, dim);
            }
        return dim*dim;
    }
};

/*
#1191 Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: arr = [1,2], k = 3
Output: 9
Example 2:

Input: arr = [1,-2,1], k = 5
Output: 2
Example 3:

Input: arr = [-1,-2], k = 7
Output: 0
 

Constraints:

1 <= arr.length <= 10^5
1 <= k <= 10^5
-10^4 <= arr[i] <= 10^4
*/

class Solution {
    int kadane(vector<int>& data) // Requires at least one positive number in the data
        {
            int max_so_far=0, sum_upto_this=0;
            int first_ind=-1, last_ind=-1;
            for(int i=0;i<data.size();i++)
            {
                sum_upto_this+=data[i];
                if(first_ind==-1) // Set first_ind to i, it will be reset to -1 if sum_upto_this becomes negative.
                    first_ind = i;
                if(max_so_far<sum_upto_this)
                {
                    max_so_far=sum_upto_this;
                    last_ind = i; // last index for which sum_upto_this replaces max_so_far
                }
                if(sum_upto_this<0) // whenever sum_upto_this goes below 0, restore sum_upto_this to 0 and we reset the sub-sequence.
                {
                    sum_upto_this=0;
                    first_ind = -1;
                    last_ind = -1;
                }
            }
            //cout<<first_ind<<" "<<last_ind<<"\n";
            return max_so_far;
        }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) 
    {
        vector<int> temp;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<arr.size();j++)
                temp.push_back(arr[j]);
            
        }
        return kadane(temp);
    }
};

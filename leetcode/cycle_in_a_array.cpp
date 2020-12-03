/**#457 You are given a circular array nums of positive and negative integers. If a number k at an index is positive, then move forward k steps. Conversely, if it's negative (-k), move backward k steps. Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.

Determine if there is a loop (or a cycle) in nums. A cycle must start and end at the same index and the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements.

 

Example 1:

Input: [2,-1,1,2,2]
Output: true
Explanation: There is a cycle, from index 0 -> 2 -> 3 -> 0. The cycle's length is 3.
Example 2:

Input: [-1,2]
Output: false
Explanation: The movement from index 1 -> 1 -> 1 ... is not a cycle, because the cycle's length is 1. By definition the cycle's length must be greater than 1.
Example 3:

Input: [-2,1,-1,-2,-2]
Output: false
Explanation: The movement from index 1 -> 2 -> 1 -> ... is not a cycle, because movement from index 1 -> 2 is a forward movement, but movement from index 2 -> 1 is a backward movement. All movements in a cycle must follow a single direction.
**/

class Solution {
    int forward(int ind, int num, int sz)
    {
        ind=ind+num;
        if(ind>sz)
            ind = ind%(sz+1);
        return ind;
    }
    
   int backward(int ind, int num, int sz)
   { 
       ind=ind+num;
       if(ind<0)
          ind=(sz+1)+ind;
       return ind;
   }   
public:
    bool circularArrayLoop(vector<int>& nums) 
    {
        int ind=0, start=-1, step;
        int sz=nums.size()-1;
        bool has_cycle=false;
        int len,k;

        for(int i=0;i<=sz;i++)
        {
            if(has_cycle)
                break;
            if(start==-1) // new starting point. either i=0 or the previous parth with starting point changed direction
                start=i;
            ind=i;
            k=0;
            len=0;
            while(true)
            {
                k++;
                if(nums[ind]>=0) // forward direction move
                {
                    ind=forward(ind,nums[ind],sz);
                    if(nums[ind]<0) // previous direction was forward, but now need to go backward, so no cycle, break the current search for cycle
                    {
                        start=-1;
                        break;
                    }
                }
                else
                {
                      ind = backward(ind,nums[ind],sz);  // forward direction move
                      if(nums[ind]>0)  // previous direction was backward, but now need to go forward, so no cycle in current path, break the current search for cycle
                      {
                         start=-1;
                         break;
                     }
                 }
                
                if(start==ind) // if start==ind that the traversal leads us to a cycle of length >=1.
                {
                    has_cycle=true;
                    break;
                }
                
                if(k>sz) // if more than the length of the array is already traversed in the current path, then no cycle exists in the current path, just break
                {
                    has_cycle=false;
                    break;
                }
                len++; // track the length of the path
            }
         }
         
        return has_cycle? len>1?has_cycle:false: false; // a cycle must be of length > 1
    }
};

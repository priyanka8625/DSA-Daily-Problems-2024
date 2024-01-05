
// any number >1 can be divisible by 3 .
// If not then you only need 1 extra operation .
// *********************
// Hint explained- 
// Rem = Num%3
// Remainder can be either 1 or 2.

// If rem= 1 then u need to break 1 operation of 3 and make the available number to be completed in (2 operations of 2) eventually 1 extra operation.


// If rem=2 ,
// Then you can easily take 1 extra operation of taking 2 elements. 

// Hence , finally you only need  1 extra operation,
//  If num%3 !=0
// Otherwise directly count operations by num/3.

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto a: nums){
            mp[a]++;
        }

        int count=0;
        for(auto a: mp){
            int t = a.second;
            if(t==1)return -1;
            count += t/3;
            if(t%3)count++;
        }
        return count;
    }
};



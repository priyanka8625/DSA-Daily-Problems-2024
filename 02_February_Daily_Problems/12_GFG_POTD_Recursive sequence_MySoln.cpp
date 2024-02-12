class Solution{
public:
    long long sequence(int n){
        // code here
        long long ans=0, index=1;
        ans = generate(ans, 1, index, n);
        return ans;
    }
    long long generate(long long ans, long long currDigit, int index, int &n){
        if(index > n)
            return ans;
        
        long long mul=1; 
        long long i=currDigit;
        for(; i < currDigit+index; i++){
            mul = (mul*i)%1000000007;
        }
        //now we have mul qhich has multiplication value of index no. of eles starting from currDigit
        //ex: for index=1, mul=1... for index=2, mul=2*3=6 which is F(2*3), and so on...
        
        //caculate mul for next index no of elements starting from i 
        //i.e. for index=1, i=1, for index=2, i=4 after loop, so pass the same for next call of index=3
        ans = (mul + generate(ans, i, index+1, n))%1000000007;
        return ans;
    }
};
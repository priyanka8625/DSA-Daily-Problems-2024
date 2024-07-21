class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long int product = 0;
        int mod = 1e9+7;
        vector<int> neg;
        for(int i:arr){
            if(i<0){
                neg.push_back(i);
            }else if(i>0){
                if(product==0) product = 1;
                product = (product*i)%mod;
            }
        }
        sort(neg.begin(), neg.end());
        if(neg.size()>1){
            if(product==0) product=1;
            for(int i=1; i<neg.size(); i+=2){
                product = (product*(neg[i]*neg[i-1]))%mod;
            }
        }
        return product;
    }
};
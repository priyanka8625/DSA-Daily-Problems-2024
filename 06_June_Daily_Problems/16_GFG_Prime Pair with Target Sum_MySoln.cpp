class Solution {
  public:
    bool isPrime(int num){
        if(num<2)
            return false;
        
        for(int i=2; i<=sqrt(num); i++){
            if(num%i == 0)
                return false;
        }
        return true;
    }
    vector<int> getPrimes(int n) {
        // code here
        vector<int> ans;
        for(int i=2; i<=(n/2); i++){
            if(isPrime(i) && isPrime(n-i)){
                ans.push_back(i);
                ans.push_back(n-i);
                return ans;
            }
        }
        return {-1, -1};
    }
};
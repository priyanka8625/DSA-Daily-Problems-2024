
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        unordered_map<int,int>mp;
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++){
            sum1=sum1+a[i];
        }
        
        for(int i=0;i<m;i++){
            sum2=sum2+b[i];
            mp[b[i]] = i;
        }
        int total=sum1+sum2;
        if(total%2==1){
            return -1;
        }
    
        int diff=(total/2)-sum1;
       
        for(int i=0;i<n;i++){
            int x=a[i];
            int dev=x+diff;
            auto it = mp.find(dev);
            if (it != mp.end()) {
                return 1;
            } 
     
        }
        return -1;  
    }
};

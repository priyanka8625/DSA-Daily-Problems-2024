//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool compare(Item a,Item b){
        double f1=(double) a.value/a.weight;
        double f2=(double) b.value/b.weight;
        return f1>f2;
    }
    
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // code here
        sort(arr,arr+n,compare);
        double ans=0;
        for(int i=0;i<n;i++){
            int val=arr[i].value;
            int wei=arr[i].weight;
            if(wei<w){
                ans+=(double)val;
                w-=wei;
            }
            else{
                ans+=(double)  val/wei *w;
                w=0;
                break;
            }
        }
        
        
        return ans;
        
    }
        
};
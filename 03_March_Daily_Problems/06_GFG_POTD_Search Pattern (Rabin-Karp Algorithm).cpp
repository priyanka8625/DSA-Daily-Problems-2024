class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            int m=pattern.size(),n=text.size();
            int i=0,j=0;
            vector<int>ans;
            while(j<n)
            {
                if(j-i+1<m)
                {
                    j++;
                }
                else
                {
                    
                string temp=text.substr(i,j-i+1);
                if(temp==pattern)
                {
                    ans.push_back(i+1);
                }
                i++;
                j++;
                
                }
            }
            return ans;
        }
     
};
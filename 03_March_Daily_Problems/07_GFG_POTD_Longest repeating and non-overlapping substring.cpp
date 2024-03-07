class Solution {
  public:
     string longestSubstring(string s, int n) {
        // code here
        int window_size=1;
        string sub_str="";
        string result;
        
        for(int i=0;i<n;i++){
            while(sub_str.length()!=window_size){
                sub_str+=s[i];
            }
            
            size_t found=s.find(sub_str,i+1);
            if(found != string::npos){
                window_size++;
                result=sub_str;
            }
            
            else{
                sub_str.erase(0,1);
            }
        }
        
        if(result.length()==0) return "-1";
        return result;
    }
};
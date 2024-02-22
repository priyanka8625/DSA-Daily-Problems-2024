//gives tle for large inputs but gives proper result

class Solution
{
    public:
    void generate(string &s, string &t, string &temp, int &count, int index, int &n, int &m){
        if(temp.size() == m){
            if(temp == t)
                count++;
            return;
        }
        if(index == n)
            return;
        
        //include current char in string temp
        temp.push_back(s[index]);
        generate(s, t, temp, count, index+1, n, m);
        //not include char in temp
        temp.pop_back();
        generate(s, t, temp, count, index+1, n, m);
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
      string temp="";
      int count=0, n=s.length(), m=t.length(), index=0;
      generate(s, t, temp, count, index, n, m);
      return count;
    }
    
};
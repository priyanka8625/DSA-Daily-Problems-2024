class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0, j=0, n1=version1.length(), n2=version2.length();
        while(i<n1 || j<n2){
            //find the revisions
            int revision1=0, revision2=0;
            while(i<n1 && version1[i]!='.'){
                revision1 = revision1*10 + (version1[i]-'0');
                i++;
            }
            while(j<n2 && version2[j]!='.'){
                revision2 = revision2*10 + (version2[j]-'0');
                j++;
            }
            //compare revisions
            if(revision1<revision2)
                return -1;
            else if(revision1>revision2)
                return 1;
            //if none of the above condn is true, continue the loop
            i++;
            j++;
        }
        
        return 0;//if any of the odd conditions in above loops don't match
    }
};
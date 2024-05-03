class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0, j=0, n1=version1.length(), n2=version2.length();
        while(i<n1 && j<n2){
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
        //check if any version still has the revisions to be compared 
        while(i<n1){
            if(version1[i]!='.' && (version1[i]-'0')>0)
                return 1;
            i++;
            //can't check the condn for <0 becuase -ve nos are not present in revisions
            //and unless we have [i]==0, it means both the numbers are still the same
        }
        while(j<n2){
            if(version2[j]!='.' && (version2[j]-'0')>0)
                return -1;//as revision2 will be greater than revision1 in this case
            j++;
        }
        return 0;//if any of the odd conditions in above loops don't match
    }
};
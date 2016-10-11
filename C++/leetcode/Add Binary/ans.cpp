class Solution {
public:
    string addBinary(string a, string b) {
        int A[1010],B[1010],C[1010];
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        memset(C,0,sizeof(C));
        int i,la=a.size(),lb=b.size(),lc=max(la,lb);
        for(i=1;i<=la;i++) A[i]=a[la-i]-'0';
        for(i=1;i<=lb;i++) B[i]=b[lb-i]-'0';
        for(i=1;i<=lc;i++) {
            C[i]+=A[i]+B[i];
            C[i+1]+=C[i]/2;
            C[i]%=2;
        }
        if(C[lc+1]>0) lc++;
        string c="";
        for(i=lc;i>=1;i--) c+=C[i]+'0';
        return c;
    }
};
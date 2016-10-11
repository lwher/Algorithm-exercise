	#include<iostream>
	#include<cmath>
	#include<cstring>
	using namespace std; 
	int a[101][101],n,sum[101],now,ans=-1000000;
	void doing ()
	{
	     int temp=0;
	     now=-100000000;
	     for (int i=1;i<=n;i++)
	     {
	         if (temp>0)
	           temp+=sum[i];
	         else
	           temp=sum[i];
	         if (temp>now)
	           now=temp;
	     }
	}
	int main ()
	{
	    int i,j,k;
	    cin>>n;
	    for (i=1;i<=n;i++)
	      for (j=1;j<=n;j++)
	        cin>>a[i][j];
	    for(i=1;i<=n;i++)
	    {
	        memset(sum,0,sizeof(sum));
	        for(j=i;j<=n;j++)
	        {
	            for(k=1;k<=n;k++)
	                sum[k]+=a[j][k];
	            doing ();
	            if (now>ans)
	                ans=now;
	        }
	    }
	    
	    /*
	    for (i=1;i<=n;i++)
	      cin>>sum[i];
	    doing ();
	    ans=now;
	    */
	    cout<<ans<<endl;
	    //system ("pause");
	    return 0;
	}

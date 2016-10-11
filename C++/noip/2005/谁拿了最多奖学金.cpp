#include<stdlib.h> 
  
#include<stdio.h> 
  
int main(){ 
  
       int n,i,j,s,t,a,b,c,k,g,kk; 
  
       char d,e,na[256],nn[256]; 
  
       scanf("%d",&n); 
  
       s=0;t=0; 
  
       for(i=1;i<=n;i++){ 
  
              scanf("%c",&d); 
  
              k=0; 
  
              while(d!=' '){ 
  
                     k++; 
  
                     na[k]=d; 
  
                     scanf("%c",&d); 
  
              }; 
  
              scanf("%d %d",&a,&b); 
  
              scanf("%c",&d); 
  
              while(d==' ')scanf("%c",&d); 
  
              scanf("%c",&e); 
  
              while(e==' ')scanf("%c",&e); 
  
              scanf("%d",&c); 
  
              g=0; 
  
              if(a>80&&c>=1)g+=8000; 
  
              if(a>85&&b>80)g+=4000; 
  
              if(a>90)g+=2000; 
  
              if(a>85&&e=='Y')g+=1000; 
  
              if(b>80&&d=='Y')g+=850; 
  
              if(g>t){ 
  
                     t=g; 
  
                     kk=k; 
  
                     for(j=1;j<=kk;j++)nn[j]=na[j]; 
  
              } 
  
              s+=g; 
  
       } 
  
       for(i=1;i<=kk;i++)if((nn[i]>='a'&&nn[i]<='z')||(nn[i]>='A'&&nn[i]<='Z'))printf("%c",nn[i]);printf("\n"); 
  
       printf("%d\n",t); 
  
       printf("%d\n",s); 
  
       return 0; 
  
} 
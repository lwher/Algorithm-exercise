#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct sth
{
   int red,x,y,age,level,lastx,lasty,redsx,bh; 
   bool live,have;
}ant[7];
int D,s,r,tx[21],ty[21]; // tower
int T,n,m,sum,now,xxs[9][9];// sum:目前地图上的蚂蚁数  now:已经出生的蚂蚁数 
bool mark[9][9],target;
int dx[8]={0,1,0,-1,0,1,0,-1};
int dy[8]={1,0,-1,0,1,0,-1,0};
inline bool comp(sth a,sth b)
{
       return a.age>b.age;
}
void addant()
{
    int i,j;double k=1;
    for(i=1;i<=6;i++)  if(ant[i].live && ant[i].x==0 && ant[i].y==0)  return;
    sum++;now++;
    for(i=1;i<=6;i++)  if(!ant[i].live)  break;
    ant[i].bh=now;ant[i].have=0;
    ant[i].live=1;ant[i].age=0;ant[i].level=(now-1)/6+1;
    for(j=1;j<=ant[i].level;j++)  k*=1.1; k*=4;
    ant[i].red=int(k);ant[i].redsx=ant[i].red;ant[i].x=0;ant[i].y=0;ant[i].lastx=0;ant[i].lasty=0;
}
void losenews()
{
    for(int i=1;i<=6;i++)  if(ant[i].live)   
    {
        if(ant[i].have)  xxs[ant[i].x][ant[i].y]+=5;
        else  xxs[ant[i].x][ant[i].y]+=2;
    }
}
bool ok(int i,int x,int y)
{
     if(x<0 || x>n || y<0 || y>m || mark[x][y])  return 0;
     if(x==ant[i].lastx && y==ant[i].lasty) return 0;
     for(int j=1;j<=6;j++)  if(j!=i && ant[j].live && ant[j].x==x && ant[j].y==y)  return 0;
     return 1;
}
void moveto(int i,int k)
{
     ant[i].lastx=ant[i].x;ant[i].lasty=ant[i].y;
     ant[i].x+=dx[k];ant[i].y+=dy[k];
}
void move()
{
    int i,k,p,maxx,gs,id,nx,ny;
    sort(ant+1,ant+1+6,comp);
    for(i=1;i<=6;i++)
    if(ant[i].live)
    {
        gs=0;id=-1;maxx=-INF;
        for(k=0;k<4;k++)
        {
           nx=ant[i].x+dx[k];ny=ant[i].y+dy[k];
           if(!ok(i,nx,ny))  continue;
           if(xxs[nx][ny]>maxx)
           {
               gs=1;id=k;maxx=xxs[nx][ny];
           }
           else  if(xxs[nx][ny]==maxx)  gs++;
        }
        if(id==-1)  {ant[i].lastx=ant[i].x;ant[i].lasty=ant[i].y;continue;}
        if(gs==1)   k=id;
        else  for(k=0;k<4;k++)
        {
           nx=ant[i].x+dx[k];ny=ant[i].y+dy[k];
           if(!ok(i,nx,ny))  continue;
           if(xxs[nx][ny]==maxx)  break;
        }
        p=k;
        if((ant[i].age+1)%5==0)
        {
            p+=4;
            for(k=p-1;k>=p-4;k--)
            {
                nx=ant[i].x+dx[k];ny=ant[i].y+dy[k];
                if(ok(i,nx,ny))  break;
            }
            p=k;
        }
        moveto(i,p);
    }
}
void checktar()
{
     if(target)  return;
     for(int i=1;i<=6;i++)  if(ant[i].live && ant[i].x==n && ant[i].y==m)  
     {
         target=1;ant[i].have=1;
         ant[i].red+=ant[i].redsx/2;
         ant[i].red=min(ant[i].red,ant[i].redsx);
         break;
     }
}
int dist(int a,int b)// a:tower  b:ant
{
     return (ant[b].x-tx[a])*(ant[b].x-tx[a])+(ant[b].y-ty[a])*(ant[b].y-ty[a]);
}
void putdown(int a,int b)// a:tower b:ant
{
     int i;double d=sqrt(dist(a,b)),h,ax,ay,bx,by;
     for(i=1;i<=6;i++)
     if(ant[i].live && i!=b)
     {
         ax=ant[i].x-tx[a];ay=ant[i].y-ty[a];
         bx=ant[b].x-tx[a];by=ant[b].y-ty[a];
         h=ax*by-ay*bx;
         h/=d;
         if(h<0)  h=-h;
         if(h<0.5+0.00001)
         {
              if(ant[i].x>=min(ant[b].x,tx[a]) && ant[i].x<=max(ant[b].x,tx[a]))
              if(ant[i].y>=min(ant[b].y,ty[a]) && ant[i].y<=max(ant[b].y,ty[a]))
              {
                   ant[i].red-=D;
              }
         }
     }
     ant[b].red-=D;
}
void attack()
{
     int i,minn,id,j,d;
     for(i=1;i<=s;i++)
     {
         minn=INF;id=0;
         for(j=1;j<=6;j++)
         if(ant[j].live)
         {
              d=dist(i,j);
              if(d<=r)
              {
                  if(ant[j].have)  {minn=0;id=j;break;}
                  if(d<minn)  {minn=d;id=j;}  else
                  if(d==minn && ant[id].age<ant[j].age)  id=j;
              }   
         }
         if(id)  putdown(i,id);
     }
     for(i=1;i<=6;i++)  if(ant[i].live && ant[i].red<0) 
     {
         ant[i].live=0;sum--;
         if(ant[i].have)  target=0;
     }
}
bool checkend()
{
     if(!target)  return 0;
     for(int i=1;i<=6;i++)  if(ant[i].live && ant[i].have && ant[i].x==0 && ant[i].y==0)  return 1;
     return 0;
}
void addage()
{
     int i,j;
     for(i=1;i<=6;i++)  if(ant[i].live)  ant[i].age++;
     for(i=0;i<=n;i++)  for(j=0;j<=m;j++)  if(xxs[i][j]>0)  xxs[i][j]--;
}
int main()
{
    //freopen("ant.in","r",stdin);
    //freopen("ant.out","w",stdout);
    int i;
    scanf("%d%d",&n,&m);
    scanf("%d%d%d",&s,&D,&r);
    for(i=1;i<=s;i++)  
    {
       scanf("%d%d",&tx[i],&ty[i]);
       mark[tx[i]][ty[i]]=1;
    }
    scanf("%d",&T);
    int nt=1;r*=r;      
    while(nt<=T)
    {
        if(sum<6)  addant();
        losenews();
        move();
        checktar();
        attack();
        if(checkend())  break;
        addage();
        nt++;
    }
    if(nt==T+1) printf("The game is going on\n");
    else  printf("Game over after %d seconds\n",nt);
    sort(ant+1,ant+1+6,comp);
    printf("%d\n",sum);
    for(i=1;i<=6;i++)  if(ant[i].live)  printf("%d %d %d %d %d\n",ant[i].age,ant[i].level,ant[i].red,ant[i].x,ant[i].y);
//  system("pause");
    return 0;
}
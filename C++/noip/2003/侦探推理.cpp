#include <stdio.h>
#include <string.h>
int m,n,p,fpcnt = 0,haswi[51] = {0},hasd[51] = {0};
short fp[51] = {0},wrong[51] = {0},who[51][51] = {0},day[51][8] = {0},not[51] = {0},notd[8] = {0},imp = 0,avai[51] = {0};
char list[51][251] = {0};
char myg[13] = "I am guilty.",myng[17] = "I am not guilty.",xxg[12] = " is guilty.",xxng[16] = " is not guilty.",today[10] = "Today is ";
char dayList[8][11] = {"orzzgg","Monday.","Tuesday.","Wednesday.","Thursday.","Friday.","Saturday.","Sunday."};
int hash(char *s)
{
    int i,h = 0,len;
    len = strlen(s);
    for(i=0;i<len;i++) h = (h*10+(int)s[i])%50+1;
    while(strcmp(s,list[h])!=0&&list[h][0])
    {
        h++;
        if(h>50) h = 1;
    }
    if(!list[h][0]) strcpy(list[h],s);
    return h;
}
void fart(int id)
{
    if(!fp[id])
    {
        fp[id] = 1;
        fpcnt++;
    }
}
void work(int id,char *s)
{
    int i;
    char ss[251] = {0};
    if(strcmp(s,myg) == 0)
    {
        avai[id] = 1;
        who[id][id] = 1;
        haswi[id] = id;
        if(who[id][id] == -1)
        {
            not[id] = 1;
            fart(id);
        }
        return;
    }
    if(strcmp(s,myng) == 0)
    {
        avai[id] = 1;
        who[id][id] = -1;
        if(who[id][id] == 1)
        {
            not[id] = 1;
            fart(id);
        }
        return;
    }
    for(i=1;i<=50;i++)
    {
        if(list[i][0])
        {
            strcpy(ss,list[i]);
            strcat(ss,xxg);
            if(strcmp(s,ss) == 0)
            {
                avai[id] = 1;
                if(haswi[id]&&haswi[id] != i)
                {
                    not[haswi[id]] = not[i] = 1;
                    fart(id);
                }
                if(who[id][i] == -1) imp = 1;
                who[id][i] = 1;
                haswi[id] = i;
                return;
            }
            strcpy(ss,list[i]);
            strcat(ss,xxng);
            if(strcmp(s,ss) == 0)
            {
                avai[id] = 1;
                if(who[id][i] == 1) imp = 1;
                who[id][i] = -1;
                return;
            }
        }
    }
    for(i=1;i<=7;i++)
    {
        strcpy(ss,today);
        strcat(ss,dayList[i]);
        if(strcmp(s,ss) == 0)
        {
            avai[id] = 1;
            if(hasd[id]&&hasd[id]!=i)
            {
                fart(id);
                notd[hasd[id]] = notd[i] = 1;
            }
            day[id][i] = 1;
            hasd[id] = i;
            return;
        }
    }
}
int main()
{
    int i,j,k,l,cnt,tot = 0,fh = 0;
    char name[251] = {0},word[251] = {0},ans[251] = {0};
    short failed = 0;
    scanf("%d %d %d\n",&m,&n,&p);
    for(i=1;i<=m;i++)
    {
        scanf("%s\n",name);
        hash(name);
    }
    for(i=1;i<=p;i++)
    {
        for(j=0;name[j-1]!=':';j++) name[j] = getchar();
        name[j-1] = 0;
        getchar();
        gets(word);
        work(hash(name),word);
        if(imp)
        {
            printf("Impossible");
            return 0;
        }
    }
    if(fpcnt>n)
    {
        printf("%Impossible");
        return 0;
    }
    fh = m;
    for(i=1;i<=50;i++) if(avai[i]) fh--;
    for(i=1;i<=50;i++)
    {
        if(!not[i]&&list[i][0])
        {
            for(j=1;j<=7;j++)
            {
                if(notd[j]) continue;
                cnt = 0;
                failed = 0;
                memcpy(wrong,fp,sizeof(wrong));
                for(k=1;k<=50;k++)
                {
                    if(!list[k][0]) continue;
                    if(haswi[k]&&haswi[k]!=i) wrong[k] = 1;
                    if(who[k][i] == -1) wrong[k] = 1;
                    if(hasd[k]&&hasd[k] != j) wrong[k] = 1;
                    if(wrong[k])
                    {
                        cnt++;
                        if(who[k][i] == 1)
                        {
                            failed = 1;
                            break;
                        }
                        for(l=1;l<=50;l++) if(who[k][l] == -1&&l!=i)
                        {
                            failed = 1;
                            break;
                        }
                        if(failed) break;
                    }
                }
                if(failed) continue;
                if(cnt == n||(cnt<n&&cnt+fh>=n)) if(strcmp(ans,list[i])!=0)
                {
                    tot++;
                    strcpy(ans,list[i]);
                }
                else if(tot>=2)
                {
                    printf("Cannot Determine");
                    return 0;
                }                 
            }
        }
    }
    if(tot) printf("%s",ans);
    else printf("Impossible");
    return 0;
}

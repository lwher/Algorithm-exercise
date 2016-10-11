#define LOCAL
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 1000 + 10

int value[MAXN];
int longestSub[MAXN];

int main()
{
#ifdef LOCAL
   // freopen("C:\\Users\\Administrator\\Desktop\\Temp\\ACMTempIn.txt", "r", stdin);
    //freopen("C:\\Users\\Administrator\\Desktop\\Temp\\ACMTempOut.txt", "w", stdout);
#endif
    int cases;
    int i,j,max;

    while(scanf("%d", &cases) != EOF)
    {
        memset(longestSub, 0, sizeof(longestSub));
        memset(value, 0, sizeof(value));
        for(i = 0; i < cases; i++)
        {
            max = 0;
            scanf("%d", &value[i]);
            longestSub[i] = 1;
            for(j = 0; j < i; j++)
            {
                if(value[j] < value[i] && max < longestSub[j])
                {
                    max = longestSub[j];
                }
                longestSub[i] = max + 1;
            }
        }

        max = 0;
        for(i = 0; i < cases; i++)
            if(max < longestSub[i])
                max =  longestSub[i];
        printf("%d\n", max);
    }
    while(1);
    return 0;
}


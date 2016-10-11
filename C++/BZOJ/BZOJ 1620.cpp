#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
const int MAXN = 1000;
int t[MAXN + 10], ed[MAXN + 10];
int n, left;
int min(int a, int b) {return a < b ? a : b;}
void swap(int &a, int &b)
{
    int tmp;
    tmp = a; a = b; b = tmp;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &t[i], &ed[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (ed[i] < ed[j])
                swap(ed[i], ed[j]), swap(t[i], t[j]);
    int left = 1000000000;
    for (int i = 1; i <= n; i++)
    {
        left = min(left, ed[i]) - t[i];
    }
    printf("%d\n", left >= 0 ? left : -1);
    system("pause");
    return 0;
}


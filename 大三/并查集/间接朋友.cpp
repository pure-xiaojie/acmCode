#include<cstdio>
#include<iostream>

using namespace std;
#define maxn 1000000

int num[maxn];
int sum[maxn];
int res;

int findFather(int x)
{
    if(x == num[x])
        return x;
    return num[x] = findFather(num[x]);
}

void merge_ab(int a, int b)
{
    int x = findFather(a);
    int y = findFather(b);

    if(x != y) {
        num[x] = y;
        sum[y] += sum[x];
        res = max(sum[y],res);
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < maxn; i++) {
            num[i] = i;
            sum[i] = 1;
        }
        int a,b;
        res = 1;
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            merge_ab(a,b);
        }
        cout << res << endl;
    }
    return 0;
}

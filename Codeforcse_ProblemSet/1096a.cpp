#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define eps 1e-8
#define int_inf (1<<30)-1
#define ll_inf (1LL<<62)-1
#define lson curPos<<1
#define rson curPos<<1|1

using namespace std;

int t;

int main()
{
    scanf("%d",&t);
    while (t--){
        ll l,r; scanf("%lld%lld",&l,&r);
        printf("%lld %lld\n",l,l*2);
    }
    return 0;
}


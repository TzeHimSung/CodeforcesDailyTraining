//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
//define
#define int int32_t
#define ll int64_t
#define dou double
#define pb emplace_back
#define mp make_pair 
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
//namespace
using namespace std;
//header end

int a[7],sum=0;

int main()
{
    rep1(i,1,6) 
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sot(a,6);
    int l=2,r=6;
    while (l<r)
    {
        int s1=a[1]+a[l]+a[r],s2=sum-s1;
        if (s1<s2) l++;
            else if (s1>s2) r--;
                else
                {
                    puts("YES");
                    return 0;
                }
    }
    puts("NO");
    return 0;
}
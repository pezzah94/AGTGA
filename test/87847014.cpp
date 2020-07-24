// @skylag
//I am into me now ;)
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define SKY ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long int
int power(int a,int n,int m)
{

    int res=1;
    while(n)
    {
        if(n&1)
        {
            res=((res%m)*(a%m))%m;
            n--;
        }
        else
        {
            a=((a%m)*(a%m))%m;
            n/=2;
        }
    }
    return res;
}
const int mod= 998244353;
void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(auto &it: a)
        cin>>it;
    int b[n];
    for(auto &it: b)
        cin>>it;
    sort(b,b+n);
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
        v[i].F=a[i]*(i+1)*(n-i);
        v[i].S=i;
    }
    sort(ALL(v));
    reverse(ALL(v));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=((ans%mod)+((v[i].F%mod)*(b[i]%mod))%mod)%mod;
    }
    cout<<ans<<"\n";
    
}
int32_t main()
{
    SKY;
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
/*Codeforces Virtual Round #560 (Div. 3)*/
 
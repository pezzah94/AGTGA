#include<bits/stdc++.h>
using namespace std;


#define ll                      long long
#define pii                     pair<int, int>
#define pli                     pair<ll, int>
#define pil                     pair<int, ll>
#define pll                     pair<ll, ll>
#define vi                      vector<int>
#define vll                     vector<ll>
#define vb                      vector<bool>
#define vd                      vector<double>
#define vs                      vector<string>
#define ff                      first
#define ss                      second
#define pb                      push_back
#define eb                      emplace_back
#define ppb                     pop_back
#define pf                      push_front
#define ppf                     pop_front
#define vpii                    vector<pii>
#define vpll                    vector<pll>
#define umap                    unordered_map
#define all(x)                  x.begin(),x.end()
#define clr(a,b)                memset(a,b,sizeof a)
#define fr(i, n)                for(ll i=0; i<n;++i)
#define fr1(i, n)               for(ll i=1; i<=n; ++i)
#define rfr(i, n)                for(ll i=n-1; i>=0; --i)
#define precise(x)              cout<<fixed<<setprecision(x)
#define wh                        while
#define mp                        make_pair
#define le                        length()


ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}

ll lcm(ll a,ll b) 
{ return (a*b)/__gcd(a,b); }

ll power(ll x,ll y,ll p) 
{ ll res=1; x=x%p;
    while(y>0) 
    { if (y&1) res=(res*x)%p; 
      y=y>>1; x=(x*x)%p; } 
    return res; } 
    
bool inside(ll x,ll y,ll n,ll m)
{
    return(x>=0&&x<n&&y>=0&&y<=m);
}   
const int N=300000 + 300;
vll g[N];
vll dp(N,0),w(N,0);

void calc(ll v,ll pre)
{
//	cout<<v<<" "<<endl;
	dp[v]=0;
	if(w[v])
	{
		dp[v]+=1;
	}
	
	for(auto u:g[v])
	{
//		calc(u,v);
		if(u!=pre)
		{
			calc(u,v);
			dp[v]+=dp[u];
		}
//		cout<<v<<" "<<dp[v]<<endl;
	}
}
void solve()
{    
	ll n;
	cin>>n;
	
	
	fr(i,n-1)
	{
		ll u,v,t;
		
		cin>>u>>v>>t;
		if(t==2)
		{
			w[u]=1;
			w[v]=1;
		}
		
		g[u].pb(v);
		g[v].pb(u);
	}
	calc(1,-1);
	vll ans;
	fr1(i,n)
	{
		if(w[i]&&dp[i]==1)
		{
			ans.pb(i);
		}
	}
	
	cout<<ans.size()<<endl;;
	
	fr(i,ans.size())
	{
		cout<<ans[i]<<" ";
	}
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(0);
    
//	int t;
//  cin>>t;
//	wh(t--)
    {
        solve();
    }
    
	return 0;
}
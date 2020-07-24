#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;

#define ll long long
#define MOD 1000000007

/* unordered_map<ll int , ll int>fib; //fibbonaci

ll int f(ll int n){
    if(fib.count(n))return fib[n];

    ll int k = (n/2);  //k = 2*n
    if(n%2 == 0)
        return fib[n] = (f(k)*f(k) + f(k-1)*f(k-1))%MOD;
    else
        return fib[n] = (f(k)*f(k+1) + f(k)*f(k-1))%MOD;
    
} */

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t;
    cin>>t;

    while(t--){

        int n,k;
        cin>>n>>k;

        if(k == 0){

            cout<<"0"<<endl;
            for(int i = 1;i<=n ; i++){
                for(int j = 1 ; j<=n ; j++){
                    cout<<"0";
                }
                cout<<endl;
            }

            continue;

        }
        int f =(k%n == 0)?0:2 ;

        int mat[n+1][n+1];

        for(int i = 0 ; i<n+1 ; i++){
            for(int j = 0 ; j<n+1 ; j++){
                mat[i][j] = 0;
            }
        }
        int p = 0; int q = 0;
        for(int i = 1 ; i<=k ; i++){
            mat[p+1][q+1] = 1 ;
            p++;  
            q = (q+1)%n;
            if(p == n){
                p =0 ;
                q = (q+1)%n;
            }

        }

        cout<<f<<endl;

        for(int i = 1 ; i <=n ; i++){
            for(int j = 1 ; j<=n ; j++){
                cout<<mat[i][j];
            }
            cout<<endl;
        }





    }

    return 0;
}
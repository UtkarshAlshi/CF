#include <bits/stdc++.h>
 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ll long long int
#define endl "\n"
#define minHeap(x) priority_queue<x,vector<x>,greater<x>>
#define pp pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define ppp pair<ll,pp>
 
const ll N = (1<<15+10);
const ll mod = 1e9+7;
const ll inf = 1e18;
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
 
ll expo(ll a, ll b, ll modulo)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2)
        ans = (ans*a)%modulo;
        a = (a*a)%modulo;
        b=b>>1;
    }
    return ans;
}
 
 
 
 
ll find(vector<ll> &par, ll x)
{
    return par[x] = (par[x]==x) ? x : find(par,par[x]);  
}
 
 
void Union(vector<ll> &par, vector<ll> &rank, ll a, ll b)
{
    a=find(par,a);
    b=find(par,b);
    
    if(a==b)
    return;
    
    if(rank[a]<rank[b])
    {
        par[a]=par[b];
        rank[b]+=rank[a];
    }
    else
    {
        par[b]=par[a];
        rank[a]+=rank[b];
    }
}
 
bool isPalindrome(int num){
	int rev=0;
	int temp=num;
	while (num>0){
		rev=rev*10 + (num%10);
		num/=10;
	}
	return (rev==temp);
}
 
vector<ll> palin;
void compute()
{
    for(int i=1;i<N;i++)
    {
        if(isPalindrome(i))
        palin.pb(i);
    }
}
 
 
void solve()
{
    
ll n,k;
cin>>n>>k;
vector<ll> arr(n);
 
for(int i=0;i<n;i++)
cin>>arr[i];
 
 
bool fl1=0,fl2=0,fl3=0;
 
ll cnt=0;
ll num=0;
for(int i=0;i<n;i++)
{
    if(arr[i]<=k)
    num++;
    else
    num--;
    
    if(num>=0)
    {
        if(i+1<n-1 and arr[i+1]>k and (i+1)%2)
        i++;
        cnt++;
        num=0;
    }
    
    if(cnt>=2 and i<n-1)
    {
        fl1=1;
        break;
    }
}
 
cnt=0;
num=0;
for(int i=n-1;i>=0;i--)
{
    if(arr[i]<=k)
    num++;
    else
    num--;
    
    if(num>=0)
    {
        if(i-1>=1 and arr[i-1]>k and (n-i)%2)
        i--;
        cnt++;
        num=0;
    }
    
    if(cnt>=2 and (i>=0))
    {
        fl2=1;
        break;
    }
}
ll idx1=n,idx2=0;
ll i=0;
num=0;
cnt=0;
while(i<n)
{
    if(arr[i]<=k)
    num++;
    else
    num--;
    
    if(num>=0)
    {
        idx1=i;
        cnt++;
        num=0;
        break;
    }
    i++;
}
 
i=n-1;
while(i>=0)
{
    if(arr[i]<=k)
    num++;
    else
    num--;
    
    if(num>=0)
    {
        idx2=i;
        cnt++;
        num=0;
        break;
    }
    i--;
}
 
if(cnt==2 and idx1<idx2)
fl3=1;
 
if(fl1 or fl2 or fl3)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
 
 
 
}
 
 
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t;
    cin >> t;
    while (t--)
        solve();
  
}
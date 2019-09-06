//Digit Pairs
#include <bits/stdc++.h>
using namespace std;

#define int         long long int
#define ld          long double
#define lop(i,a,b)  for(int i = a; i < b; i++)
#define rlop(i,b,a) for(int i = b-1; i >= a; i--)
#define endl        '\n'
#define pb          push_back
#define F           first
#define S           second
#define pii         pair <int, int>
#define vi          vector <int>
#define vpi         vector <pii>
#define mii         map <int, int>
#define si          set <int>
#define spi         set <pii>
#define usi         unordered_set <int>
#define que_max     priority_queue <int>
#define que_min     priority_queue <int, vi, greater<int>>
#define sz(x)       ((int) x.size())
#define all(p)      p.begin(), p.end()
#define mset(a,b,c) lop(i,0,c) a[i] = b
#define print(a)    for(auto x:a) cout << x << " "; cout << endl
#define print1(a,n) lop(i,0,n) cout << a[i] << " "; cout << endl
#define bug(...)    __f(#__VA_ARGS__, __VA_ARGS__)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr(names + 1, ',');
     cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

vi v,v1;

void solve()
{
     int n,m,k;
     cin>>n;
     v.resize(n);
     lop(i,0,n) cin>>v[i];
     for(auto x:v)
     {
          int mx=-1,mn=10,z=x,cnt=0;
          while(z>0)
          {
               mx=max(mx,z%10);
               mn=min(mn,z%10);
               cnt++;
               z/=10;
          }
          if(cnt==3) v1.pb(11*mx+7*mn);
     }
     mii mp,mp1;
     lop(i,0,sz(v1))
     {
          int y=v1[i],cnt=0;
          while(y>0)
          {
               if(cnt==1)
               {
                   if(i&1) mp[y%10]++;
                   else mp1[y%10]++;
                   break;
               }
               y/=10;
               cnt++;
          }
     }
     int ans=0;
     int ar[10];
     mset(ar,0,10);
     for(auto x:mp)
     {
          if(x.S==2) ans++,ar[x.F]++;
          else if(x.S>2) ans+=2,ar[x.F]+=2;
     }
     for(auto x:mp1)
     {
          if(x.S==2 && !ar[x.F]) ans++;
          else if(x.S>2)
          {
               if(!ar[x.F]) ans+=2;
               else if(ar[x.F]==1) ans++;
          }
     }
     cout<<ans;
}

int32_t main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     solve();

     return 0;
}
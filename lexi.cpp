// Lexi String
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

map<char,int> mp;

bool cmp(char a,char b)
{
     return mp[a]<mp[b];
}
void solve(int t)
{
     mp.clear();
     string s,s1;
     cin>>s>>s1;
     lop(i,0,sz(s)) mp[s[i]]=i;
     sort(all(s1),cmp);
     if(t) cout<<s1<<endl;
     else cout<<s1;
}

int32_t main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     int t; cin >> t;
     while (t--) solve(t);

     return 0;
}
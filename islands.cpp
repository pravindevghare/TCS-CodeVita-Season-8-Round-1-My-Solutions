// Islands
#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct point
{
     ll x,y,x1,y1;
};
int const N=1e6;
point a[N];
ll n,c,d;

void work(ll b[],int i)
{
     b[0]=abs(a[i].x-c)+abs(a[i].y-d);
     b[1]=abs(a[i].x1-c)+abs(a[i].y1-d);
     b[2]=abs(a[i].x-c)+abs(a[i].y1-d);
     b[3]=abs(a[i].x1-c)+abs(a[i].y-d);

     if(d>=min(a[i].y,a[i].y1) && d<=max(a[i].y,a[i].y1))
     {
          ll e=abs(a[i].x-c);
          ll f=abs(a[i].x1-c);
          b[4]=min(e,f);
     }

     if(c>=min(a[i].x,a[i].x1) && c<=max(a[i].x,a[i].x1))
     {
          ll e=abs(a[i].y-d);
          ll f=abs(a[i].y1-d);
          b[5]=min(e,f);
     }
}
int main()
{
     cin>>n;
     for(ll i=0;i<n;i++) 
     {
          cin>>a[i].x>>a[i].y>>a[i].x1>>a[i].y1;
     }
     cin>>c>>d;

     set <pair<ll,ll> > st;

     for(ll i=0;i<n;i++)
     {
          ll b[6],ans=1e18;
          for(ll i=0;i<6;i++) 
               b[i]=1e18;

          work(b,i);

          for(ll i=0;i<6;i++)  ans=min(ans,b[i]);
          st.insert({ans,i+1});
     }

     for(auto x:st) cout<<x.second<<" ";

     return 0;
}
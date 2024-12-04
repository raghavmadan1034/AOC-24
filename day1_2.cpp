#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    //in the end add 0 0 to the input
    vector<ll>v1,v2;
    ll a,b;
    cin>>a>>b;
    while(a){
        
        v1.push_back(a);
        v2.push_back(b);
        cin>>a>>b;
    }
    sort(v1.begin(),v1.end());sort(v2.begin(),v2.end());
    map<ll,ll>m;
    for(auto x:v2)m[x]++;
    ll ans=0;
    for(auto x:v1){
        ans+=m[x]*x;
    }
    cout<<ans<<endl;
}
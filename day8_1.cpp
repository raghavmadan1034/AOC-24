#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){ 
    vector<string>v;
    string s;
    getline(cin,s);
    ll ans=0;
    ll m,n;
    while(s.size()){
        m=s.size();
        v.push_back(s);
        getline(cin,s);
    }
    n=v.size();
    cout<<n<<" "<<m<<endl;
    // ll ans=0;
    set<pair<ll,ll>>st;
    map<char,vector<pair<ll,ll>>>mp;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]!='.')mp[v[i][j]].push_back({i,j});
        }
    }
    for(auto x:mp){
        ll k=x.second.size();
        for(ll i=0;i<k;i++){
            for(ll j=i+1;j<k;j++){
                pair<ll,ll> p1=x.second[i];
                pair<ll,ll>p2=x.second[j];
                ll a=2*p1.first-p2.first;ll b=2*p1.second-p2.second;
                if(a>=0 && a<n && b>=0 && b<m)st.insert({2*p1.first-p2.first,2*p1.second-p2.second});
                a=2*p2.first-p1.first;b=2*p2.second-p1.second;

                if(a>=0 && a<n && b>=0 && b<m)st.insert({2*p2.first-p1.first,2*p2.second-p1.second});
            }
        }
    }
    ans=st.size();
    cout<<ans<<endl;
}
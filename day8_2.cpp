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
                st.insert(p1);st.insert(p2);
                ll i=1;
                ll a=(i+1)*p1.first-i*p2.first;ll b=(i+1)*p1.second-i*p2.second;
                while(a>=0 && a<n && b>=0 && b<m){

                    st.insert({a,b});
                    i++;
                    a=(i+1)*p1.first-i*p2.first;b=(i+1)*p1.second-i*p2.second;
                }
                i=1;
                a=(i+1)*p2.first-i*p1.first;b=(i+1)*p2.second-i*p1.second;
                while(a>=0 && a<n && b>=0 && b<m){
                    st.insert({a,b});
                    i++;
                    a=(i+1)*p2.first-i*p1.first;b=(i+1)*p2.second-i*p1.second;
                }
            }
        }
    }
    // for(auto x:st)cout<<x.first<<" "<<x.second<<endl;
    ans=st.size();
    cout<<ans<<endl;
}
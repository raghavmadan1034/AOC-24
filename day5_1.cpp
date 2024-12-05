#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    string s;
    getline(cin,s);
    map<ll,set<ll>>m;
    while(s.size()){
        m[stoi(s.substr(0,2))].insert(stoi(s.substr(3,2)));
        getline(cin,s);
    }
    // for(auto x:m[14])cout<<x<<" ";
    getline(cin,s);
    ll ans=0;
    while(s.size()){
        vector<ll>v;
        string temp;
        for(ll i=0;i<s.size();i++){
            if(s[i]!=','){
                temp.push_back(s[i]);
            }
            else{
                v.push_back(stoi(temp));
                temp.clear();
            }
        }
        v.push_back(stoi(temp));
        ll n=v.size();
        vector<ll>t;
        ll f=0;
        for(ll i=0;i<n;i++){
            for(auto x:t){
                if(m[v[i]].find(x)!=m[v[i]].end())f=1;
            }
            t.push_back(v[i]);
        }
        if(!f)ans+=v[n/2];
        getline(cin,s);
    }
    cout<<ans<<endl;
}
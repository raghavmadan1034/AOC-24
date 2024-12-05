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
        if(f){
            //we just have to find the middle number =>exactly (n-1)/2 numbers in vector are on right of it
            //for each number find how many numbers are to the right of it O(n^2)
            for(ll i=0;i<n;i++){
                
                ll cnt=0;
                for(ll j=0;j<n;j++){
                    if(j==i)continue;
                    if(m[v[i]].find(v[j])!=m[v[i]].end()){
                        cnt++;
                    }
                }
                if(cnt==(n-1)/2){
                    ans+=v[i];
                    break;
                }
            }

            
        }
        getline(cin,s);
    }
    cout<<ans<<endl;
}
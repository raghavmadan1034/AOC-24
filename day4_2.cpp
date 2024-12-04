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
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]=='A'){
                ll f=0;
                if(i-1>=0 && j-1>=0 && i+1<n && j+1<m){
                    if(v[i-1][j-1]=='M' && v[i+1][j+1]=='S')f++;
                    if(v[i-1][j-1]=='S' && v[i+1][j+1]=='M')f++;
                    if(v[i-1][j+1]=='M' && v[i+1][j-1]=='S')f++;
                    if(v[i-1][j+1]=='S' && v[i+1][j-1]=='M')f++;
                }
                if(f==2)ans++;
                
            }
        }
    }
    cout<<ans<<endl;
}
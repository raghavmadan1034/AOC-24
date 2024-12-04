#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll right(vector<string>&v,ll i,ll j,ll n,ll m){
    if(j+3>=n)return 0;
    string temp;
    for(ll k=0;k<4;k++){
        temp.push_back(v[i][j+k]);
    }
    if(temp=="XMAS")return 1;
    else return 0;
}
ll left(vector<string>&v,ll i,ll j,ll n,ll m){
    if(j-3<0)return 0;
    string temp;
    for(ll k=0;k<4;k++){
        temp.push_back(v[i][j-k]);
    }
    if(temp=="XMAS")return 1;
    else return 0;
}
ll up(vector<string>&v,ll i,ll j,ll n,ll m){
    if(i-3<0)return 0;
    string temp;
    for(ll k=0;k<4;k++){
        temp.push_back(v[i-k][j]);
    }
    if(temp=="XMAS")return 1;
    else return 0;
}
ll down(vector<string>&v,ll i,ll j,ll n,ll m){
    if(i+3>=n)return 0;
    string temp;
    for(ll k=0;k<4;k++){
        temp.push_back(v[i+k][j]);
    }
    if(temp=="XMAS")return 1;
    else return 0;
}
ll NW(vector<string>&v,ll i,ll j,ll n,ll m){
    if(j-3<0||i-3<0)return 0;
    string temp;
    for(ll k=0;k<4;k++){
        temp.push_back(v[i-k][j-k]);
    }
    if(temp=="XMAS")return 1;
    else return 0;
}
ll NE(vector<string>&v,ll i,ll j,ll n,ll m){
    if(j+3>=n||i-3<0)return 0;
    string temp;
    for(ll k=0;k<4;k++){
        temp.push_back(v[i-k][j+k]);
    }
    if(temp=="XMAS")return 1;
    else return 0;
}
ll SW(vector<string>&v,ll i,ll j,ll n,ll m){
    if(j-3<0||i+3>=n)return 0;
    string temp;
    for(ll k=0;k<4;k++){
        temp.push_back(v[i+k][j-k]);
    }
    if(temp=="XMAS")return 1;
    else return 0;
}
ll SE(vector<string>&v,ll i,ll j,ll n,ll m){
    if(j+3>=n||i+3>=n)return 0;
    string temp;
    for(ll k=0;k<4;k++){
        temp.push_back(v[i+k][j+k]);
    }
    if(temp=="XMAS")return 1;
    else return 0;
}
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
            if(v[i][j]=='X'){
                ans+=right(v,i,j,n,m)+left(v,i,j,n,m)+up(v,i,j,n,m)+down(v,i,j,n,m)+NW(v,i,j,n,m)+NE(v,i,j,n,m)+SW(v,i,j,n,m)+SE(v,i,j,n,m);
            }
        }
    }
    cout<<ans<<endl;
}
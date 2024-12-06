#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    string s;
    getline(cin,s);
    vector<string>v;
    ll m=s.size();
    while(s.size()){
        v.push_back(s);
        getline(cin,s);
    }
    ll n=v.size();
    ll f=0;
    pair<ll,ll>prev={-1,-1};
    ll ans=0;
    pair<ll,ll>indx;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]=='^')indx={i,j};
        }
    }
    for(ll a=0;a<n;a++){
        for(ll b=0;b<m;b++){
            if(prev.first!=-1)v[prev.first][prev.second]='.';
            if(v[a][b]=='#'||v[a][b]=='^'){
                continue;
            }
            v[a][b]='#';
            prev={a,b};
            ll i=indx.first;
            ll j=indx.second;
            ll cnt=0;
            cnt++;
            ll direction=1;//direction%4= 1->up , 2->right,3->down,0->left
            while(j!=m-1 && i!=n-1 && i!=0 && j!=0){
                while(direction%4==1 && i>0 && v[i-1][j]!='#'){
                    i--;
                    cnt++;
                }
                if(i>0 && v[i-1][j]=='#')direction++;
                while(direction%4==2 && j<m-1 && v[i][j+1]!='#'){
                    j++;
                    cnt++;
                }
                if(j<m-1 && v[i][j+1]=='#')direction++;
                while(direction%4==3 && i<n-1 && v[i+1][j]!='#'){
                    i++;
                    cnt++;
                }
                if(i<n-1 && v[i+1][j]=='#')direction++;
                while(direction%4==0 && j>0 && v[i][j-1]!='#'){
                    j--;
                    cnt++;
                }            
                if(j>0 && v[i][j-1]=='#')direction++;
                if(cnt>=n*m){//if it visits more than size of grid=>definitely stuck in loop
                    // cout<<a<<" "<<b<<endl;
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}
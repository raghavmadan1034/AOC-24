#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    //press enter in the last line after taking input to leave last line as an empty string 
    string s;
    getline(cin,s);
    ll ans=0;
    while(s.size()){
        vector<ll>v;
        string temp;
        for(auto x:s){
            if(x!=' ')temp.push_back(x);
            else{
                // cout<<temp<<" ";
                v.push_back(stoi(temp));
                temp.clear();
            }
        }
        v.push_back(stoi(temp));
        // for(auto x:v)cout<<x<<" ";
        // cout<<endl;
        ll f=0;
        ll flag=0;
        if(v[1]>=v[0])f=1;
        if(f){
            for(ll i=1;i<v.size();i++){
                if(v[i]-v[i-1]<1||v[i]-v[i-1]>3)flag=1;
            }
        }
        else{
            for(ll i=1;i<v.size();i++){
                if(v[i-1]-v[i]<1||v[i-1]-v[i]>3)flag=1;
            }
        }
        if(!flag)ans++;
        getline(cin,s);
    }
    cout<<ans<<endl;

}
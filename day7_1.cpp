#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool recur(vector<ll>&v,ll & val,ll st,ll temp){
    if(st==v.size()){
        if(temp==val)return true;
        else return false;
    }
    return (recur(v,val,st+1,temp+v[st])||recur(v,val,st+1,temp*v[st]));
}
int main(){
    string s;
    getline(cin,s);
    ll ans=0;
    while(s.size()){
        vector<ll>v;
        ll i=0;
        string temp;
        while(s[i]!=':'){
            temp.push_back(s[i]);
            i++;
        }
        ll val=stoll(temp);
        i++;
        
        while(i!=s.size()){
            string temp;
            if(s[i]==' ')i++;
            while(i<s.size() && s[i]!=' '){
                temp.push_back(s[i]);
                i++;
            }
            if(temp.size())v.push_back(stoll(temp));
        }
        ll n=v.size();
        // cout<<recur(v,val,n,0)<<endl;
        if(recur(v,val,1,v[0]))ans+=val;

        getline(cin,s);

    }
    cout<<ans<<endl;
    
}
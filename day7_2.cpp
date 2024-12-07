#include<bits/stdc++.h>
#define ll long long
using namespace std;
//for part 2 run this code on online compiler (codechef ), will give correct ans
ll cntdigit(ll val){
    ll ans=0;
    while(val){
        ans++;
        val/=10;
    }
    return ans;
}
bool recur(vector<ll>&v,ll & val,ll st,ll temp){
    // if(temp>=1e16)return false;
    if(st==v.size()){
        if(temp==val)return true;
        else return false;
    }
    ll x=pow(10,cntdigit(v[st]));

    return (recur(v,val,st+1,temp+v[st])||recur(v,val,st+1,temp*v[st]))||recur(v,val,st+1,temp*x+v[st]);
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
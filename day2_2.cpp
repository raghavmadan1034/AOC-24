#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    //press enter in the last line after taking input to leave last line as an empty string 
    string s;
    getline(cin,s);
    ll ans=0;
    ll cnt=0;
    while(s.size()){
        cnt++;
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
        set<ll>s1;
        if(f){
            for(ll i=1;i<v.size();i++){
                if(v[i]-v[i-1]<1||v[i]-v[i-1]>3){
                    s1.insert(i-1);
                    s1.insert(i);
                    flag=1;
                }
            }
            if(s1.size()>3){
                s1.clear();
                for(ll i=1;i<v.size();i++){
                    if(v[i-1]-v[i]<1||v[i-1]-v[i]>3){
                        s1.insert(i-1);
                        s1.insert(i);
                        flag=1;
                    }
                } 
            }
        }
        else{
            for(ll i=1;i<v.size();i++){
                if(v[i-1]-v[i]<1||v[i-1]-v[i]>3){
                    s1.insert(i-1);
                    s1.insert(i);
                    flag=1;
                }
            }
            if(s1.size()>3){
                s1.clear();
                for(ll i=1;i<v.size();i++){
                    if(v[i]-v[i-1]<1||v[i]-v[i-1]>3){
                        s1.insert(i-1);
                        s1.insert(i);
                        flag=1;
                    }
                } 
            }
        }
        if(!flag)ans++;
        else{
            if(s1.size()<=3){
                flag=0;
                for(auto x:s1){
                    vector<ll>temp;
                    for(ll i=0;i<v.size();i++){
                        if(i==x)continue;
                        temp.push_back(v[i]);
                    }
                    ll flagt=0;
                        for(ll i=1;i<temp.size();i++){
                            if(temp[i]-temp[i-1]<1||temp[i]-temp[i-1]>3){
                                flagt=1;
                            }
                        }
                    if(flagt==0)flag=1;
                    flagt=0;
                        for(ll i=1;i<temp.size();i++){
                            if(temp[i-1]-temp[i]<1||temp[i-1]-temp[i]>3){
                                flagt=1;
                            }
                        }
                    if(flagt==0)flag=1;
                    
                }
                if(flag)ans++;
            }
        }
        getline(cin,s);
    }
    cout<<ans<<endl;
}
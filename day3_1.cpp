#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
   //in the end add 0 0 to the input 
    string s;
    getline(cin,s);
    ll ans=0;
    while(s.size()){
        for(ll i=0;i<s.size();i++){
            if(i+3<s.size() && s[i]=='m' && s[i+1]=='u' && s[i+2]=='l' && s[i+3]=='('){
                string t1,t2;
                i+=4;
                while(i<s.size() && s[i]-'0'<=9 && s[i]-'0'>=0){
                    t1.push_back(s[i]);
                    i++;
                }
                if(i>=s.size())continue;
                if(t1.size()<1||t1.size()>3)continue;
                if(i<s.size() && s[i]!=',')continue;
                i++;
                while(i<s.size() && s[i]-'0'<=9 && s[i]-'0'>=0){
                    t2.push_back(s[i]);
                    i++;
                }
                if(i>=s.size())continue;
                if(t2.size()<1||t2.size()>3)continue;
                if(s[i]!=')')continue;
                ans+=stoi(t1)*stoi(t2);

            }
        }
        getline(cin,s);
    }
    cout<<ans<<endl;
}
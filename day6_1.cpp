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
    // cout<<n<<" "<<m;
    set<pair<ll,ll>>st;
    ll direction=1;//direction%4= 1->up , 2->right,3->down,0->left
    ll f=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]=='^'){
                st.insert({i,j});
                while(j!=m-1 && i!=n-1 && i!=0 && j!=0){
                    while(direction%4==1 && i>0 && v[i-1][j]!='#'){
                        i--;
                        st.insert({i,j});
                    }
                    if(i>0 && v[i-1][j]=='#')direction++;
                    while(direction%4==2 && j<m-1 && v[i][j+1]!='#'){
                        j++;
                        st.insert({i,j});
                    }
                    if(j<m-1 && v[i][j+1]=='#')direction++;
                    while(direction%4==3 && i<n-1 && v[i+1][j]!='#'){
                        i++;
                        st.insert({i,j});
                    }
                    if(i<n-1 && v[i+1][j]=='#')direction++;
                    while(direction%4==0 && j>0 && v[i][j-1]!='#'){
                        j--;
                        st.insert({i,j});
                    }
                    if(j>0 && v[i][j-1]=='#')direction++;
                }
                f=1;
                break;
            }
            if(f)break;
        }
        if(f)break;
    }

    cout<<st.size()<<endl;
}
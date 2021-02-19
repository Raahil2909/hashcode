#include<bits/stdc++.h>
using namespace std;

/***typededfs***/
typedef long long ll;
typedef long double ldb;

/***defines***/
#define M1 1000000007
#define M2 998244353
#define F first
#define S second
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forz(i,n) for(int i=0;i<(n);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define rforz(i,n) for(int i=(n-1);i>=0;i--)
#define rfore(i,a,b) for(int i=(a);i>=(b);i--)
#define test int T; cin>>T; while(T--)
#define all(x) x.begin(),x.end()


int main(){ 
    FASTIO;
    int m,t2,t3,t4;
    cin>>m>>t2>>t3>>t4;
    map<string,int>hash;
    map<int,string>rhash;
    vector<int>gr[m];
    int counter=1;
    forz(i,m){
        int x;
        cin>>x;
        gr[i].pb(x);
        while(x--){
            string s; int temp;
            cin>>s;
            if(hash[s]==0){
                hash[s]=counter++;
                rhash[counter-1]=s;
            }
            temp = hash[s];
            gr[i].pb(temp);
        }
    }
    forz(i,m){
        int ok=1;
        for(auto x:gr[i]){
            if(ok){
                cout<<x<<" -> ";
                ok=0;
                continue;
            } else{
                cout<<rhash[x]<<' ';
            }
        } cout<<'\n';
    }
}
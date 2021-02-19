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

void iofile(){	
#ifndef ONLINE_JUDGE
    freopen("a_example.txt","r",stdin);
    freopen("a_out.txt","w",stdout);
#endif
}

int main(){ 
    FASTIO;
    iofile();
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
    // cout<<m<<','<<t2<<','<<t3<<','<<t4<<'\n';
    // forz(i,m){
    //     int ok=1,j;
    //     for(j=0;j<gr[i].size()-1;j++){
    //         cout<<gr[i][j]<<',';
    //     } cout<<gr[i][j]<<'\n';
    // }
    int tol_team=t2+t3+t4;
    int ppl_left = t2*2+t3*3+t4*4;
    int piz_left = m;
    int t2_left = t2*2, t3_left = t3*3, t4_left = t4*4;
    vector<int>ans2,ans3,ans4;
    int curr_pizz=0;
    while(true){
        if(t2_left && piz_left>1){
            ans2.pb(curr_pizz++);
            ans2.pb(curr_pizz++);
            t2_left-=2;
            piz_left-=2;
        } else if(t3_left && piz_left>2){
            ans3.pb(curr_pizz++);
            ans3.pb(curr_pizz++);
            ans3.pb(curr_pizz++);
            t3_left-=3;
            piz_left-=3;
        } else if(t4_left && piz_left>3){
            ans4.pb(curr_pizz++);
            ans4.pb(curr_pizz++);
            ans4.pb(curr_pizz++);
            ans4.pb(curr_pizz++);
            t4_left-=4;
            piz_left-=4;
        } else{
            break;
        }
    }
    cout<<ans2.size()/2+ans3.size()/3+ans4.size()/4<<'\n';
    forz(i,ans2.size()){
        cout<<2<<' '<<ans2[i]<<' '<<ans2[i+1]<<'\n';
        i++;
    }
    forz(i,ans3.size()){
        cout<<3<<' '<<ans3[i]<<' '<<ans3[i+1]<<' '<<ans3[i+2]<<'\n';
        i+=2;
    }
    forz(i,ans4.size()){
        cout<<4<<' '<<ans4[i]<<' '<<ans4[i+1]<<' '<<ans4[i+2]<<' '<<ans4[i+3]<<'\n';
        i+=3;
    }

}
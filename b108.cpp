#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> gon(n); for(ll i = 0; i < n; i++) cin >> gon[i];
    vector<ll> grp(m); for(ll i = 0; i < m; i++) cin >> grp[i];
    
    vector<ll> ans(n, 0);
    ll pgon = 0; // 現在のゴンドラ
    // grp分ループ
    // cout << endl;
    for(ll i = 0; i < m; i++){
        for(;; pgon++){
            if(pgon == n){
                pgon = 0;
            }
            // 全員乗れる
            if(gon[pgon] - grp[i] >= 0){
                ans[pgon] += grp[i];
                grp[i] = 0;
                pgon++;
                break;
            }
            // 全員乗れない
            ans[pgon] += gon[pgon];
            grp[i] -= gon[pgon]; // 乗った人数を引く
        }
    }

    for(ll i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    
    return 0;
}
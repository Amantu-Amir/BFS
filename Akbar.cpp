#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<queue>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
using namespace std;
const int N=1e6+50;
const int mod=1e9+7;

class node{
public:
	ll name, dist, prev;
};
ll vis[N];
vector<ll> G[N];

bool bfs(ll root, ll dis){
	queue<node> Q;
	Q.push({root, dis, -1});
	ll flag = 0;
	while(!Q.empty()){
		node par = Q.front();
		Q.pop();
		vis[par.name]++;
		if(vis[par.name] == 1)
			flag = 1;
		if(par.dist > 0){
			ll len = G[par.name].size();
			for(ll i=0; i<len; i++){
				ll child = G[par.name][i];
				if(child == par.prev)
					continue;
				Q.push({child, par.dist-1, par.name});
			}
		}
	}
	return flag;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll tc=1; cin>>tc;
	for(ll T=1; T<=tc;T++){
		for(ll i=0; i<N-5; i++){
			vis[i] = 0;
			G[i].clear();
		}
		ll n,r,m; cin>>n>>r>>m;
		ll u,v;
		for(ll i=0; i<r; i++){
			cin>>u>>v;
			G[u].pb(v);
			G[v].pb(u);
		}
		ll k, s, no = 0;
		for(ll i=0; i<m; i++){
			cin>>k>>s;
			if(no == 0){
				bool flag = bfs(k,s);
				if(!flag){
					no = 1;
				}
			}
		}
		if(no){
			cout<<"No\n";
			continue;
		}
		for(ll i=1; i<=n; i++){
			if(!vis[i]){
				no = 1; break;
			}
		}
		if(no) cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}


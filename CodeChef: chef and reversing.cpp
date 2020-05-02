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
#define inf 1e9
using namespace std;
const int N=1e5+50;
const int mod=1e9+7;

class node{
public:
	ll nod, wgt;
};
vector<node> G[N];
ll dist[N];

void bfs(ll n){
	for(ll i=0; i<N-5; i++){
		dist[i] = inf;
	}
	dist[1] = 0;
	deque<node> dq;
	dq.push_back({1,0});
	ll ok = 0;
	node u, v;
	while(!dq.empty()){
		u = dq.front();
		dq.pop_front();
		if(u.nod==n){
			ok=1;
		}
		ll len = G[u.nod].size();
		for(ll i=0; i<len; i++){
			v = G[u.nod][i];
			if((dist[u.nod] + v.wgt) < dist[v.nod]){
				dist[v.nod] = dist[u.nod] + v.wgt;
				if(v.wgt==0){
					dq.push_front(v);
				}
				else{
					dq.push_back(v);
				}
			}
		}
	}
	if(ok==1){
		cout<<dist[n]<<"\n";
	}
	else{
		cout<<"-1\n";
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll tc=1;
	for(ll T=1; T<=tc;T++){
		ll n, e;
		cin>>n>>e;
		ll u, v;
		for(ll i=1; i<=e; i++){
			cin>>u>>v;
			G[u].pb({v,0});
			G[v].pb({u,1});
		}
		if(n==1){
			cout<<"-1\n";
			return 0;
		}
		bfs(n);
	}
	return 0;
}


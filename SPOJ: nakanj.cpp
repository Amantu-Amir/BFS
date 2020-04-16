//knight moves

#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<queue>
#define ll int
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
using namespace std;
const int N=15;
const int mod=1e9+7;


ll fx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
ll fy[] = {1, 2, 2, 1, -1, -2, -2, -1};
ll vis[N][N], level[N][N];
void solve(string a, string b);
void bfs(ll x, ll y, ll a, ll b);
bool valid(ll r, ll c);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll tc; cin>>tc;
	for(ll T=1; T<=tc ;T++){
		string a, b; cin>>a>>b;
		solve(a,b);
		for(ll i=0; i<8; i++){
			for(ll j=0; j<8; j++){
				vis[i][j] = 0;
			}
		}
	}
	return 0;
}



bool valid(ll r, ll c){
	return r<8 and r>=0 and c<8 and c>=0;
}

void bfs(ll x, ll y, ll a, ll b){
	vis[x][y] = 1;
	level[x][y] = 0;
	queue<pair<ll,ll>> Q;
	Q.push({x,y});
	while(!Q.empty()){
		pair<ll,ll> u = Q.front();
		Q.pop();
		ll r = u.first, c = u.second;
		if(r == a and c == b) break;
		for(ll i=0; i<8; i++){
			x = r+fx[i], y = c+fy[i];
			if(valid(x,y)){
				if(vis[x][y] == 0){
					vis[x][y] = 1;
					level[x][y] = level[r][c] +1;
					Q.push({x,y});
				}
			}
		}
	}
	cout<<level[a][b]<<"\n";
}

void solve(string a, string b){
	ll x = '8' - a[1], y = a[0] - 'a';
	ll dx = '8' - b[1], dy = b[0] - 'a';
	bfs(x,y,dx,dy);
}


//grid visit

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
const int N=1e3+50;
const int mod=1e9+7;


ll fx[] = {-1,0,1,0};
ll fy[] = {0,1,0,-1};
ll R,C;
ll vis[N][N], level[N][N];
void bfs(ll x, ll y, ll a, ll b);
bool valid(ll r, ll c);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	for(ll T=1; ;T++){
		cin>>R>>C;
		if((R+C) == 0){
			break;
		}
		ll n; cin>>n;
		for(ll i=1; i<=n; i++){
			ll r,a,c; cin>>r>>a;
			for(ll j=1; j<=a; j++){
				cin>>c;
				vis[r][c] = 1;
			}
		}
		ll x, y, a, b; cin>>x>>y>>a>>b;
		bfs(x,y,a,b);
		for(ll i=0; i<N-5; i++){
			for(ll j=0; j<N-5; j++){
				vis[i][j] = 0;
			}
		}
	}
	return 0;
}

bool valid(ll r, ll c){
	return r<R and r>=0 and c<C and c>=0;
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
		for(ll i=0; i<=3; i++){
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


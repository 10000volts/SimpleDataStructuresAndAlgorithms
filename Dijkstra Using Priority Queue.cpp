#include <cstdio>
#include <string.h> 
#include <vector>
#include <queue>

using namespace std;

#define MAX	16384
#define MAXP	524288
static const long long INF = 2147483647;

struct edge{
	int src;
	int dest;
	long long cost;
};

// Number of nodes.
int n;
// Number of edges.
int m;
int i;

// Whether the ith node has been analyzed.
bool ana[MAX];

// The shortest distance from start node to the ith node.
long long dis[MAX];

// Adjacency list.
vector<vector<edge> > al;

// Number of ways that the ith node can choose.
int s[MAXP];

void Dijkstra(int st){
	for (i = 1; i <= n; ++i){
		dis[i] = INF;
	}

	// pq.first : Temporary shortest distance from start node to the ith node. pq.second : the index of the node, means i.
	priority_queue<pair<long long, int> > pq;
	for (i = 0; i < s[st]; ++i){
		edge e = al[st][i];
		pq.push(make_pair(-e.cost, e.dest));
		if(e.cost < dis[e.dest]) dis[e.dest] = e.cost;
	}
	dis[st] = 0;
	ana[st] = true;

	while (!pq.empty()){
		int anai = pq.top().second; pq.pop();
		if (ana[anai]) continue;

		ana[anai] = true; 
		for (int j = 0; j < s[anai]; ++j){
			int dest = al[anai][j].dest;
			if (ana[dest]) continue;
			if (dis[anai] + al[anai][j].cost < dis[dest]){
				dis[dest] = dis[anai] + al[anai][j].cost;
				pq.push(make_pair(-dis[dest], dest));
			}
		}
	}

	for (i = 1; i <= n; ++i){
		printf("%lld", dis[i]);
		if (i < n) putchar(' ');
	}
}

int main(){
	int st;

	scanf("%d%d%d", &n, &m, &st);
	getchar();
	al.resize(n + 1);
	for (i = 1; i <= m; ++i){
		edge e;
		scanf("%d", &e.src);
		scanf("%d", &e.dest);
		scanf("%lld", &e.cost);
		al[e.src].push_back(e);
		++s[e.src];
	}
	getchar();

	Dijkstra(st);

	return 0;
}

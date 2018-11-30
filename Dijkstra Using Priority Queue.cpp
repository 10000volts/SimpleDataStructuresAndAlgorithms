#include <stdio.h>
#include <iostream>
#include <string.h> 
#include <vector>
#include <queue>

using namespace std;

#define MAX		131072
#define MAXP	262144
static const long long INF = 17179869184;

struct edge{
	int src;
	int dest;
	long long cost;
};

// Number of nodes.
int n;
// Number of paths.
int m;
int i;

// Whether the ith node has been analyzed.
bool ana[MAX];

// The shortest path from start node to the ith node.
long long l[MAX];

// Adjacency list.
vector<vector<edge> > al;

// Number of ways that the ith node can choose.
int s[MAXP];


void Dijkstra(int st){
	for (i = 1; i <= n; ++i){
		l[i] = INF;
	}

	// dijk.first : Temporary shortest path from start node to the ith node. dijk.second : the index of the node, means i.
	priority_queue<pair<long long, int> > dijk;
	for (i = 0; i < s[1]; ++i){
		edge e = al[st][i];
		dijk.push(make_pair(e.cost * (-1), e.dest));
		l[e.dest] = e.cost;
	}
	l[st] = 0;
	ana[st] = true;

	while (!dijk.empty()){
		int anai = dijk.top().second;
		dijk.pop();
		if (ana[anai]) continue;

		int j;
		for (j = 0; j < s[anai]; ++j){
			int dest = al[anai][j].dest;
			if (l[anai] + al[anai][j].cost < l[dest]){
				l[dest] = l[anai] + al[anai][j].cost;
				dijk.push(make_pair(l[dest] * (-1), dest));
			}
		}
		ana[anai] = true;
	}

	for (i = 1; i <= n; ++i){
		printf("%lld", l[i]);
		if (i < n) putchar(' ');
	}
}

int main(){
	int st;
	memset(ana, 0, sizeof(ana));
	memset(s, 0, sizeof(s));

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

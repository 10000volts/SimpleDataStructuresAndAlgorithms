#include <iostream>
#include <string.h> 
#include <vector>
#include <queue>

using namespace std;

#define INF		1048576
#define MAX		16384

struct edge{
	int src;
	int dest;
	int cost;
};

// Number of nodes.
int n;
// Number of paths.
int m;
int i;

// Whether the ith node has been analyzed.
bool ana[MAX];

// The shortest path from start node to the ith node.
int l[MAX];

// Adjacency list.
vector<vector<edge> > al;

// Number of ways that the ith node can choose.
int s[MAX];

int Dijkstra(){
	l[0] = 0;
	for (i = 1; i < n; ++i){
		l[i] = INF;
	}

	// dijk.first : Temporary shortest path from start node to the ith node. dijk.second : the index of the node, means i.
	priority_queue<pair<int, int> > dijk;
	for (i = 0; i < s[0]; ++i){
		edge e = al[0][i];
		dijk.push(make_pair(e.cost * (-1), e.dest));
		l[e.dest] = e.cost;
	}
	l[0] = 0;
	ana[0] = true;

	for (i = 1; i < n; ++i){
		int anai = dijk.top().second;
		while (ana[anai]){
			dijk.pop();
			anai = dijk.top().second;
		}

		int j;
		for (j = 0; j < s[anai]; ++j){
			edge te = al[anai][j];
			if (l[anai] + te.cost < l[te.dest]){
				l[te.dest] = l[anai] + te.cost;
				dijk.push(make_pair(l[te.dest] * (-1), te.dest));
			}
		}
		ana[anai] = true;

		dijk.pop();
	}
	return l[n - 1];
}

int main(){
	memset(ana, 0, sizeof(ana));
	memset(s, 0, sizeof(s));

	scanf("%d%d", &n, &m);
	getchar();
	al.resize(n);
	for (i = 0; i < m; ++i){
		edge e;
		scanf("%d", &e.src);
		scanf("%d", &e.dest);
		scanf("%d", &e.cost);
		al[e.src].push_back(e);
		++s[e.src];
	}
	getchar();

	printf("%d", Dijkstra());

	return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cnt = 0;
void BFS(vector<vector<int> >& adj, vector<int>& pre,
		vector<int>& dist, vector<int>& pai, int s0)
{
	cnt = 0;
	int n = adj.size();
	queue<int> fila;
	fila.push(s0);
	pre[s0] = cnt++;
	dist[s0] = 0;


	while(! fila.empty())
	{
		int v = fila.front(); // Pega o 1º da fila
		fila.pop(); // Remove o 1º da fila

		for(int w : adj[v])
		if(pre[w] == -1)
		{
			pre[w] = cnt++;
			pai[w] = v;
			dist[w] = dist[v] + 1;
			fila.push(w);
		}
	}
}

int main()
{

	// Leitura do grafo
	int n, m;
	cin >> n >> m;

	vector<vector<int> > adj(n, vector<int>());
	int v, w;
	for(int i=0; i<m;i++)
	{
		cin >> v >> w;
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	// cout << n << " " << m << endl;

	vector<int> pre(n, -1);
	vector<int> dist(n, -1);
	vector<int> pai(n, -1);

	pai[0] = -1;
	int s0 = 0;
	BFS(adj, pre, dist, pai, s0);

	for(int i=0; i<n; i++)
		cout << "Vertice " << i << " pai " << pai[i] << endl;


	vector<int> caminho;
	int u = 7;
	while(pai[u] != -1)
	{
		caminho.push_back(u);
		u = pai[u];
	}
	caminho.push_back(s0);

	for(int i=caminho.size() - 1; i>=0; i--)
		cout << caminho[i] << " -> ";
	cout << endl;



}

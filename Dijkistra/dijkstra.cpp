#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

#define INF INT_MAX

void mostraAjuda() {
    cout << "Uso: ./dijkstra -f <arquivo_entrada> [-o <arquivo_saida>] [-i <vertice_inicial>] [-h]\n";
    cout << "\t-f <arquivo_entrada> : Especifica o arquivo de entrada com o grafo.\n";
    cout << "\t-o <arquivo_saida>   : Especifica o arquivo de saída. (opcional)\n";
    cout << "\t-i <vertice_inicial> : Especifica o vértice inicial. (padrão = 1)\n";
    cout << "\t-h                  : Mostra esta mensagem de ajuda.\n";
}

void dijkstra(int V, const vector<pair<int, int>> adj[], int origem, FILE* saida) {
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[origem] = 0;
    pq.push(make_pair(0, origem));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int peso = edge.second;

            if (dist[v] > dist[u] + peso) {
                dist[v] = dist[u] + peso;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        fprintf(saida, "%d: %d\n", i + 1, (dist[i] == INF ? -1 : dist[i]));
    }
}

int main(int argc, char* argv[]) {
    FILE *entrada = NULL;
    FILE *saida = stdout;
    int vertice_inicial = 1;

    if (argc < 3) {
        mostraAjuda();
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            mostraAjuda();
            return 0;
        } else if (strcmp(argv[i], "-f") == 0) {
            if (++i < argc) {
                entrada = fopen(argv[i], "r");
                if (!entrada) {
                    fprintf(stderr, "Erro: Não foi possível abrir o arquivo de entrada '%s'\n", argv[i]);
                    return 1;
                }
            } else {
                fprintf(stderr, "Erro: Faltando nome do arquivo de entrada após -f\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-o") == 0) {
            if (++i < argc) {
                saida = fopen(argv[i], "w");
                if (!saida) {
                    fprintf(stderr, "Erro: Não foi possível abrir o arquivo de saída '%s'\n", argv[i]);
                    return 1;
                }
            } else {
                fprintf(stderr, "Erro: Faltando nome do arquivo de saída após -o\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-i") == 0) {
            if (++i < argc) {
                vertice_inicial = atoi(argv[i]);
            } else {
                fprintf(stderr, "Erro: Faltando vértice inicial após -i\n");
                return 1;
            }
        }
    }

    if (!entrada) {
        fprintf(stderr, "Erro: Arquivo de entrada não especificado. Use -f <arquivo>\n");
        return 1;
    }
    int V, E;
    fscanf(entrada, "%d %d", &V, &E);

    vector<pair<int, int>> adj[V];

    int u, v, peso;
    for (int i = 0; i < E; i++) {
        fscanf(entrada, "%d %d %d", &u, &v, &peso);
        adj[u - 1].push_back(make_pair(v - 1, peso));
        adj[v - 1].push_back(make_pair(u - 1, peso));
    }
    fclose(entrada);

    dijkstra(V, adj, vertice_inicial - 1, saida);

    if (saida != stdout) fclose(saida);

    return 0;
}

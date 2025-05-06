#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Aresta {
    int u, v, peso;
};

void mostraAjuda() {
    cout << "Uso: ./kruskal -f <arquivo_entrada> [-o <arquivo_saida>] [-s] [-h]\n";
    cout << "\t-f <arquivo_entrada> : Especifica o arquivo de entrada com o grafo.\n";
    cout << "\t-o <arquivo_saida>   : Especifica o arquivo de saída. (opcional)\n";
    cout << "\t-s                   : Mostra as arestas da MST na saída.\n";
    cout << "\t-h                   : Mostra esta mensagem de ajuda.\n";
}

int find(vector<int> &parent, int u) {
    if (parent[u] != u)
        parent[u] = find(parent, parent[u]);
    return parent[u];
}

void merge(vector<int> &parent, vector<int> &rank, int x, int y) {
    if (rank[x] < rank[y]) {
        parent[x] = y;
    } else if (rank[x] > rank[y]) {
        parent[y] = x;
    } else {
        parent[y] = x;
        rank[x]++;
    }
}

int kruskal(int V, vector<Aresta> &arestas, FILE *saida, bool mostrar_arestas) {
    sort(arestas.begin(), arestas.end(), [](Aresta a, Aresta b) {
        return a.peso < b.peso;
    });

    vector<int> parent(V + 1), rank(V + 1, 0);
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    int peso_total = 0;
    int arestas_mst = 0;

    for (const auto &ar : arestas) {
        int set_u = find(parent, ar.u);
        int set_v = find(parent, ar.v);

        if (set_u != set_v) {
            peso_total += ar.peso;
            arestas_mst++;
            if (mostrar_arestas) {
                fprintf(saida, "%d %d\n", ar.u, ar.v);
            }
            merge(parent, rank, set_u, set_v);
        }
    }

    if (arestas_mst < V - 1) {
        fprintf(stderr, "Aviso: O grafo é desconexo. A MST cobre apenas parte do grafo.\n");
    }

    return peso_total;
}

int main(int argc, char* argv[]) {
    FILE *entrada = NULL;
    FILE *saida = stdout;
    bool mostrar_arestas = false;

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
        } else if (strcmp(argv[i], "-s") == 0) {
            mostrar_arestas = true;
        }
    }

    if (!entrada) {
        fprintf(stderr, "Erro: Arquivo de entrada não especificado. Use -f <arquivo>\n");
        if (saida != stdout) fclose(saida);
        return 1;
    }

    int V, E;
    if (fscanf(entrada, "%d %d", &V, &E) != 2) {
        fprintf(stderr, "Erro: Formato inválido no arquivo de entrada.\n");
        fclose(entrada);
        if (saida != stdout) fclose(saida);
        return 1;
    }

    vector<Aresta> arestas;
    int u, v, peso;
    for (int i = 0; i < E; i++) {
        if (fscanf(entrada, "%d %d %d", &u, &v, &peso) != 3) {
            fprintf(stderr, "Erro: Formato inválido na linha %d do arquivo de entrada.\n", i + 2);
            fclose(entrada);
            if (saida != stdout) fclose(saida);
            return 1;
        }
        if (u < 1 || u > V || v < 1 || v > V) {
            fprintf(stderr, "Erro: Vértice fora do intervalo na linha %d do arquivo de entrada.\n", i + 2);
            fclose(entrada);
            if (saida != stdout) fclose(saida);
            return 1;
        }
        arestas.push_back({u, v, peso});
    }
    fclose(entrada);

    int peso_mst = kruskal(V, arestas, saida, mostrar_arestas);

    if (!mostrar_arestas) {
        fprintf(saida, "%d\n", peso_mst);
    }

    if (saida != stdout) fclose(saida);

    return 0;
}
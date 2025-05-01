#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <tuple>

using namespace std;

void mostraAjuda() {
    printf("Uso: ./bellmanford -f <arquivo_entrada> [-o <arquivo_saida>] [-i <vertice_inicial>] [-h]\n");
    printf("\t-f <arquivo_entrada> : Especifica o arquivo de entrada com o grafo.\n");
    printf("\t-o <arquivo_saida>   : Especifica o arquivo de saída. (opcional)\n");
    printf("\t-i <vertice_inicial> : Especifica o vértice inicial (padrão = 1).\n");
    printf("\t-h                   : Mostra esta mensagem de ajuda.\n");
}

void bellmanFord(int vertices, vector<tuple<int, int, int>>& arestas, int origem, FILE* saida) {
    vector<int> dist(vertices, INT_MAX);
    dist[origem] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        for (const auto& aresta : arestas) {
            int u = get<0>(aresta);
            int v = get<1>(aresta);
            int peso = get<2>(aresta);

            if (dist[u] != INT_MAX && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
            }
        }
    }
    bool ciclo_negativo = false;
    for (const auto& aresta : arestas) {
        int u = get<0>(aresta);
        int v = get<1>(aresta);
        int peso = get<2>(aresta);

        if (dist[u] != INT_MAX && dist[u] + peso < dist[v]) {
            ciclo_negativo = true;
            break;
        }
    }
    if (ciclo_negativo) {
        fprintf(saida, "Erro: Ciclo negativo detectado no grafo!\n");
    } else {
        for (int i = 0; i < vertices; ++i) {
            fprintf(saida, "%d: %d\n", i + 1, (dist[i] == INT_MAX ? -1 : dist[i]));
        }
    }
}


int main(int argc, char *argv[]) {
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

    int vertices, arestas;
    fscanf(entrada, "%d %d", &vertices, &arestas);

    vector<tuple<int, int, int>> lista_arestas;
    int u, v, peso;
    for (int i = 0; i < arestas; i++) {
        fscanf(entrada, "%d %d %d", &u, &v, &peso);
        u--; v--;
        lista_arestas.push_back({u, v, peso});
    }
    fclose(entrada);

    bellmanFord(vertices, lista_arestas, vertice_inicial - 1, saida);

    if (saida != stdout) fclose(saida);

    return 0;
}
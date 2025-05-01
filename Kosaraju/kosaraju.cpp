#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> ordemFinal;

void mostraAjuda() {
    printf("Uso: ./kosaraju -f <arquivo_entrada> [-o <arquivo_saida>] [-h]\n");
    printf("\t-f <arquivo_entrada> : Especifica o arquivo de entrada com o grafo.\n");
    printf("\t-o <arquivo_saida>   : Especifica o arquivo de saida. (opcional)\n");
    printf("\t-h                  : Mostra esta mensagem de ajuda.\n");
}

void DFSrec(vector<vector<int>>& adj, vector<bool>& visitado, int vertice) {
    visitado[vertice] = true;
    for (int vizinho : adj[vertice]) {
        if (!visitado[vizinho]) DFSrec(adj, visitado, vizinho);
    }
    ordemFinal.push_back(vertice); 
}

void DFS(vector<vector<int>>& adj, vector<bool>& visitado) {
    int tamanho = adj.size();
    for (int i = 0; i < tamanho; i++) {
        if (!visitado[i]) DFSrec(adj, visitado, i);
    }
}

void DFSrecTransposto(vector<vector<int>>& transposto, vector<bool>& visitado, int vertice, vector<int>& componente) {
    visitado[vertice] = true;
    componente.push_back(vertice);
    for (int vizinho : transposto[vertice]) {
        if (!visitado[vizinho]) DFSrecTransposto(transposto, visitado, vizinho, componente);
    }
}

int main(int argc, char *argv[]) {
	
    FILE *entrada = NULL;
    FILE *saida = stdout;

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
                    perror("Erro ao abrir arquivo de entrada");
                    return 1;
                }
            } else {
                fprintf(stderr, "Faltando nome do arquivo de entrada após -f\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-o") == 0) {
            if (++i < argc) {
                saida = fopen(argv[i], "w");
                if (!saida) {
                    perror("Erro ao abrir arquivo de saída");
                    return 1;
                }
            } else {
                fprintf(stderr, "Faltando nome do arquivo de saída após -o\n");
                return 1;
            }
        }
    }

    if (!entrada) {
        fprintf(stderr, "Arquivo de entrada não especificado. Use -f <arquivo>\n");
        return 1;
    }


    int vertices, arestas;
    fscanf(entrada, "%d %d", &vertices, &arestas);

    vector<vector<int>> adj(vertices), adj_transposto(vertices);
    int v, a;
    for (int i = 0; i < arestas; i++) {
        fscanf(entrada, "%d %d", &v, &a);
        v--;
        a--;
        adj[v].push_back(a);
        adj_transposto[a].push_back(v); 
    }
    fclose(entrada);

    vector<bool> visitado(vertices, false);
    DFS(adj, visitado);

    reverse(ordemFinal.begin(), ordemFinal.end());
    fill(visitado.begin(), visitado.end(), false);

    vector<vector<int>> componentesFortementeConexos;
    for (int v : ordemFinal) {
        if (!visitado[v]) {
            vector<int> componente;
            DFSrecTransposto(adj_transposto, visitado, v, componente);
            componentesFortementeConexos.push_back(componente);
        }
    }
    for (const auto& componente : componentesFortementeConexos) {
        
        for (int v : componente){
        fprintf(saida, "%d ", v+1);
    }
    fprintf(saida, "\n");
    }

    if (saida != stdout) fclose(saida);


    return 0;
	
}
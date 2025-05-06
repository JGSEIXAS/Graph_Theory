# 📊 Teoria dos Grafos — Implementação de Algoritmos
![C++](https://img.shields.io/badge/C%2B%2B-17-blue?logo=c%2B%2B&logoColor=white)
![Build](https://img.shields.io/badge/build-passing-brightgreen)
![Algoritmos](https://img.shields.io/badge/Algoritmos-Grafos-orange)

Este repositório contém a implementação de algoritmos clássicos de Teoria dos Grafos em C++, desenvolvidos como parte da 2ª VA da disciplina.

---

## 📝 Descrição

O trabalho consiste na implementação de 5 algoritmos de grafos, cada um em sua respectiva pasta, conforme as regras da atividade.

## ⚙️ Regras

O trabalho consiste em implementar 5 algoritmos de grafos em C ou C++.  
Os algoritmos obrigatórios são:

- **Kosaraju** (Componentes Fortemente Conexos)
- **Prim** (Árvore Geradora Mínima)
- **Kruskal** (Árvore Geradora Mínima)
- **Dijkstra** (Caminho Mínimo)
- **Algoritmo de livre escolha**: *Bellman-Ford*

Cada algoritmo possui:

- Código-fonte em C++
- Um arquivo **Makefile** para facilitar a compilação
- Um arquivo **README.md** com instruções específicas do algoritmo
- Binários compilados para execução

---

## 📂 Estrutura do repositório

📂 Graph_Theory/
├── 📂 Bat1/
│   ├── Bat1.sh                # Script principal para testar os algoritmos
│   ├── gabarito_agm.txt       # Gabarito com os pesos corretos das MSTs
│   ├── instances/             # Instâncias de entrada para os algoritmos
│   │   ├── exemp.mtx          # Exemplo de instância
│   │   ├── C125-9.mtx         # Outras instâncias
│   │   └── ...                # Mais arquivos de entrada
│   ├── scc/                   # Resultados esperados para Kosaraju
│   ├── sp/                    # Resultados esperados para Dijkstra
│   ├── ordena.sh              # Script auxiliar para ordenação
│   └── ...                    # Outros arquivos relacionados ao Bat1
├── 📂 Bellman-Ford/
│   ├── Bellman-Ford.cpp       # Implementação do algoritmo de Bellman-Ford
│   ├── Makefile               # Makefile para compilar o Bellman-Ford
│   ├── Bath.sh                # Script para testar o Bellman-Ford
│   └── ...                    # Outros arquivos relacionados
├── 📂 Kruskal/
│   ├── kruskal.cpp            # Implementação do algoritmo de Kruskal
│   ├── Makefile               # Makefile para compilar o Kruskal
│   └── ...                    # Outros arquivos relacionados
├── 📂 Prim/
│   ├── prim.cpp               # Implementação do algoritmo de Prim
│   ├── Makefile               # Makefile para compilar o Prim
│   └── ...                    # Outros arquivos relacionados
├── 📂 Dijkstra/
│   ├── dijkstra.cpp           # Implementação do algoritmo de Dijkstra
│   ├── Makefile               # Makefile para compilar o Dijkstra
│   └── ...                    # Outros arquivos relacionados
├── 📂 Kosaraju/
│   ├── kosaraju.cpp           # Implementação do algoritmo de Kosaraju
│   ├── Makefile               # Makefile para compilar o Kosaraju
│   └── ...                    # Outros arquivos relacionados
├── README.md                  # Descrição geral do projeto
└── ...                        # Outros arquivos ou pastas



---

## ▶️ Instruções Gerais

Cada pasta possui um **README** com detalhes de como compilar, executar e testar o algoritmo.

### Compilação e Execução

```bash
1. Navegue até a pasta do algoritmo desejado:

cd Kruskal/

Compile o programa usando o Makefile:
make
Execute o programa com os parâmetros necessários:
./kruskal.bin -f instances/exemp.mtx

🛠️ Bath e Bat1
  Os scripts Bath.sh e Bat1.sh foram disponibilizados neste repositório para facilitar os testes. Eles incluem:

  Todos os binários compilados.
  Testes automatizados para cada algoritmo.
  Comparação com os gabaritos fornecidos.

  Executando o Bat1.sh
    cd Bat1/
    bash Bat1.sh
  
  Executando o Bath.sh
    cd Bellman-Ford/
    bash Bath.sh
```

👨‍💻 Desenvolvedores :octocat:
**João Gabriel Seixas Santos**
**Marcos Mendonça**

# 📊 Teoria dos Grafos — Implementação de Algoritmos!

Este repositório contém a implementação de algoritmos clássicos de Teoria dos Grafos em **C++**, desenvolvidos como parte da **2ª VA** da disciplina.

## 📝 Descrição

O trabalho consiste na implementação de **5 algoritmos de grafos**, cada um em sua respectiva pasta, conforme as regras da atividade.

### ⚙️ Regras

- O trabalho consiste em implementar **5 algoritmos** de grafos em C ou C++.
- Os algoritmos obrigatórios são:
  1. **Kosaraju** (Componentes Fortemente Conexos)
  2. **Prim** (Árvore Geradora Mínima)
  3. **Kruskal** (Árvore Geradora Mínima)
  4. **Dijkstra** (Caminho Mínimo)
  5. **Algoritmo de livre escolha** (Bellman-Ford)

- Cada algoritmo possui sua **própria pasta**, contendo:
  - O código-fonte
  - Um arquivo **Makefile**
  - Um arquivo **README.md** com instruções específicas do algoritmo
  - O executável/binary correspondente

## 📂 Estrutura do repositório

├── kosaraju/ │ ├── kosaraju.cpp │ ├── Makefile │ ├── README.md │ └── bin/ ├── prim/ │ ├── prim.cpp │ ├── Makefile │ ├── README.md │ └── bin/ ├── kruskal/ │ ├── kruskal.cpp │ ├── Makefile │ ├── README.md │ └── bin/ ├── dijkstra/ │ ├── dijkstra.cpp │ ├── Makefile │ ├── README.md │ └── bin/ ├── algoritmo_extra/ │ ├── extra.cpp │ ├── Makefile │ ├── README.md │ └── bin/ └── README.md ← este arquivo


## ▶️ Instruções gerais

Cada pasta possui um **README** com detalhes de como compilar, executar e testar o algoritmo.

Exemplo de compilação e execução (dentro de cada pasta):

```bash
make
./programa -f entrada.txt -i <nó_inicial> -o saida.txt

🛠️ Bath e Bat1
O Bath e Bat1 foi disponibilizado neste repositório, contendo:

Todos os binários compilados

O binário de Kosaraju (com instruções específicas na respectiva pasta)

👨‍💻 Desenvolvedores :octocat:
João Gabriel Seixas Santos
Marcos Mendonça

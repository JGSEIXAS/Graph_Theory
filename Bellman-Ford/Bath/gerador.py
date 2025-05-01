import random

num_vertices = 500
num_arestas = 100
peso_min = -2
peso_max = 20

with open("tlong_graph1.dat", "w") as f:
    f.write(f"{num_vertices} {num_arestas}\n")
    arestas_criadas = set()
    while len(arestas_criadas) < num_arestas:
        u = random.randint(1, num_vertices)
        v = random.randint(1, num_vertices)
        if u == v:
            continue
        peso = random.randint(peso_min, peso_max)
        aresta = tuple(sorted((u, v)))
        if aresta not in arestas_criadas:
            f.write(f"{u} {v} {peso}\n")
            arestas_criadas.add(aresta)

print("Arquivo tlong_graph1.dat gerado com sucesso.")
INF = 999999999

adj_matrix = [
    [0, 7, 5],
    [7, 0, INF],
    [5, INF, 0]
]

print(adj_matrix)

adj_graph = [[] for _ in range(3)]
adj_graph[0].append((1, 7))
adj_graph[0].append((2, 5))

adj_graph[1].append((0, 7))

adj_graph[2].append((0, 5))

print(adj_graph)

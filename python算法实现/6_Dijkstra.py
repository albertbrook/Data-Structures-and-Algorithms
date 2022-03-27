def find_lowest_cost_node(costs, processed):
    lowest_cost = float("infinity")
    lowest_node = None
    for node in costs:
        if costs[node] < lowest_cost and node not in processed:
            lowest_cost = costs[node]
            lowest_node = node
    return lowest_node


graph = {
    "start": {"a": 6, "b": 2},
    "a": {"finish": 1},
    "b": {"a": 3, "finish": 5},
    "finish": {}
}
costs = {"a": 6, "b": 2, "finish": float("infinity")}
parents = {"a": "start", "b": "start", "finish": None}
processed = []

node = find_lowest_cost_node(costs, processed)
while node is not None:
    processed.append(node)
    for neighbor in graph[node].keys():
        cost = costs[node] + graph[node][neighbor]
        if cost < costs[neighbor]:
            costs[neighbor] = cost
            parents[neighbor] = node
    node = find_lowest_cost_node(costs, processed)
    print(costs)
    print(parents)
    print(processed)
    print()

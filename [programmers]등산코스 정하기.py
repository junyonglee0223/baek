import heapq

max_distance = 100000001

def dijkstra(graph, start, summits_set):
    distances = {node: max_distance for node in graph}
    distances[start] = 0
    queue = [(0, start)]
    
    while queue:
        current_distance, current_node = heapq.heappop(queue)
        #print(current_distance, current_node)           #tset
        if current_distance > distances[current_node]:
            continue
        if current_node in summits_set:
            continue

        for next_node, weight in graph[current_node]:
            distance = max(current_distance, weight)
            if distance < distances[next_node]:
                distances[next_node] = distance
                #print(distance, next_node)          #test
                heapq.heappush(queue, (distance, next_node))
    
    return distances


def solution(n, paths, gates, summits):
    graph = {i: [] for i in range(0, n + 1)}
    for path in paths:
        i, j, w = path
        graph[i].append((j, w))
        graph[j].append((i, w))
    for gate in gates:
        graph[0].append((gate, 0))
    
    #print(graph)            #test
    
    summits_set = set(summits)
    best_summit, min_intensity = 0, max_distance
    
    distances = dijkstra(graph, 0, summits_set)
    for summit in summits:
        if distances[summit] < min_intensity:
            min_intensity = distances[summit]
            best_summit = summit
        elif distances[summit] == min_intensity and summit < best_summit:
            best_summit = summit


    return [best_summit, min_intensity]
    
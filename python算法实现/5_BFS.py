from collections import deque


def get_start(maps):
    for i in range(len(maps)):
        for j in range(len(maps[i])):
            if maps[i][j] == "s":
                return [i, j]


def get_visited(maps):
    visited = [[False for _ in range(len(maps[0]))] for _ in range(len(maps))]
    for i in range(len(maps)):
        for j in range(len(maps[i])):
            if maps[i][j] == "1":
                visited[i][j] = True
    return visited


def get_neighbors(maps, coordinate):
    neighbors = []
    if coordinate[1] - 1 >= 0:
        neighbors.append([coordinate[0], coordinate[1] - 1])
    if coordinate[0] + 1 < len(maps):
        neighbors.append([coordinate[0] + 1, coordinate[1]])
    if coordinate[1] + 1 < len(maps[0]):
        neighbors.append([coordinate[0], coordinate[1] + 1])
    if coordinate[0] - 1 >= 0:
        neighbors.append([coordinate[0] - 1, coordinate[1]])
    return [coordinate] + neighbors


def bfs(maps):
    queue = deque()
    queue += [get_start(maps)]
    visited = get_visited(maps)
    links = []
    while queue:
        coordinate = queue.popleft()
        if visited[coordinate[0]][coordinate[1]]:
            continue
        visited[coordinate[0]][coordinate[1]] = True
        neighbors = get_neighbors(maps, coordinate)
        links.append(neighbors)
        queue += neighbors[1:]
        if maps[coordinate[0]][coordinate[1]] == "t":
            break
    else:
        return None
    routers = [links.pop()[0]]
    links.reverse()
    for link in links:
        if routers[-1] in link[1:]:
            routers.append(link[0])
    return routers[1:-1]


def print_maps(maps, routers):
    if routers is not None:
        for router in routers:
            maps[router[0]][router[1]] = "*"
    for i in range(len(maps[0])):
        for j in range(len(maps)):
            print(maps[j][i], end="  " if j != len(maps) - 1 else "")
        print()


if __name__ == "__main__":
    (x, y) = (9, 6)
    maps = [["0" for _ in range(y)] for _ in range(x)]
    maps[0][0] = "s"
    maps[8][5] = "t"
    for i in range(4):
        maps[2][y - i - 1] = "1"
        maps[4][i] = "1"
        maps[6][y - i - 1] = "1"
    print_maps(maps, bfs(maps))

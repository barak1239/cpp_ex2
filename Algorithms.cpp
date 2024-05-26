//Barak Zalman
// Id: 325706661
//email: barak12395@gmail.com

#include "Algorithms.hpp"
#include <queue>
#include <unordered_set>
#include <limits>
#include <iostream>

namespace ariel {

bool Algorithms::bfs(const Graph& g, int start, std::vector<bool>& visited) {
    std::queue<int> queue;
    visited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        int currVertex = queue.front();
        queue.pop();

        for (int neighbor = 0; neighbor < g.getVertexCount(); neighbor++) {
            if (g.getMatrix()[currVertex][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }

    for (bool v : visited) {
        if (!v)
            return false;
    }

    return true;
}

bool Algorithms::dfs(const Graph& g, int vertex, std::vector<bool>& visited, std::vector<int>& parent) {
    visited[vertex] = true;

    for (int neighbor = 0; neighbor < g.getVertexCount(); neighbor++) {
        if (g.getMatrix()[vertex][neighbor]) {
            if (!visited[neighbor]) {
                parent[neighbor] = vertex;
                if (!dfs(g, neighbor, visited, parent))
                    return false;
            }
        }
    }

    return true;
}

std::string Algorithms::bellmanFordShortestPath(const Graph& g, int start, int end) {
    std::vector<int> dist(g.getVertexCount(), std::numeric_limits<int>::max());
    std::vector<int> parent(g.getVertexCount(), -1);

    dist[start] = 0;

    for (int i = 0; i < g.getVertexCount() - 1; i++) {
        for (int u = 0; u < g.getVertexCount(); u++) {
            for (int v = 0; v < g.getVertexCount(); v++) {
                if (g.getMatrix()[u][v]) {
                    int weight = g.getMatrix()[u][v];
                    if (dist[u] != std::numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        parent[v] = u;
                    }
                }
            }
        }
    }

    for (int u = 0; u < g.getVertexCount(); u++) {
        for (int v = 0; v < g.getVertexCount(); v++) {
            if (g.getMatrix()[u][v]) {
                int weight = g.getMatrix()[u][v];
                if (dist[u] != std::numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    return "Negative cycle detected";
                }
            }
        }
    }

    if (dist[end] == std::numeric_limits<int>::max())
        return "-1";

    std::string path;
    int currVertex = end;
    while (currVertex != -1) {
        path = std::to_string(currVertex) + "->" + path;
        currVertex = parent[currVertex];
    }
    path.pop_back(); 
    path.pop_back(); 

    return path;
}

bool Algorithms::isConnected(const Graph& g) {
    std::vector<bool> visited(g.getVertexCount(), false);

    if (!bfs(g, 0, visited)) {
        return false;
    }

    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }

    if (g.isDirectedGraph()) {
        std::fill(visited.begin(), visited.end(), false);
        std::vector<int> parent(g.getVertexCount(), -1);
        dfs(g, 0, visited, parent);

        for (bool r : visited) {
            if (!r) {
                return false;
            }
        }
    }

    return true;
}

std::string Algorithms::shortestPath(const Graph& g, int start, int end) {
    return Algorithms::bellmanFordShortestPath(g, start, end);
}

bool Algorithms::isContainsCycle(const Graph& g) {
    std::vector<bool> visited(g.getVertexCount(), false);
    std::vector<int> parent(g.getVertexCount(), -1);

    for (int vertex = 0; vertex < g.getVertexCount(); vertex++) {
        if (!visited[vertex]) {
            if (isCyclicUtil(g, vertex, visited, parent, -1)) {
                return true;
            }
        }
    }

    return false;
}

bool Algorithms::isCyclicUtil(const Graph& g, int vertex, std::vector<bool>& visited,
                              std::vector<int>& parent, int parentVertex) {
    visited[vertex] = true;

    for (int neighbor = 0; neighbor < g.getVertexCount(); neighbor++) {
        if (g.getMatrix()[vertex][neighbor]) {
            if (!visited[neighbor]) {
                parent[neighbor] = vertex;
                if (isCyclicUtil(g, neighbor, visited, parent, vertex)) {
                    return true;
                }
            } else if (neighbor != parentVertex) {
                return true;
            }
        }
    }

    return false;
}

std::string Algorithms::isBipartite(const Graph& g) {
    std::vector<int> colorMap(g.getVertexCount(), -1);

    for (int vertex = 0; vertex < g.getVertexCount(); vertex++) {
        if (colorMap[vertex] == -1) {
            if (!isBipartiteUtil(g, vertex, colorMap)) {
                return "The graph is not bipartite";
            }
        }
    }

    std::vector<int> setA, setB;
    for (int vertex = 0; vertex < g.getVertexCount(); vertex++) {
        if (colorMap[vertex] == 1) {
            setA.push_back(vertex);
        } else {
            setB.push_back(vertex);
        }
    }

    std::string result = "The graph is bipartite: A={";
    for (int v : setA) {
        result += std::to_string(v) + ",";
    }
    result.pop_back(); 
    result += "}, B={";
    for (int v : setB) {
        result += std::to_string(v) + ",";
    }
    result.pop_back();
    result += "}";

    return result;
}

bool Algorithms::isBipartiteUtil(const Graph& g, int src, std::vector<int>& colorMap) {
    std::queue<int> queue;
    colorMap[src] = 1;
    queue.push(src);

    while (!queue.empty()) {
        int currVertex = queue.front();
        queue.pop();

        for (int neighbor = 0; neighbor < g.getVertexCount(); neighbor++) {
            if (g.getMatrix()[currVertex][neighbor]) {
                if (colorMap[neighbor] == -1) {
                    colorMap[neighbor] = 1 - colorMap[currVertex];
                    queue.push(neighbor);
                } else if (colorMap[neighbor] == colorMap[currVertex]) {
                    return false;
                }
            }
        }
    }

    return true;
}

void Algorithms::negativeCycle(const Graph& g) {
    std::vector<int> dist(g.getVertexCount(), std::numeric_limits<int>::max());

    dist[0] = 0;

    for (int i = 0; i < g.getVertexCount() - 1; i++) {
        for (int u = 0; u < g.getVertexCount(); u++) {
            for (int v = 0; v < g.getVertexCount(); v++) {
                if (g.getMatrix()[u][v]) {
                    int weight = g.getMatrix()[u][v];
                    if (dist[u] != std::numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }
    }

    for (int u = 0; u < g.getVertexCount(); u++) {
        for (int v = 0; v < g.getVertexCount(); v++) {
            if (g.getMatrix()[u][v]) {
                int weight = g.getMatrix()[u][v];
                if (dist[u] != std::numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    std::cout << "The graph contains a negative cycle" << std::endl;
                    return;
                }
            }
        }
    }

    std::cout << "No negative cycle found" << std::endl;
}

}
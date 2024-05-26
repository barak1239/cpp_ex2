//Barak Zalman
// Id: 325706661
//email: barak12395@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <unordered_map>
#include <string>

namespace ariel {

class Graph {
private:
    std::vector<std::vector<int>> adjacencyMatrix;
    int vertexCount;
    int edgeCount;
    bool directed;

public:
    Graph();
    void loadGraph(const std::vector<std::vector<int>>& matrix);
    void loadDirectedGraph(const std::vector<std::vector<int>>& matrix);
    void printGraph() const;
    std::vector<std::vector<int>> getMatrix() const;
    int getVertexCount() const;
    int getEdgeCount() const;
    bool isDirectedGraph() const;
    Graph getTransposedGraph() const;

    friend Graph operator+(const Graph& lhs, const Graph& rhs);
    Graph& operator+=(const Graph& rhs);
    Graph operator+() const;
    Graph operator-(const Graph& rhs) const;
    Graph& operator-=(const Graph& rhs);
    Graph operator-() const;

    friend bool operator>(const Graph& lhs, const Graph& rhs);
    friend bool operator>=(const Graph& lhs, const Graph& rhs);
    friend bool operator<(const Graph& lhs, const Graph& rhs);
    friend bool operator<=(const Graph& lhs, const Graph& rhs);
    friend bool operator==(const Graph& lhs, const Graph& rhs);
    friend bool operator!=(const Graph& lhs, const Graph& rhs);

    Graph operator*(int scalar) const;
    Graph operator*(const Graph& rhs) const;
    Graph& operator*=(int scalar);
    Graph& operator/=(int scalar);

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
};

}

#endif
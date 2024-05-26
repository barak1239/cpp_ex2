//Barak Zalman
// Id: 325706661
//email: barak12395@gmail.com

#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <limits>

namespace ariel {

Graph::Graph() : vertexCount(0), edgeCount(0), directed(false) {}

void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        throw std::invalid_argument("The input matrix is empty.");
    }

    adjacencyMatrix = matrix;
    vertexCount = matrix.size();
    edgeCount = 0;

    for (int i = 0; i < vertexCount; i++) {
        if (matrix[i].size() != vertexCount) {
            throw std::invalid_argument("The graph is not a square matrix.");
        }
        for (int j = 0; j < vertexCount; j++) {
            if (matrix[i][j] != 0) {
                edgeCount++;
            }
        }
    }

    // Assuming an undirected graph
    directed = false;
}

void Graph::printGraph() const {
    std::cout << "Graph with " << vertexCount << " vertices and " << edgeCount << " edges." << std::endl;
    for (const auto& row : adjacencyMatrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> Graph::getMatrix() const {
    return adjacencyMatrix;
}

int Graph::getVertexCount() const {
    return vertexCount;
}

int Graph::getEdgeCount() const {
    return edgeCount;
}

bool Graph::isDirectedGraph() const {
    return directed;
}

Graph Graph::getTransposedGraph() const {
    Graph transposedGraph;
    std::vector<std::vector<int>> transposedMatrix(vertexCount, std::vector<int>(vertexCount, 0));

    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            transposedMatrix[j][i] = adjacencyMatrix[i][j];
        }
    }

    transposedGraph.loadGraph(transposedMatrix);
    return transposedGraph;
}

Graph operator+(const Graph& g1, const Graph& g2) {
    if (g1.getVertexCount() != g2.getVertexCount()) {
        throw std::invalid_argument("Graphs must have the same number of vertices");
    }

    int n = g1.getVertexCount();
    std::vector<std::vector<int>> resultMatrix(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultMatrix[i][j] = g1.getMatrix()[i][j] + g2.getMatrix()[i][j];
        }
    }

    Graph result;
    result.loadGraph(resultMatrix);

    return result;
}

Graph& Graph::operator+=(const Graph& rhs) {
    if (this->getVertexCount() != rhs.getVertexCount()) {
        throw std::invalid_argument("Graphs must have the same number of vertices");
    }

    int n = this->getVertexCount();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            this->adjacencyMatrix[i][j] += rhs.getMatrix()[i][j];
        }
    }

    return *this;
}

Graph Graph::operator+() const {
    return *this;
}

Graph operator-(const Graph& g1, const Graph& g2) {
    if (g1.getVertexCount() != g2.getVertexCount()) {
        throw std::invalid_argument("Graphs must have the same number of vertices");
    }

    int n = g1.getVertexCount();
    std::vector<std::vector<int>> resultMatrix(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultMatrix[i][j] = g1.getMatrix()[i][j] - g2.getMatrix()[i][j];
        }
    }

    Graph result;
    result.loadGraph(resultMatrix);

    return result;
}

Graph operator-(const Graph& g) {
    int n = g.getVertexCount();
    std::vector<std::vector<int>> resultMatrix(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultMatrix[i][j] = -g.getMatrix()[i][j];
        }
    }

    Graph result;
    result.loadGraph(resultMatrix);

    return result;
}

Graph& Graph::operator-=(const Graph& rhs) {
    if (this->getVertexCount() != rhs.getVertexCount()) {
        throw std::invalid_argument("Graphs must have the same number of vertices");
    }

    int n = this->getVertexCount();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            this->adjacencyMatrix[i][j] -= rhs.getMatrix()[i][j];
        }
    }

    return *this;
}

bool operator>(const Graph& g1, const Graph& g2) {
    return g1.getEdgeCount() > g2.getEdgeCount();
}

bool operator>=(const Graph& g1, const Graph& g2) {
    return g1.getEdgeCount() >= g2.getEdgeCount();
}

bool operator<(const Graph& g1, const Graph& g2) {
    return g1.getEdgeCount() < g2.getEdgeCount();
}

bool operator<=(const Graph& g1, const Graph& g2) {
    return g1.getEdgeCount() <= g2.getEdgeCount();
}

bool operator==(const Graph& g1, const Graph& g2) {
    return g1.getEdgeCount() == g2.getEdgeCount();
}

bool operator!=(const Graph& g1, const Graph& g2) {
    return g1.getEdgeCount() != g2.getEdgeCount();
}

Graph operator*(const Graph& g, int scalar) {
    int n = g.getVertexCount();
    std::vector<std::vector<int>> resultMatrix(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultMatrix[i][j] = g.getMatrix()[i][j] * scalar;
        }
    }

    Graph result;
    result.loadGraph(resultMatrix);

    return result;
}

Graph Graph::operator*(const Graph& rhs) const {
    if (adjacencyMatrix[0].size() != rhs.adjacencyMatrix.size()) {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

    int rows = adjacencyMatrix.size();
    int cols = rhs.adjacencyMatrix[0].size();
    std::vector<std::vector<int>> resultMatrix(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < rhs.adjacencyMatrix.size(); k++) {
                resultMatrix[i][j] += adjacencyMatrix[i][k] * rhs.adjacencyMatrix[k][j];
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        resultMatrix[i][i] = 0;
    }
    
    Graph result;
    if (result.directed == true)
        result.loadDirectedGraph(resultMatrix);
    else
        result.loadGraph(resultMatrix);

    return result;
}

Graph& Graph::operator*=(int scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Cannot multiply graph by 0");
    }

    int n = getVertexCount();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjacencyMatrix[i][j] *= scalar;
        }
    }

    edgeCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjacencyMatrix[i][j] != 0) {
                edgeCount++;
            }
        }
    }

    return *this;
}

Graph& Graph::operator/=(int scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Cannot divide graph by 0");
    }

    int n = getVertexCount();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjacencyMatrix[i][j] /= scalar;
        }
    }

    edgeCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjacencyMatrix[i][j] != 0) {
                edgeCount++;
            }
        }
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    os << "Graph with " << graph.vertexCount << " vertices and " << graph.edgeCount << " edges." << std::endl;
    for (const auto& row : graph.adjacencyMatrix) {
        for (int val : row) {
            os << val << " ";
        }
        os << std::endl;
    }

    return os;
}

void Graph::loadDirectedGraph(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        throw std::invalid_argument("The input matrix is empty.");
    }

    adjacencyMatrix = matrix;
    vertexCount = matrix.size();
    edgeCount = 0;

    for (int i = 0; i < vertexCount; i++) {
        if (matrix[i].size() != vertexCount) {
            throw std::invalid_argument("The graph is not a square matrix.");
        }
        for (int j = 0; j < vertexCount; j++) {
            if (matrix[i][j] != 0) {
                edgeCount++;
            }
        }
    }

    // Consider the graph as directed when loading from a matrix
    directed = true;
}

}
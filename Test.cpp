#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected - Case 1")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Case 2")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Case 3")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath - Case 1")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
}

TEST_CASE("Test shortestPath - Case 2")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
}

TEST_CASE("Test shortestPath - Case 3")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");
}

TEST_CASE("Test isContainsCycle - Case 1")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test isContainsCycle - Case 2")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isContainsCycle - Case 3")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isBipartite - Case 1")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2}, B={1}");
}

TEST_CASE("Test isBipartite - Case 2")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2}, B={1}");
}

TEST_CASE("Test invalid graph - Case 1")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test invalid graph - Case 2")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1},
        {1, 0},
        {0, 0}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test shortestPath - Case 4")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 5, 10, 0},
        {5, 0, 3, 20},
        {10, 3, 0, 1},
        {0, 20, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
}

TEST_CASE("Test isContainsCycle - Case 4")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isBipartite - Case 3")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1,2}");
}

TEST_CASE("Test invalid graph - Case 3")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0},
        {0, 0, 4},
        {0, 0, 0}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test shortestPath - Case 5")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 2, 0},
        {0, 0, 0, 3},
        {0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
}

TEST_CASE("Test isContainsCycle - Case 5")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isBipartite - Case 4")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2}, B={1,3}");
}

TEST_CASE("Test invalid graph - Case 4")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0},
        {0, 0, 4},
        {0, 0, 0}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test shortestPath - Case 6")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
}

TEST_CASE("Test isContainsCycle - Case 6")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test isBipartite - Case 5")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2}, B={1}");
}

TEST_CASE("Test invalid graph - Case 5")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1}};
    CHECK_THROWS(g.loadGraph(graph));
}

#pragma once
#include "Vector.h"
#include "Pair.h"
#include "Sort_func.h"

Vector<int> calculateDegrees(const Vector<Vector<int>>& graph) {
    Vector<int> nodeDegrees(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        nodeDegrees[i] = graph[i].size();
    }
    return nodeDegrees;
}
Vector<int> generateDegreeSeq(const Vector<Vector<int>>& graph) {
    Vector<int> degreesSeq = calculateDegrees(graph);
    for (int i = 0; i < graph.size(); ++i) {
        degreesSeq[i] = graph[i].size();
    }
    mergeSort(degreesSeq, 0, degreesSeq.size() - 1);
    return degreesSeq;
}

void depthFirstSearch(int start, const Vector<Vector<int>>& graph, Vector<bool>& visitedNode) {
    visitedNode[start] = true;
    for (int i = 0; i < graph[start].size(); ++i) {
        int neighbor = graph[start][i];
        if (!visitedNode[neighbor]) depthFirstSearch(neighbor, graph, visitedNode);
    }
}

int findConnectedComponents(const Vector<Vector<int>>& graph) {
    int numOfComponents = 0;
    Vector<bool> visitedNode(graph.size(), false);
    for (int i = 0; i < graph.size(); ++i) {
        if (visitedNode[i] == false) {
            ++numOfComponents;
            depthFirstSearch(i, graph, visitedNode);
        }
    }
    return numOfComponents;
}

long long int countEdgesInComplement(int n, const Vector<Vector<int>>& graph) {
    long long int originalEdges = 0;
    for (int i = 0; i < graph.size(); ++i) {
        originalEdges += graph[i].size();
    }
    originalEdges /= 2; // ka¿da krawêdŸ dwa razy
    long long int totalEdgesInCompleteGraph = (long long int)n * (n - 1) / 2;
    return totalEdgesInCompleteGraph - originalEdges;
}

bool isBipartite(const Vector<Vector<int>>& graph) {
    int n = graph.size();
    Vector<int> colors(n, -1);

    for (int start = 0; start < n; ++start) {
        if (colors[start] == -1) {
            Vector<int> stack;
            stack.push(start);
            colors[start] = 0;

            while (stack.size() > 0) {
                int v = stack[stack.size() - 1];
                stack.pop();

                for (int i = 0; i < graph[v].size(); ++i) {
                    int neighbor = graph[v][i];
                    if (colors[neighbor] == -1) {
                        colors[neighbor] = 1 - colors[v];
                        stack.push(neighbor);
                    }
                    else if (colors[neighbor] == colors[v]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

Vector<int> LFColoring(const Vector<Vector<int>>& graph) {
    int n = graph.size();
    Vector<int> colors(n, -1);
    Vector<bool> available(n, true);

    Vector<Pair<int, int>> degreeVertexPairs;
    for (int i = 0; i < n; ++i) {
        degreeVertexPairs.push(Pair<int, int>(graph[i].size(), i));
    }

    ColorMergeSort(degreeVertexPairs, 0, degreeVertexPairs.size() - 1);

    for (int i = 0; i < degreeVertexPairs.size(); ++i) {
        int u = degreeVertexPairs[i].getSecond();

        for (int j = 0; j < graph[u].size(); ++j) {
            int neighbor = graph[u][j];
            if (colors[neighbor] != -1) {
                available[colors[neighbor]] = false;
            }
        }

        int cr;
        for (cr = 0; cr < n; ++cr) {
            if (available[cr]) {
                break;
            }
        }

        colors[u] = cr;

        for (int j = 0; j < graph[u].size(); ++j) {
            int neighbor = graph[u][j];
            if (colors[neighbor] != -1) {
                available[colors[neighbor]] = true;
            }
        }
    }

    return colors;
}

Vector<int> greedyColoring(const Vector<Vector<int>>& graph) {
    int n = graph.size();
    Vector<int> colors(n, -1);
    Vector<bool> available(n, true);

    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < graph[u].size(); ++i) {
            int neighbor = graph[u][i];
            if (colors[neighbor] != -1) {
                available[colors[neighbor]] = false;
            }
        }

        int cr;
        for (cr = 0; cr < n; ++cr) {
            if (available[cr]) {
                break;
            }
        }

        colors[u] = cr;

        for (int i = 0; i < graph[u].size(); ++i) {
            int neighbor = graph[u][i];
            if (colors[neighbor] != -1) {
                available[colors[neighbor]] = true;
            }
        }
    }

    return colors;
}


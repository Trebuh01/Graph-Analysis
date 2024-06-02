#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Vector.h"
#include "Pair.h"
#include "Sort_func.h"
#include "Algorithms.h"
using namespace std;
void read(Vector<Vector<int>>& graph, int countsVertices) {
    for (int i = 0; i < countsVertices; ++i) {
        int countsNeighbours;
        scanf("%d", &countsNeighbours);

        for (int j = 0; j < countsNeighbours; ++j) {
            int neighbor;
            scanf("%d", &neighbor);
            graph[i].push(neighbor - 1);
        }
    }
}

void DisplayDegreeSequence(const Vector<Vector<int>>& graph) {
    Vector<int> degreeSeq = generateDegreeSeq(graph);

    for (int i = 0; i < degreeSeq.size(); ++i) printf("%d ", degreeSeq[i]);
    
    printf("\n");
}

void DisplayConnectedComponents(const Vector<Vector<int>>& graph) {
    int connectedComp = findConnectedComponents(graph);
    printf("%d\n", connectedComp);
}

void DisplayBipartiteness(const Vector<Vector<int>>& graph) {
    bool isbipartite = isBipartite(graph);
    if (isbipartite) printf("T\n");
    else printf("F\n");

}

void DisplayGreedyColoring(const Vector<Vector<int>>& graph) {
    Vector<int> greedyCol = greedyColoring(graph);
    for (int i = 0; i < greedyCol.size(); ++i) printf("%d ", greedyCol[i] + 1);

    printf("\n");
}

void DisplayLFColoring(const Vector<Vector<int>>& graph) {
    Vector<int> lfCol = LFColoring(graph);
    for (int i = 0; i < lfCol.size(); ++i) printf("%d ", lfCol[i] + 1);
    
    printf("\n");
}

void DisplayComplementEdgesCount(int countVertices, const Vector<Vector<int>>& graph) {
    long long int countComplementEdges = countEdgesInComplement(countVertices, graph);
    printf("%lld\n", countComplementEdges);
}

int main() {
    int numOfGraphs;
    scanf("%d", &numOfGraphs);

    for (int i = 0; i < numOfGraphs; ++i) {
        int numOfVertices;
        scanf("%d", &numOfVertices);

        Vector<Vector<int>> graph(numOfVertices);
        read(graph, numOfVertices);

        DisplayDegreeSequence(graph);
        DisplayConnectedComponents(graph);
        DisplayBipartiteness(graph);
        //skip undone function
        printf("?\n"); 
        printf("?\n"); 

        DisplayGreedyColoring(graph);
        DisplayLFColoring(graph);
        //skip undone function
        printf("?\n"); 
        printf("?\n"); 

        DisplayComplementEdgesCount(numOfVertices, graph);
    }

    return 0;
}



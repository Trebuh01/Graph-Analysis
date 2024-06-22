# Graph Analysis

This project involves analyzing graphs to determine various parameters, including degree sequences, connected components, bipartiteness, and vertex coloring using both greedy and LF methods. The program also calculates the number of edges in the complement of the graph. The entire implementation uses custom vector and pair structures.

## Features

- **Degree Sequence**: Calculate the degree sequence of a graph.
- **Connected Components**: Find the number of connected components in a graph.
- **Bipartiteness**: Check if a graph is bipartite.
- **Vertex Coloring**:
  - Greedy Coloring: Color vertices using a greedy algorithm.
  - LF Coloring: Color vertices using the LF (Largest First) method.
- **Complement Edges**: Calculate the number of edges in the complement of the graph.

## Input Format

The input consists of multiple graphs provided as follows:

1. The first line contains the number of graphs, `k`.
2. For each graph:
   - The first line contains `n`, the number of vertices.
   - The next `n` lines contain the adjacency list for each vertex, where the first number is the count of neighbors `s`, followed by `s` neighbor identifiers (1-based).

## Usage

Compile the project using a C++ compiler. Ensure that the custom `Vector` and `Pair` structures, along with the algorithm and sort functions, are included in your project.

## Custom Vector and Pair Implementations
### Vector
The custom Vector class mimics the behavior of the standard template library's std::vector.

### Pair
The custom Pair class mimics the behavior of the standard template library's std::pair.

### Sort Functions
Sorting functions, including merge sort, have been implemented to sort the custom Vector and Pair structures as required by the algorithms.

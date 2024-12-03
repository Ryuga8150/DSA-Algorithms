# Eulerian Path Algorithm

## Overview

An **Eulerian Path** in a graph is a path that visits every edge exactly once. This project provides an implementation of the Eulerian Path algorithm for directed graphs. The algorithm can determine if an Eulerian Path exists and construct the path if it does.

The implementation is encapsulated in a reusable `EulerianPath` class that supports graph input in two formats:

1. **List of edges** (pairs of source and destination nodes).
2. **Adjacency list** (list of nodes connected to each node).

## Complexity

### Time Complexity

- **O(V + E)**: The algorithm traverses all edges (`E`) and nodes (`V`) during graph traversal and validation.

### Space Complexity

- **O(V + E)**: For storing the graph and recursion stack during DFS.

## Algorithm Steps

The algorithm follows these steps:

### Step 1: Input the Graph

The graph can be provided as:

- A list of edges where each edge is represented as `[source, destination]`.
- An adjacency list where `adjList[i]` contains all nodes reachable from node `i`.

### Step 2: Calculate In-Degrees and Out-Degrees

For each node:

- **In-degree**: The number of edges coming into the node.
- **Out-degree**: The number of edges going out of the node.

These values are used to determine if an Eulerian Path exists.

### Step 3: Check for Eulerian Path

To have an Eulerian Path in a directed graph:

- At most one node should have `out-degree - in-degree = 1` (starting node).
- At most one node should have `in-degree - out-degree = 1` (ending node).
- All other nodes must have equal in-degree and out-degree.

### Step 4: Find the Starting Node

The starting node is:

- The node with `out-degree - in-degree = 1`, if such a node exists.
- Otherwise, any node with outgoing edges can be used as the starting point.

### Step 5: Depth-First Search (DFS)

- Perform a DFS traversal to build the Eulerian Path.
- Remove edges as they are visited to ensure no edge is used more than once.
- Construct the path in reverse order and reverse it at the end to get the correct sequence.

### Step 6: Verify the Path

Ensure that the path contains all the edges in the graph. If not, the graph does not have an Eulerian Path.

## Limitations

### Input Assumptions

- The algorithm assumes the graph is directed.
- All edges must belong to a single connected component if an Eulerian Path exists.

### Disconnected Graphs

- The algorithm will fail if the graph has multiple disconnected components.

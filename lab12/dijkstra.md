# Dijkstra algorithm
> Dijkstra's algorithm can be used to determine the shortest path from one node in a graph to every other node within the same same graph data structure, provided that the nodes are reachable from the starting point.
* This algorithm run in all vertices so it can be used in later.

Rule
1. Every time that we set out to visit a new node, we will choose the node with the smallest known distance/cost to visit first.
2. Once we’ve moved to the node we’re going to visit, we will check each of its neighboring nodes.
3. For each neighboring node, we’ll calculate the distance/cost for the neighboring nodes by summing the cost of the edges that lead to the node we’re checking from the starting vertex.
4. Finally, if the distance/cost to a node is less than a known distance, we’ll update the shortest distance that we have on file for that vertex.
#pragma once
#include "NonOrientedGraph.h"

template <typename T>
class Graph<T>::AdjacentVertexIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = vertex_type;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

private:
    Graph* graph;
    size_t vertex;
    size_t adj_index;

public:
    AdjacentVertexIterator(Graph* g, size_t v, size_t idx): graph(g), vertex(v), adj_index(idx) 
    {
    while (adj_index < graph->vertex_count() && !graph->has_edge(vertex, adj_index)) {
            adj_index++;
        }
    }   

    reference operator*()
    {
        return graph->vertices[adj_index];
    }

    AdjacentVertexIterator& operator++()
    {
    adj_index++;
        while (adj_index < graph->vertex_count() && !graph->has_edge(vertex, adj_index)) {
            adj_index++;
        }
    return *this;
    }

    bool operator!=(const AdjacentVertexIterator& other) const
    {
    return vertex != other.vertex || adj_index != other.adj_index;
    }

    bool operator==(const AdjacentVertexIterator& other) const
    {
    return vertex == other.vertex || adj_index == other.adj_index;
    }

};
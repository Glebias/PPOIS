#pragma once
#include "NonOrientedGraph.h"

template <typename T>
class Graph<T>::IncidentEdgeIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = edge_type;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

private:
    Graph* graph;
    size_t vertex;
    size_t edge_index;

public:
    IncidentEdgeIterator(Graph* g, size_t v, size_t idx): graph(g), vertex(v), edge_index(idx) 
    {
    while (edge_index < graph->vertex_count() && !graph->has_edge(vertex, edge_index)) {
        edge_index++;
    }
}

    edge_type operator*() {
        return edge_type(vertex, edge_index);
    }

    IncidentEdgeIterator& operator++() 
    {
        edge_index++;
        while (edge_index < graph->vertex_count() && !graph->has_edge(vertex, edge_index)) {
            edge_index++;
        }
    return *this;
    }
    
    bool operator!=(const IncidentEdgeIterator& other) const
    {
        return vertex != other.vertex || edge_index != other.edge_index;
    }

    bool operator==(const IncidentEdgeIterator& other) const
    {
        return vertex == other.vertex || edge_index == other.edge_index;
    }

};
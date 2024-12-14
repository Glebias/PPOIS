#pragma once
#include "NonOrientedGraph.h"

template <typename T>
class Graph<T>::EdgeIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = edge_type;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

private:
    Graph* graph;
    size_t start_vertex, end_vertex;

public:
    EdgeIterator(Graph* g, size_t start_u, size_t start_v) : graph(g), start_vertex(start_u), end_vertex(start_v) {
    while (start_vertex < graph->vertex_count() && end_vertex < graph->vertex_count() && !graph->has_edge(start_vertex, end_vertex)) {
        if (++end_vertex >= graph->vertex_count()) {
            start_vertex++;
            end_vertex = start_vertex + 1;
        }
    }
}

    edge_type operator*() {
        return edge_type(start_vertex, end_vertex);
    }

    EdgeIterator& operator++(){
    v++;
    while (start_vertex < graph->vertex_count() && end_vertex < graph->vertex_count() && !graph->has_edge(start_vertex, end_vertex)) {
        if (++end_vertex >= graph->vertex_count()) {
            start_vertex++;
            end_vertex = start_vertex + 1;
        }
    }
    return *this;
}

    bool operator!=(const EdgeIterator& other) const{
    return start_vertex != other.start_vertex || end_vertex != other.end_vertex;
}

bool operator==(const EdgeIterator& other) const{
    return start_vertex == other.start_vertex || end_vertex == other.end_vertex;
}
};
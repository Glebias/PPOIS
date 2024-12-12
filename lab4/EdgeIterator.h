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
    size_t u, v;

public:
    EdgeIterator(Graph* g, size_t start_u, size_t start_v) : graph(g), u(start_u), v(start_v) {
    while (u < graph->vertex_count() && v < graph->vertex_count() && !graph->has_edge(u, v)) {
        if (++v >= graph->vertex_count()) {
            u++;
            v = u + 1;
        }
    }
}

    edge_type operator*() {
        return edge_type(u, v);
    }

    EdgeIterator& operator++(){
    v++;
    while (u < graph->vertex_count() && v < graph->vertex_count() && !graph->has_edge(u, v)) {
        if (++v >= graph->vertex_count()) {
            u++;
            v = u + 1;
        }
    }
    return *this;
}

    bool operator!=(const EdgeIterator& other) const{
    return u != other.u || v != other.v;
}

bool operator==(const EdgeIterator& other) const{
    return u == other.u || v == other.v;
}
};
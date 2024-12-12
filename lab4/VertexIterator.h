#pragma once
#include "NonOrientedGraph.h"

template <typename T>
class Graph<T>::VertexIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = vertex_type;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

private:
    Graph* graph;
    size_t index;

public:
    VertexIterator(Graph* g, size_t idx): graph(g), index(idx) {}

    reference operator*()
    {
        return graph->vertices[index];
    }

    pointer operator->()
    {
        return &graph->vertices[index];
    }

    VertexIterator& operator++()
    {
        index++;
        return *this;
    }

    VertexIterator& operator--()
    {
        index--;
        return *this;
    }

    bool operator!=(const VertexIterator& other) const
    {
        return index != other.index;
    }

    bool operator==(const VertexIterator& other) const
    {
        return index == other.index;
    }

};
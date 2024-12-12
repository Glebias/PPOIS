#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <iterator>
#include <algorithm>

template <typename T>
class Graph {
public:
    using vertex_type = T;
    using edge_type = std::pair<int, int>;
    using reference = vertex_type&;
    using const_reference = const vertex_type&;
    using pointer = vertex_type*;
    using const_pointer = const vertex_type*;
    using size_type = size_t;

private:
    std::vector<vertex_type> vertices;
    std::vector<std::vector<bool>> adjacency_matrix;

public:
    Graph();
    Graph(const Graph& other);
    ~Graph();

    bool empty() const;
    void clear();

    bool has_vertex(const vertex_type& vertex) const;
    bool has_edge(size_t u, size_t v) const;

    size_t vertex_count() const;
    size_t edge_count() const;
    size_t degree(size_t vertex) const;

    void add_vertex(const vertex_type& vertex);
    void add_edge(size_t u, size_t v);
    void remove_vertex(size_t vertex);
    void remove_edge(size_t u, size_t v);

    class VertexIterator;
    class EdgeIterator;
    class IncidentEdgeIterator;
    class AdjacentVertexIterator;

    VertexIterator begin();
    VertexIterator end();

    EdgeIterator edges_begin();
    EdgeIterator edges_end();

    IncidentEdgeIterator incident_edges_begin(size_t vertex);
    IncidentEdgeIterator incident_edges_end(size_t vertex);

    AdjacentVertexIterator adjacent_vertices_begin(size_t vertex);
    AdjacentVertexIterator adjacent_vertices_end(size_t vertex);

    void remove_vertex(VertexIterator it);
    void remove_edge(EdgeIterator it);

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        for (size_t i = 0; i < graph.vertex_count(); ++i) {
            os << graph.vertices[i] << ": ";
            for (size_t j = 0; j < graph.vertex_count(); ++j) {
                if (graph.has_edge(i, j)) {
                    os << graph.vertices[j] << " ";
                }
            }
            os << std::endl;
        }
        return os;
    }
};









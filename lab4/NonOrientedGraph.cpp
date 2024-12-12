#include "NonOrientedGraph.h"
#include "VertexIterator.h"

// Реализация методов класса Graph
template <typename T>
Graph<T>::Graph() = default;

template <typename T>
Graph<T>::Graph(const Graph& other) 
    : vertices(other.vertices), adjacency_matrix(other.adjacency_matrix) {}

template <typename T>
Graph<T>::~Graph() = default;

template <typename T>
bool Graph<T>::empty() const {
    return vertices.empty();
}

template <typename T>
void Graph<T>::clear() {
    vertices.clear();
    adjacency_matrix.clear();
}

template <typename T>
bool Graph<T>::has_vertex(const vertex_type& vertex) const {
    return std::find(vertices.begin(), vertices.end(), vertex) != vertices.end();
}

template <typename T>
bool Graph<T>::has_edge(size_t u, size_t v) const {
    if (u >= vertices.size() || v >= vertices.size()) {
        throw std::out_of_range("Vertex index out of range");
    }
    return adjacency_matrix[u][v];
}

template <typename T>
size_t Graph<T>::vertex_count() const {
    return vertices.size();
}

template <typename T>
size_t Graph<T>::edge_count() const {
    size_t count = 0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        for (size_t j = i + 1; j < vertices.size(); ++j) {
            if (adjacency_matrix[i][j]) {
                count++;
            }
        }
    }
    return count;
}

template <typename T>
size_t Graph<T>::degree(size_t vertex) const {
    if (vertex >= vertices.size()) {
        throw std::out_of_range("Vertex index out of range");
    }
    return std::count(adjacency_matrix[vertex].begin(), adjacency_matrix[vertex].end(), true);
}

template <typename T>
void Graph<T>::add_vertex(const vertex_type& vertex) {
    vertices.push_back(vertex);
    size_t new_size = vertices.size();
    adjacency_matrix.resize(new_size, std::vector<bool>(new_size, false));
    for (size_t i = 0; i < new_size - 1; ++i) {
        adjacency_matrix[i].resize(new_size, false);
    }
}

template <typename T>
void Graph<T>::add_edge(size_t u, size_t v) {
    if (u >= vertices.size() || v >= vertices.size()) {
        throw std::out_of_range("Vertex index out of range");
    }
    adjacency_matrix[u][v] = true;
    adjacency_matrix[v][u] = true; // Неориентированный граф
}

template <typename T>
void Graph<T>::remove_vertex(size_t vertex) {
    if (vertex >= vertices.size()) {
        throw std::out_of_range("Vertex index out of range");
    }
    vertices.erase(vertices.begin() + vertex);
    adjacency_matrix.erase(adjacency_matrix.begin() + vertex);
    for (auto& row : adjacency_matrix) {
        row.erase(row.begin() + vertex);
    }
}

template <typename T>
void Graph<T>::remove_edge(size_t u, size_t v) {
    if (u >= vertices.size() || v >= vertices.size()) {
        throw std::out_of_range("Vertex index out of range");
    }
    adjacency_matrix[u][v] = false;
    adjacency_matrix[v][u] = false; // Неориентированный граф
}

template <typename T>
typename Graph<T>::VertexIterator Graph<T>::begin() {
    return VertexIterator(this, 0); // Начинаем с первой вершины
}

template <typename T>   
typename Graph<T>::VertexIterator Graph<T>::end() {
    return VertexIterator(this, vertex_count()); // Конец за пределами последней вершины
}

template <typename T> 
typename Graph<T>::EdgeIterator Graph<T>::edges_begin() {
    return EdgeIterator(this, 0, 1); // Начинаем с первого возможного ребра
}

template <typename T>
typename Graph<T>::EdgeIterator Graph<T>::edges_end() {
    return EdgeIterator(this, vertex_count(), 0); // Конец за пределами возможных рёбер
}

template <typename T>
typename Graph<T>::IncidentEdgeIterator Graph<T>::incident_edges_begin(size_t vertex) {
    return IncidentEdgeIterator(this, vertex, 0); // Начинаем с первого возможного ребра
}

template <typename T>
typename Graph<T>::IncidentEdgeIterator Graph<T>::incident_edges_end(size_t vertex) {
    return IncidentEdgeIterator(this, vertex, vertex_count()); // Конец за пределами возможных рёбер
}

template <typename T>
typename Graph<T>::AdjacentVertexIterator Graph<T>::adjacent_vertices_begin(size_t vertex) {
    return AdjacentVertexIterator(this, vertex, 0); // Начинаем с первой возможной смежной вершины
}

template <typename T>
typename Graph<T>::AdjacentVertexIterator Graph<T>::adjacent_vertices_end(size_t vertex) {
    return AdjacentVertexIterator(this, vertex, vertex_count()); // Конец за пределами возможных смежных вершин
}
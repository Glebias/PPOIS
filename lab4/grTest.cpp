#include <gtest/gtest.h>
#include "NonOrientedGraph.h"
#include "NonOrientedGraph.cpp" 
#include "EdgeIterator.h"
#include "VertexIterator.h"
#include "AdjacentVertexIterator.h"
#include "IncidentEdgeIterator.h"
#include <string>

class GraphTest : public ::testing::Test {
protected:
    Graph<std::string> graph;

    void SetUp() override {
        // Добавляем вершины
        graph.add_vertex("A");
        graph.add_vertex("B");
        graph.add_vertex("C");
        graph.add_vertex("D");

        // Добавляем рёбра
        graph.add_edge(0, 1); // A <-> B
        graph.add_edge(1, 2); // B <-> C
        graph.add_edge(2, 3); // C <-> D
    }
};

// Основные тесты
TEST_F(GraphTest, VertexCount) {
    EXPECT_EQ(graph.vertex_count(), 4);
}

TEST_F(GraphTest, EdgeCount) {
    EXPECT_EQ(graph.edge_count(), 3);
}

TEST_F(GraphTest, HasVertex) {
    EXPECT_TRUE(graph.has_vertex("A"));
    EXPECT_FALSE(graph.has_vertex("E"));
}

TEST_F(GraphTest, HasEdge) {
    EXPECT_TRUE(graph.has_edge(0, 1)); // A <-> B
    EXPECT_FALSE(graph.has_edge(0, 2)); // A <-> C
}

TEST_F(GraphTest, Degree) {
    EXPECT_EQ(graph.degree(1), 2); // Вершина B имеет степень 2
}

TEST_F(GraphTest, AddVertex) {
    graph.add_vertex("E");
    EXPECT_EQ(graph.vertex_count(), 5);
    EXPECT_TRUE(graph.has_vertex("E"));
}

TEST_F(GraphTest, RemoveVertex) {
    graph.remove_vertex(1); // Удаляем B
    EXPECT_EQ(graph.vertex_count(), 3);
    EXPECT_FALSE(graph.has_vertex("B"));
    EXPECT_FALSE(graph.has_edge(0, 1)); // A <-> B больше не существует
}

TEST_F(GraphTest, AddEdge) {
    graph.add_edge(0, 2); // A <-> C
    EXPECT_TRUE(graph.has_edge(0, 2));
}

TEST_F(GraphTest, RemoveEdge) {
    graph.remove_edge(0, 1); // Удаляем A <-> B
    EXPECT_FALSE(graph.has_edge(0, 1));
}

// Тесты для итераторов
TEST_F(GraphTest, VertexIterator) {
    auto it = graph.begin();
    EXPECT_EQ(*it, "A"); // Первая вершина

    ++it;
    EXPECT_EQ(*it, "B"); // Вторая вершина

    ++it;
    EXPECT_EQ(*it, "C"); // Третья вершина

    ++it;
    EXPECT_EQ(*it, "D"); // Четвертая вершина

    ++it;
    EXPECT_EQ(it, graph.end()); // Достигли конца
}

TEST_F(GraphTest, EdgeIterator) {
    auto it = graph.edges_begin();
    EXPECT_EQ(*it, std::make_pair(0, 1)); // A <-> B

    // ++it;
    // EXPECT_EQ(*it, std::make_pair(1, 2)); // B <-> C

    // ++it;
    // EXPECT_EQ(*it, std::make_pair(2, 3)); // C <-> D

    // ++it;
    // EXPECT_EQ(it, graph.edges_end()); // Достигли конца
}

TEST_F(GraphTest, IncidentEdgeIterator) {
    auto it = graph.incident_edges_begin(1); // Вершина B
    EXPECT_EQ(*it, std::make_pair(1, 0)); // B <-> A

    ++it;
    EXPECT_EQ(*it, std::make_pair(1, 2)); // B <-> C

    ++it;
    EXPECT_EQ(it, graph.incident_edges_end(1)); // Достигли конца
}

TEST_F(GraphTest, AdjacentVertexIterator) {
    auto it = graph.adjacent_vertices_begin(1); // Вершина B
    EXPECT_EQ(*it, "A"); // Смежная вершина A

    ++it;
    EXPECT_EQ(*it, "C"); // Смежная вершина C

    ++it;
    EXPECT_EQ(it, graph.adjacent_vertices_end(1)); // Достигли конца
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
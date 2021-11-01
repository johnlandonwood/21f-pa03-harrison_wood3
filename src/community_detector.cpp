#include <iostream>
#include <fstream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/graphml.hpp>
#include <boost/property_map/dynamic_property_map.hpp>
#include "community_detector.h"
using std::cout;
using std::endl;

boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>
create_empty_undirected_graph() noexcept {
    return {};
}

template <typename graph> std::pair<typename graph::vertex_iterator, typename graph::vertex_iterator>
get_vertex_iterators(const graph& g) noexcept {
    return vertices(g);
}

template <typename graph> std::vector<typename boost::graph_traits<graph>::vertex_descriptor>
get_vertex_descriptors(const graph& g) noexcept {
    using vd = typename graph::vertex_descriptor;

    std::vector<vd>  vds(boost::num_vertices(g));
    const auto vis = vertices(g);
    std::copy(vis.first, vis.second, std::begin(vds));
    return vds;
}

template <typename graph> typename boost::graph_traits<graph>::edge_descriptor
add_edge(graph& g) noexcept {
    const auto vd_a = boost::add_vertex(g);
    const auto vd_b = boost::add_vertex(g);
    const auto aer = boost::add_edge(vd_a, vd_b, g);

    return aer.first;
}

template <typename graph> std::pair<typename graph::edge_iterator, typename graph::edge_iterator>
get_edge_iterators(const graph& g) {
    return edges(g);
}

template <typename graph> std::vector<typename boost::graph_traits<graph>::edge_descriptor>
get_edge_descriptors(const graph& g) noexcept {
    using ed = typename boost::graph_traits<graph>::edge_descriptor;

    std::vector<ed> v(boost::num_edges(g));
    const auto eip = edges(g);
    std::copy(eip.first, eip.second, std::begin(v));
    return v;
}

template <typename graph> std::vector<int> get_vertex_out_degrees(const graph& g) noexcept {
    using vd = typename graph::vertex_descriptor;

    std::vector<int> v(boost::num_vertices(g));
    const auto vip = vertices(g);
    std::transform(vip.first, vip.second, std::begin(v), [&g](const vd&d) {
            return out_degree(d,g);
        }
    );
    return v;
}

template <typename graph> bool has_edge_between_vertices(
        const typename boost::graph_traits<graph>::vertex_descriptor& vd_1,
        const typename boost::graph_traits<graph>::vertex_descriptor& vd_2,
        const graph& g
        ) noexcept {
    return edge(vd_1, vd_2, g).second;
}

template <typename graph> typename boost::graph_traits<graph>::edge_descriptor
get_edge_between_vertices(
        const typename boost::graph_traits<graph>::vertex_descriptor& vd_from,
        const typename boost::graph_traits<graph>::vertex_descriptor& vd_to,
        const graph& g
        ) {
    const auto er = edge(vd_from, vd_to, g);
    if (!er.second) {
        std::stringstream msg;
        msg << "no_edge_between_these_vertices" << endl;
        throw std::invalid_argument(msg.str());
    }
    return er.first;
}

community_detector::community_detector() {
//    this->graph = create_empty_undirected_graph();
}

void community_detector::run() {


//    graph = create_empty_undirected_graph();
//    const auto vd_a = boost::add_vertex(graph);
//    const auto vd_b = boost::add_vertex(graph);
//    const auto vd_c = boost::add_vertex(graph);
//    boost::add_edge(vd_a, vd_b, graph);
//    boost::add_edge(vd_b, vd_c, graph);
//    boost::add_edge(vd_c, vd_a, graph);
//
//    std::vector<int> out_degrees = get_vertex_out_degrees(graph);
//
//    int vertices = boost::num_vertices(graph);
//    int edges = boost::num_edges(graph);
//
//    cout << "Vertices: " << vertices << endl << "Edges: " << edges << endl;
//    cout << "Out degrees: ";
//    for (int i : out_degrees) {
//        cout << i << " ";
//    }
//    cout << endl;
//
    boost::dynamic_properties dp;
    std::ifstream football(R"(C:\cygwin64\home\Owner\classes\CS3353\21f-pa03-harrison_wood3\input\football.graphml)");
    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> f_graph;
    boost::read_graphml(football, f_graph, dp);
    football.close();

//    std::ifstream football("cmake-build-debug/output.graphml");
//    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> f_graph;
//    boost::read_graphml(football, f_graph, dp);
//    football.close();


    int f_vertices = boost::num_vertices(f_graph);
    int f_edges = boost::num_edges(f_graph);
    std::vector<int> f_out_degrees = get_vertex_out_degrees(f_graph);

    cout << "f_vertices: " << f_vertices << endl << "f_edges: " << f_edges << endl;
    cout << "f_out_degrees: ";
    for (int i : f_out_degrees) {
        cout << i << " ";
    }
    cout << endl;


}



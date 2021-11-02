#ifndef COMMUNITY_DETECTION_COMMUNITY_DETECTOR_H
#define COMMUNITY_DETECTION_COMMUNITY_DETECTOR_H
#include <boost/graph/adjacency_list.hpp>

struct graph_node {
    long node_id;
    std::string label;
    long value;
};

class community_detector {
private:
    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, graph_node> graph;
public:
    community_detector();
    void read_graph(std::ifstream& input);
    void run();
};


#endif //COMMUNITY_DETECTION_COMMUNITY_DETECTOR_H

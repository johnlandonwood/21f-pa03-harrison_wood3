#ifndef COMMUNITY_DETECTION_COMMUNITY_DETECTOR_H
#define COMMUNITY_DETECTION_COMMUNITY_DETECTOR_H
#include <boost/graph/adjacency_list.hpp>


class community_detector {
private:
    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> graph;
public:
    community_detector();
    void run();
};


#endif //COMMUNITY_DETECTION_COMMUNITY_DETECTOR_H

#ifndef TEST_KONTUR_GRAPH_H
#define TEST_KONTUR_GRAPH_H

#include <string>
#include <vector>
#include "data.h"

using namespace std;

class Graph {
private:
    bool **matrix;
    string *name;
    int cntName;
public:
    Graph(child* ch, int chSize, sympathy* sym, int symSize);
    vector<string> getUnloved();
    vector<string> getUnhappy();
    vector<string> getFavorite();
    virtual ~Graph();
};

#endif //TEST_KONTUR_GRAPH_H
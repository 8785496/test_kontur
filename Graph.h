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
    Graph(const child* ch, int chSize, const sympathy* sym, int symSize);
    vector<string> getUnloved() const;
    vector<string> getUnhappy() const;
    vector<string> getFavorite() const;
    virtual ~Graph();
};

#endif //TEST_KONTUR_GRAPH_H
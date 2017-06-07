#include <vector>
#include "Graph.h"

Graph::Graph(child *ch, int chSize, sympathy *sym, int symSize) {
    cntName = chSize;
    name = new string[chSize];
    for (int i = 0; i < chSize; ++i) {
        name[ch[i].id] = ch[i].name;
    }

    cntSympathy = symSize;
    matrix = new bool*[symSize];
    for (int k = 0; k < symSize; ++k) {
        matrix[k] = new bool[symSize];
        for (int p = 0; p < symSize; ++p) {
            matrix[k][p] = false;
        }
    }

    for (int j = 0; j < symSize; ++j) {
        matrix[sym[j].from][sym[j].to] = true;
    }
}

Graph::~Graph() {
    delete[] name;
    for (int i = 0; i < cntSympathy; ++i) {
        delete[] matrix[i];
    }
}

vector<string*> Graph::getUnloved() {
    vector<string*> result;

    for (int j = 0; j < cntSympathy; ++j) {
        int sum = 0;
        for (int i = 0; i < cntSympathy; ++i)
            if(matrix[i][j])
                sum++;
        if (sum == 0)
            result.push_back(&name[j]);
    }

    return result;
}

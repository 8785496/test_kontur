#include <vector>
#include "Graph.h"

Graph::Graph(child *ch, int chSize, sympathy *sym, int symSize) {
    cntName = chSize;
    name = new string[chSize];
    for (int i = 0; i < chSize; ++i) {
        name[ch[i].id] = ch[i].name;
    }

    matrix = new bool*[cntName];
    for (int k = 0; k < cntName; ++k) {
        matrix[k] = new bool[cntName];
        for (int p = 0; p < cntName; ++p) {
            matrix[k][p] = false;
        }
    }

    for (int j = 0; j < symSize; ++j) {
        matrix[sym[j].from][sym[j].to] = true;
    }
}

Graph::~Graph() {
    delete[] name;
    for (int i = 0; i < cntName; ++i) {
        delete[] matrix[i];
    }
}

vector<string> Graph::getUnloved() {
    vector<string> result;

    for (int j = 0; j < cntName; ++j) {
        int sum = 0;
        for (int i = 0; i < cntName; ++i)
            if(matrix[i][j])
                sum++;
        if (sum == 0)
            result.push_back(name[j]);
    }

    return result;
}

vector<string> Graph::getUnhappy() {
    vector<string> result;

    for (int i = 0; i < cntName; ++i) {
        int multi = 0;
        int sum = 0;
        for (int j = 0; j < cntName; ++j) {
            if (matrix[i][j])
                sum++;
            multi += matrix[i][j] * matrix[j][i];
        }
        if (sum > 0 && multi == 0)
            result.push_back(name[i]);
    }

    return result;
}
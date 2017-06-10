#include <iostream>
#include <fstream>
#include "Reader.h"

using namespace std;

Reader::Reader(const char *fNameChild, const char *fNameSympathy) {
    cntChild = fileSize(fNameChild) / sizeof(child);
    cntSympathy = fileSize(fNameSympathy) / sizeof(sympathy);

    _child = new child[cntChild];
    ifstream finc(fNameChild, ios::binary | ios::in);
    finc.read((char*)_child, cntChild * sizeof(child));
    finc.close();

    _sympathy = new sympathy[cntSympathy];
    ifstream fins(fNameSympathy, ios::binary | ios::in);
    fins.read((char*)_sympathy, cntSympathy * sizeof(sympathy));
    fins.close();
}

Reader::~Reader() {
    delete[] _child;
    delete[] _sympathy;
}

int Reader::fileSize(const char *fileName) {
    ifstream fin(fileName, ios::in | ios::binary);
    if (!fin.is_open()) {
        cerr << "File '" << fileName <<  "' don't open" << endl;
        throw new exception();
    }
    fin.seekg(0, ios::end);
    int size = fin.tellg();
    fin.close();
    return size;
}

child *Reader::getChild() {
    return _child;
}

sympathy *Reader::getSympathy() {
    return _sympathy;
}

int Reader::getCntChild() {
    return cntChild;
}

int Reader::getCntSympathy() {
    return cntSympathy;
}

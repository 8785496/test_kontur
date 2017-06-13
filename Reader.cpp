#include <iostream>
#include <fstream>
#include <cstring>
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
        char *buff = new char[17 + strlen(fileName)];
        sprintf(buff, "File '%s' not open", fileName);
        throw Exception(buff);
    }
    fin.seekg(0, ios::end);
    int size = fin.tellg();
    fin.close();
    return size;
}

const child *Reader::getChild() const {
    return _child;
}

const sympathy *Reader::getSympathy() const {
    return _sympathy;
}

int Reader::getCntChild() const {
    return cntChild;
}

int Reader::getCntSympathy() const {
    return cntSympathy;
}

const char *Reader::Exception::what() const throw() {
    return _message;
}

Reader::Exception::~Exception() {
    delete[] _message;
}

Reader::Exception::Exception(const char *message) {
    _message = message;
}

#pragma once
#include "data.h"

class Reader {
private:
    child* _child;
    sympathy* _sympathy;
    int cntChild, cntSympathy;
    int fileSize(const char* fileName);
public:
    Reader(const char* fNameChild, const char* fNameSympathy);
    child* getChild();
    sympathy* getSympathy();
    int getCntChild();
    int getCntSympathy();
    virtual ~Reader();
};

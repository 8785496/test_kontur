#ifndef TEST_KONTUR_READER_H
#define TEST_KONTUR_READER_H

#include <exception>
#include "data.h"

class Reader {
private:
    const child* _child;
    const sympathy* _sympathy;
    int cntChild, cntSympathy;
    int fileSize(const char* fileName);
public:
    Reader(const char* fNameChild, const char* fNameSympathy);
    const child* getChild() const;
    const sympathy* getSympathy() const;
    int getCntChild() const;
    int getCntSympathy() const;
    virtual ~Reader();
    class Exception : std::exception {
    private:
        const char* _message;
    public:
        Exception(const char* message);
        const char *what() const throw();
        ~Exception();
    };
};

#endif //TEST_KONTUR_READER_H

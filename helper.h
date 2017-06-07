#include <iostream>
#include <fstream>
#include <string.h>
#include "data.h"

using namespace std;

void writeFiles() {
    child* children = new child[6];
    children[0].id = 0; strcpy(children[0].name,"Fedor");
    children[1].id = 1; strcpy(children[1].name,"Lena");
    children[2].id = 2; strcpy(children[2].name,"Vasya");
    children[3].id = 3; strcpy(children[3].name,"Masha");
    children[4].id = 4; strcpy(children[4].name,"Kostya");
    children[5].id = 5; strcpy(children[5].name,"Sveta");

    ofstream foutc("child", ios::binary | ios::out);
    foutc.write((char*)children, sizeof(child) * 6);
    foutc.close();
    delete[] children;

    sympathy* sym = new sympathy[9];
    sym[0].from = 0; sym[0].to = 2;
    sym[1].from = 0; sym[1].to = 3;
    sym[2].from = 0; sym[2].to = 4;
    sym[3].from = 1; sym[3].to = 2;
    sym[4].from = 2; sym[4].to = 0;
    sym[5].from = 2; sym[5].to = 3;
    sym[6].from = 3; sym[6].to = 0;
    sym[7].from = 4; sym[7].to = 0;
    sym[8].from = 5; sym[8].to = 2;

    ofstream fouts("sympathy", ios::binary | ios::out);
    fouts.write((char*)sym, sizeof(sympathy) * 9);
    fouts.close();
    delete[] sym;
}

#include <iostream>
#include <vector>
#include "Reader.h"
#include "Graph.h"
#include "helper.h"

using namespace std;

int main(int argc , char *argv[]) {
    if (argc < 3) {
        cout << "Incorrect arguments" << endl;
        throw exception();
    }
    Reader* reader = new Reader(argv[1], argv[2]);
    Graph graph(
            reader->getChild(),
            reader->getCntChild(),
            reader->getSympathy(),
            reader->getCntSympathy()
    );
    delete reader;

    cout << "Commands:" << endl;
    cout << "  0 - exit" << endl;
    cout << "  1 - print list of unloved" << endl;
    cout << "  2 - print list of unhappy" << endl;
    cout << "  3 - print list of favorite" << endl;
    cout << "  4 - write test files" << endl;

    int command = 0;
    while (true) {
        cout << endl << "To continue enter command: ";
        cin >> command;

        vector<string*> result;
        switch (command)
        {
            case 0:
                return 0;
            case 1:
                result = graph.getUnloved();
                for (auto it = result.begin(); it != result.end() ; ++it)
                    cout << **it << endl;
                break;
            case 4:
                writeFiles();
                break;
            default:
                cout << "Command not found" << endl;
        }
    }
}
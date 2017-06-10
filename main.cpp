#include <iostream>
#include <vector>
#include "Reader.h"
#include "Graph.h"

using namespace std;

int main(int argc , char *argv[]) {
    if (argc < 3) {
        cerr << "Incorrect arguments" << endl;
        throw new exception();
    }
    Reader* reader = new Reader(argv[1], argv[2]);
    Graph graph(
            reader->getChild(),
            reader->getCntChild(),
            reader->getSympathy(),
            reader->getCntSympathy()
    );
    delete reader;

    cout << "Comands:" << endl;
    cout << "  0 - exit" << endl;
    cout << "  1 - print list of unloved" << endl;
    cout << "  2 - print list of unhappy" << endl;
    cout << "  3 - print list of favorite" << endl;

    int command = 0;
    while (true) {
        cout << endl << "To continue enter command: ";
        cin >> command;

        vector<string> result;
        switch (command)
        {
            case 0:
                return 0;
            case 1:
                result = graph.getUnloved();
                for (auto it = result.begin(); it != result.end() ; ++it)
                    cout << *it << endl;
                break;
            case 2:
                result = graph.getUnhappy();
                for (auto it = result.begin(); it != result.end() ; ++it)
                    cout << *it << endl;
                break;
            case 3:
                result = graph.getFavorite();
                for (auto it = result.begin(); it != result.end() ; ++it)
                    cout << *it << endl;
                break;
            default:
                cout << "Command not found" << endl;
        }
    }
}
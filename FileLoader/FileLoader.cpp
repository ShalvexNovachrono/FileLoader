#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "dynamic_array.h"

using namespace std;
using namespace dynamic_array;

namespace FileLoader {
    dynamic_array::array<string> GetFileContentLines(string path) {
        dynamic_array::array<string> Contents;
        ifstream FileContent(path);

        if (!FileContent.is_open()) {
            cerr << "Error File failed to open." << endl;
            return Contents;
        }

        string TempContentLine;

        while (getline(FileContent, TempContentLine)) {
            Contents.Append(TempContentLine);
        }

        FileContent.close();

        return Contents;
    }
}


int main() {
    dynamic_array::array<string> Lines = FileLoader::GetFileContentLines("path to a file");

    for (int i = 0; i < Lines.Size(); i++) {
        cout << Lines.Get(i) << endl;
    }

}
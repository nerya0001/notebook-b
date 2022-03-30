#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Direction.hpp"

using namespace std;

namespace ariel {

    const int ROWMAX= 100;
    const int ROWMIN = 0;

    class Notebook {

        private:
            unordered_map<int, unordered_map<int, unordered_map<int, char>>> notebook;
        public:
            Notebook();

            void write(int page, int row, int column, Direction dir, const string &str);

            string read(int page, int row, int column, Direction dir, int length);

            void erase(int page, int row, int column, Direction dir, int length);

            void show(int page);
    };
}



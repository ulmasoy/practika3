// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include <iostream>
#include <vector>
#include <fstream>
#include <clocale>
#include <windows.h>

#include "cars.h"
#include "date.h"
using namespace std;

void loadData(vector<Car>& cars, istream& in) {
    while (!in.eof() && in.good()) {
        Car c;
        c.load(in);
        cars.push_back(c);
    }
}

void printData(vector<Car>& cars) {
    for (auto& c : cars) {
        c.print();
    }
}

void CheckMemoryLeaks() {
    //_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    //_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    //_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    //_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    //_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    //_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
    _CrtDumpMemoryLeaks();
}

int main()
{
    atexit(CheckMemoryLeaks);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector <Car> cars;
    ifstream in("ist.txt");
    try {
        loadData(cars, in);
        printData(cars);
    }
    catch (runtime_error& e) {
        cerr << "Invalid argument: " << e.what() << endl;
    }
    catch (out_of_range& e) {
        cerr << "Variable is out of range: " << e.what() << endl;
    }
    return 0;
}

#pragma once

#include <ostream>
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <iostream>

using namespace std;

typedef unsigned long long sizeType;
//typedef int sizeType;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &inputVector) {
    os << "{";
    for (int i = 0; i < inputVector.size() - 1; i++) {
        os << int(inputVector[i]) << " ";
    }
    os << int(inputVector[inputVector.size() - 1]) << "}";
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, const map<sizeType, T> &inputMap) {
    os << "{";
    for (auto it = inputMap.begin(); it != --inputMap.end(); it++) {
        os << int(it->second) << " ";
    }
    os << int((--inputMap.end())->second) << "}";
    return os;
}

class CountSeconds {
public:
    CountSeconds(string inputMessage) {
        start = chrono::system_clock::now();
        message = inputMessage;
    }

    ~CountSeconds() {
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsedSeconds = end - start;
        cout << message << ":" << elapsedSeconds.count() << endl;
    }

private:
    string message;
    chrono::time_point<chrono::system_clock> start;

};
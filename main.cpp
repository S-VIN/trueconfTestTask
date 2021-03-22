#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include "debugContainers.h"
#include "synchronization.h"

using namespace std;

typedef unsigned long long sizeType;
//typedef int sizeType;

const sizeType sizeOfContainers = 30;

vector<int8_t> generateVector(sizeType size = 10000) {
    vector<int8_t> result(size);
    for (auto &item : result) {
        item = (rand() % 9) + 1;
    }
    return result;
}

map<sizeType, int8_t> generateMap(sizeType size = 10000) {
    map<sizeType, int8_t> result;
    for (uint64_t i = 0; i < size; i++) {
        result.insert({i, (rand() % 9) + 1});
    }
    return result;
}

void deleteRandomElements(vector<int8_t> &inputVector) {
    int countOfElements = (rand() % 15) + 1;
    for (int i = 0; i < countOfElements; i++) {
        sizeType indexOfElement = rand() % sizeOfContainers;
        inputVector.erase(inputVector.begin() + indexOfElement);
    }
}

void deleteRandomElements(map<sizeType, int8_t> &inputMap) {
    int countOfElements = (rand() % 15) + 1;
    for (int i = 0; i < countOfElements; i++) {
        sizeType indexOfElement = rand() % sizeOfContainers;
        inputMap.erase(indexOfElement);
    }
}


int main() {
    // generate containers (map[i], vector[i])
    vector<int8_t> firstContainer = generateVector(sizeOfContainers);
    //~10s allocation (need to optimize)
    map<sizeType, int8_t> secondContainer(generateMap(sizeOfContainers));

    cout << "generated vector: " << firstContainer << endl;
    cout << "generated map:    " << secondContainer << endl << endl;

    //delete elements from containers (fast operation)
    deleteRandomElements(firstContainer);
    deleteRandomElements(secondContainer);
    cout << "vector after deletion: " << firstContainer << endl;
    cout << "map after deletion:    " << secondContainer << endl << endl;

    //~10s operation
    synchronization(firstContainer, secondContainer);
    cout << "vector after synchronization: " << firstContainer << endl;
    cout << "map after synchronization:    " << secondContainer << endl;

    return 0;
}

#pragma once

#include "debugContainers.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef unsigned long long sizeType;
//typedef int sizeType;

//return vector, which counts amount of each number in input container
//f.e. {1, 2, 3, 4, 4} -> {0, 1, 1, 1, 2, 0, ...} (mas[3]==2 because input array has two '4')
vector<sizeType> createAmountElementsVector(vector<int8_t> &inputVector) {
    vector<sizeType> result(10, 0);
    for (sizeType i = 0; i < inputVector.size(); i++) {
        result[inputVector[i]]++;
    }
    return result;
}

vector<sizeType> createAmountElementsVector(map<sizeType, int8_t> &inputMap) {
    vector<sizeType> result(10, 0);
    for (sizeType i = 0; i < inputMap.size(); i++) {
        result[inputMap[i]]++;
    }
    return result;
}

vector<sizeType> createMinElementsVector(vector<sizeType> fv, vector<sizeType> sv) {
    int smallestSize = (fv.size() < sv.size()) ? fv.size() : sv.size();
    vector<sizeType> result(smallestSize);
    for (int i = 0; i < result.size(); i++) {
        result[i] = min(fv[i], sv[i]);
    }
    return result;
}

void createVectorFromCountNumbers(vector<sizeType> count, vector<int8_t> &outputVector){
    sizeType counter = 0;
    for (sizeType i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            outputVector[counter] = i;
            count[i]--;
            counter++;
        }
    }
    outputVector.erase(outputVector.begin() + counter, outputVector.end());
}

void createVectorFromCountNumbers(vector<sizeType> count, map<sizeType, int8_t> &outputMap){
    sizeType counter = 0;
    for (sizeType i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            outputMap[counter] = i;
            count[i]--;
            counter++;
        }
    }
    outputMap.erase(next(outputMap.begin(), counter), outputMap.end());
}

void synchronization(vector<int8_t> &inputVector, map<sizeType, int8_t> &inputMap) {
    auto t1 = createAmountElementsVector(inputVector);
    //need to optimize
    auto t2 = createAmountElementsVector(inputMap);

    auto amountOfNumbers = createMinElementsVector(t1, t2);

    //we know amount of each number, so lets create synchronized vector and map
    createVectorFromCountNumbers(amountOfNumbers, inputVector);
    createVectorFromCountNumbers(amountOfNumbers, inputMap);
}
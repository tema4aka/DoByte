#include <iostream>
#include <map>
#include <vector>

enum  thirteenDec{
    A = 10, B, C    
};

class ICalcPermutation {
public:
    static std::map<uint8_t, uint64_t> mNumSums;
    static void countBound(const std::vector<int8_t>& vNumbers, uint16_t sum, uint8_t nSize, uint8_t lenght);
};


std::map<uint8_t, uint64_t> ICalcPermutation::mNumSums;

void ICalcPermutation::countBound(const std::vector<int8_t>& vNumbers, uint16_t nSum, uint8_t nSize, uint8_t nLenght) {
    if (nLenght == 1) {
        for (size_t j = 0; j < nSize; j++) {
            uint16_t nCurrent = vNumbers[j];
            mNumSums[nSum + nCurrent]++;
        }
    }
    else {
        for (size_t i = 0; i < nSize; i++) {
            int32_t nCurrent = vNumbers[i];
            countBound(vNumbers, nSum + nCurrent, nSize, nLenght - 1);
        }
    }
}

int main() 
{   
    std::vector<int8_t> vNumbers =
    { 0,1,2,3,4,5,6,7,8,9,thirteenDec::A, thirteenDec::B, thirteenDec::C };
    uint8_t nSize = vNumbers.size();
    uint8_t nLenght = 6;
    ICalcPermutation::countBound(vNumbers, 0, nSize, nLenght);
    uint64_t summ = 0;
    for (auto [first, second] : ICalcPermutation::mNumSums)
        summ += second * second;
 
    std::cout << summ;
    return 0;
}
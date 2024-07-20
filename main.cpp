#include <iostream>
#include "LinkedList/leecode-24.h"
#include "LinkedList/leecode-19.h"
#include "HashTable/leecode-202.h"

int main() {

    std::vector<int> vec1 = {1,2,3,4,5,6};

    vec1.back();

    std::vector<int> vec2 = std::vector<int>(vec1.begin(), vec1.begin());
     return 0;
}

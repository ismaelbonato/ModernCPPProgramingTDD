#include "Soundex.h"

#include "iostream"

int main() {
    Soundex soundex;
    std::cout << "restult: " << soundex.encode("Example") << std::endl;
    return 0;
}
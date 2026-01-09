#include <iostream>

int main() {
#ifdef DEBUG
    std::cout << "debug info\n";
#endif
    for (int i = 0; i < 3; ++i) {
        std::cout << "hello cmake.\n";
    }
    return 0;
}
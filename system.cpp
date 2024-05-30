#include <cstdlib>
#include <stdlib.h>
#include <iostream>

using namespace std;


int main(void) {
    int compile = system("g++ --std=c++17 -DHOANG_DEBUG main.cpp -o main");
    int run  = 0;

    if(compile == 0) {
#ifdef __linux__
        run = system("./main");
#endif // __linux__

#ifdef __WIN32
        run = system(".\main.exe");
#endif // __WIN32
        if(run == 0) {
            return 0;
        } else {
            return -1;
        }
    } else {
        return -1;
    }

    return 0;
}

#include <cstdlib>
#include <stdlib.h>
#include <iostream>

using namespace std;


int main(void) {
    int compile = system("g++ --std=c++11 -DHOANG_DEBUG main.cpp -o main.out");
    int run  = 0;

    if(compile == 0) {
        run = system("./main.out");
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

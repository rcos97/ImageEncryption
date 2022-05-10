#include "myTools.h"

int myTools::mod(int x, int y)
{
    if (x >= 0 && y > 0) {
        return x % y;
    }
    if (x < 0 && y > 0) {
        return y - (x % y);
    }
    return 0;
}

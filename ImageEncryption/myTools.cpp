#include "myTools.h"

int myTools::mod(int x, int y)
{
    if (x >= 0 && y > 0) {
        return x % y;
    }
    if (x < 0 && y > 0) {
        int result = y - (-x % y);
        if (result == y) {
            result = 0;
        }
        return result;
    }
    return 0;
}

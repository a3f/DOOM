extern "C" {
#include "fcntl.h"
}
#include <assert.h>

int main(void)
{
    assert(-1 == open("kek", 0));
    assert(-1 != open("doom1.wad", 0));
}

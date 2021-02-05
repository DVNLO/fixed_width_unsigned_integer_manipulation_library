#include <stddef.h>
#include <stdio.h>

#include "test_uint8.h"
#include "test_uint16.h"
#include "test_uint32.h"
#include "test_uint64.h"

int main()
{
    fwuim_test_uint8();
    fwuim_test_uint16();
    fwuim_test_uint32();
    fwuim_test_uint64();
}
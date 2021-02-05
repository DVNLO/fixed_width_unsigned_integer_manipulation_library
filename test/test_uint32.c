#include <stdio.h>

#include "uint32.h"
#include "test_uint32.h"
#include "test_constants.h"

uint8_t
fwuim_test_uint32_get_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{   
    uint8_t const SIZE_UINT32_T_BITS = sizeof(uint8_t) * 8U;
    uint32_t val = (uint32_t)(~(0x01U));
    uint32_t const expected = (uint32_t)(0x00U);
    // iteratively get the i-th 0 bit
    for(uint8_t i = (uint8_t)(0U); i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_get_bit_uint32(i, val);
        if(got != expected)
        {
            return fwuim_test_fail;    // failure
        }
        val = (uint32_t)(val << (uint32_t)(1U));
        val |= (uint32_t)(0x1U); // set lsb; surround 0 with 1s
    }
    return fwuim_test_pass;    // pass
}

uint8_t
fwuim_test_uint32_get_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    uint8_t const SIZE_UINT32_T_BITS = sizeof(uint8_t) * 8U;
    uint32_t val = (uint32_t)(0x01U);
    uint32_t const expected = (uint32_t)(0x01U);
    // iteratively get the i-th 1 bit
    for(uint8_t i = (uint8_t)(0U); i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_get_bit_uint32(i, val);
        if(got != expected)
        {
            return fwuim_test_fail;    // failure
        }
        val = (uint32_t)(val << (uint32_t)(1U));
        val &= (uint32_t)(~((uint32_t)(0x01U)));    // clear lsb; surround 1 with 0s
    }
    return fwuim_test_pass;    // pass
}

uint8_t
fwuim_test_uint32_set_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    uint8_t const SIZE_UINT32_T_BITS = sizeof(uint8_t) * 8U;
    uint32_t const val = (uint32_t)(0x00U);
    uint32_t expected = (uint32_t)(0x01U);
    // iteratively set the i-th 0 bit
    for(uint8_t i = (uint8_t)(0U); i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_set_bit_uint32(i, val);
        if(got != expected)
        {
            return fwuim_test_fail;    // failure
        }
        expected = (uint32_t)(expected << (uint32_t)(1U));
        expected &= (uint32_t)(~((uint32_t)(0x01)));    // clear lsb; surround 1 with 0s
    }
    return fwuim_test_pass;    // pass
}

uint8_t
fwuim_test_uint32_set_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    uint8_t const SIZE_UINT32_T_BITS = sizeof(uint8_t) * 8U;
    uint32_t val = (uint32_t)(0x01U);
    uint32_t expected = (uint32_t)(0x01U);
    // iteratively set the i-th 1 bit
    for(uint8_t i = (uint8_t)(0U); i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_set_bit_uint32(i, val);
        if(got != expected)
        {
            return fwuim_test_fail;    // failure
        }
        val = (uint32_t)(val << (uint32_t)(1U));
        expected = (uint32_t)(expected << (uint32_t)(1U));
        expected &= (uint32_t)(~((uint32_t)(0x01)));    // clear lsb; surround 1 with 0s
    }
    return fwuim_test_pass;    // pass
}

uint8_t
fwuim_test_uint32_clear_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{   
    uint8_t const SIZE_UINT32_T_BITS = sizeof(uint8_t) * 8U;
    uint32_t val = (uint32_t)(~(0x01U));
    uint32_t expected = (uint32_t)(~(0x01U));
    // iteratively clear the i-th 0 bit
    for(uint8_t i = (uint8_t)(0U); i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_clear_bit_uint32(i, val);
        if(got != expected)
        {
            return fwuim_test_fail;    // failure
        }
        val = (uint32_t)(val << (uint32_t)(1U));
        val |= (uint32_t)(0x1U); // set lsb; surround 0 with 1s
        expected = (uint32_t)(expected << (uint32_t)(1U));
        expected |= (uint32_t)(0x1); // set lsb; surround 0 with 1s
    }
    return fwuim_test_pass;    // pass
}

uint8_t
fwuim_test_uint32_clear_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    uint8_t const SIZE_UINT32_T_BITS = sizeof(uint8_t) * 8U;
    uint32_t val = (uint32_t)(0x01U);
    uint32_t expected = (uint32_t)(0x00U);
    // iteratively clear the i-th 1 bit
    for(uint32_t i = 0; i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_clear_bit_uint32(i, val);
        if(got != expected)
        {
            return fwuim_test_fail;    // failure
        }
        val = (uint32_t)(val << (uint32_t)(1U));
        val &= (uint32_t)(~((uint32_t)(0x01)));    // clear lsb; surround 1 with 0s
    }
    return fwuim_test_pass;    // pass
}

uint8_t
fwuim_test_uint32_toggle_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{   
    uint8_t const SIZE_UINT32_T_BITS = sizeof(uint8_t) * 8U;
    uint32_t val = (uint32_t)(~((uint32_t)(0x01)));
    uint32_t const expected = (uint32_t)(~((uint32_t)(0x00)));
    // iteratively toggle the i-th 0 bit
    for(uint32_t i = 0; i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_toggle_bit_uint32(i, val);
        if(got != expected)
        {
            return fwuim_test_fail;    // failure
        }
        val = (uint32_t)(val << (uint32_t)(1U));
        val |= (uint32_t)(0x1U); // set lsb; surround 0 with 1s
    }
    return fwuim_test_pass;    // pass
}

uint8_t
fwuim_test_uint32_toggle_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    uint8_t const SIZE_UINT32_T_BITS = sizeof(uint8_t) * 8U;
    uint32_t val = (uint32_t)(0x01U);
    uint32_t const expected = (uint32_t)(0x00U);
    // iteratively toggle the i-th 1 bit
    for(uint32_t i = 0; i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_toggle_bit_uint32(i, val);
        if(got != expected)
        {
            return fwuim_test_fail;    // failure
        }
        val = (uint32_t)(val << (uint32_t)(1U));
        val &= (uint32_t)(~((uint32_t)(0x01)));    // clear lsb; surround 1 with 0s
    }
    return fwuim_test_pass;    // pass
}

void 
fwuim_test_uint32(void)
{
    uint8_t rc; // return code
    rc = fwuim_test_uint32_get_all_0_bits();
    if(rc == fwuim_test_pass)
    {
        puts("fwuim_test_uint32_get_all_0_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_get_all_0_bits failed");
    }
    rc = fwuim_test_uint32_get_all_1_bits();
    if(rc == fwuim_test_pass)
    {
        puts("fwuim_test_uint32_get_all_1_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_get_all_1_bits failed");
    }
    rc = fwuim_test_uint32_set_all_0_bits();
    if(rc == fwuim_test_pass)
    {
        puts("fwuim_test_uint32_set_all_0_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_set_all_0_bits failed");
    }
    rc = fwuim_test_uint32_set_all_1_bits();
    if(rc == fwuim_test_pass)
    {
        puts("fwuim_test_uint32_set_all_1_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_set_all_1_bits failed");
    }
    rc = fwuim_test_uint32_clear_all_0_bits();
    if(rc == fwuim_test_pass)
    {
        puts("fwuim_test_uint32_clear_all_0_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_clear_all_0_bits failed");
    }
    rc = fwuim_test_uint32_clear_all_1_bits();
    if(rc == fwuim_test_pass)
    {
        puts("fwuim_test_uint32_clear_all_1_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_clear_all_1_bits failed");
    }
    rc = fwuim_test_uint32_toggle_all_0_bits();
    if(rc == fwuim_test_pass)
    {
        puts("fwuim_test_uint32_toggle_all_0_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_toggle_all_0_bits failed");
    }
    rc = fwuim_test_uint32_toggle_all_1_bits();
    if(rc == fwuim_test_pass)
    {
        puts("fwuim_test_uint32_toggle_all_1_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_toggle_all_1_bits failed");
    }
}
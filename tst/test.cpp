#include "../lib/library.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

extern "C" long long asm_foo(void);

TEST_CASE("Testing assembly functions"){
    SUBCASE("compute answer"){
        compute_answer();
        CHECK(compute_answer() == 42);
    }
    SUBCASE("increment pointer"){
        int64_t not_zero = 0;
        increment_pointer_int64(&not_zero);
        CHECK(not_zero != 0);
    }
    SUBCASE("asm_foo"){
        CHECK(asm_foo() == 1337);
    }
    SUBCASE("sum of four ints"){
        CHECK(sum_4_ints(1, 1, 1, 1) == 4);
    }
}
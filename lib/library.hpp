#pragma once
#include <cstdint>
extern "C" {
    int compute_answer();
    int sum_4_ints(int, int, int, int);
    void increment_pointer_int64(int64_t*);
    int sum_two_ints(int, int);
    int mul_two_ints(int, int);
    void mutate_arg(uint64_t, uint64_t, uint64_t*);
    /**
     * Iterate through an array and count the number of positive increments
     * @param arr Target array
     * @param size Array length
     * @return Number of positive increments
     */
    int count_increments(uint64_t arr[] , uint64_t size);
    uint64_t* three_element_window(uint64_t[], uint64_t srcSize, uint64_t *destSize);
}

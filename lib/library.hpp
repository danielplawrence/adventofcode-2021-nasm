#pragma once
#include <cstdint>
extern "C" {
    int compute_answer();
    int sum_4_ints(int, int, int, int);
    void increment_pointer_int64(int64_t*);
    int sum_two_ints(int, int);
    int mul_two_ints(int, int);
    /**
     * Iterate through an array and count the number of positive increments
     * @param arr Target array
     * @param size Array length
     * @return Number of positive increments
     */
    int count_increments(uint64_t arr[] , uint64_t size);
    /**
     * Compute the three-item sum of an array
     * @param arr Input array
     * @param srcSize Length of input array
     * @param destSize Reference to update with output length
     * @return Pointer to first element of output array
     */
    uint64_t* three_element_window(uint64_t arr[], uint64_t srcSize, uint64_t *destSize);
    /**
     * Alter the horizontal and vertical position of a submarine
     * @param horizontal Reference to horizontal position (will be mutated)
     * @param vertical Reference to vertical position (will be mutated)
     * @param command 'forward' or 'down'
     * @param argument Distance to move
     */
    void move_submarine(int64_t* horizontal, int64_t* vertical, char command[], int argument);
     /**
     * Alter the horizontal and vertical position of a submarine (part II)
     * @param horizontal Reference to horizontal position (will be mutated)
     * @param vertical Reference to vertical position (will be mutated)
     * @param aim Reference to aim (will be mutated)
     * @param command 'forward' or 'down'
     * @param argument Distance to move
     */
    void move_submarine_aim(int64_t* horizontal, int64_t* vertical, int64_t* aim, char command[], int64_t argument);

}

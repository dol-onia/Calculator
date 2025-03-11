#include "unity.h"
#include "calculator.h"
// Optional but needs to be defined(runs BEFORE each test)
void setUp(void) {
// Initialize any resources needed for your tests here
// For example, you might reset a global value, dynamically allocate memory, etc.
// In this example, we do not need anything here.
}
// Optional but needs to be defined(runs AFTER each test)
void tearDown(void) {
// Clean up resources after each test
// For example, free dynamically allocated memory, reset global values, etc.
// In this example, we do not need anything here.
}
void test_add_positive_numbers(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3)); //We expect 2 + 3 to be 5
}
void test_add_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(1, add(5, -4)); //expect 5 + -4 = 1
}
void test_add_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-7, add(-3, -4)); //expect -3 + -4 = -7
}
//NOTE: We can do multiple validations in one test
void test_add_zero(void) {
    TEST_ASSERT_EQUAL(10, add(10, 0)); //expect 10 + 0 = 10
    TEST_ASSERT_EQUAL(0, add(0, 0)); //expect 0 + 0 = 0
}
void test_add_overflow(void) {
    int result = add(INT_MAX, 1); //Should wrap around or cause undefined behavior
    TEST_ASSERT_TRUE(result < 0); //This checks if overflow occurred
}
// Test integer underflow
void test_add_underflow(void) {
    int result = add(INT_MIN, -1);
    TEST_ASSERT_TRUE(result > 0); //This checks if underflow occurred
}
// Test subtraction cases
void test_subtract_positive(void) {
    TEST_ASSERT_EQUAL(1, subtract(8,7));
}

void test_subtract_negative(void) {
    TEST_ASSERT_EQUAL(-5, subtract(2, 7));
}

void test_subtract_negative_from_positive(void) {
    TEST_ASSERT_EQUAL(8, subtract(3, -5));
}

void test_subtract_negative_from_negative(void) {
    TEST_ASSERT_EQUAL(5, subtract(-4, -9));
    TEST_ASSERT_EQUAL(-3, subtract(-7, -4));
}

void test_subtract_with_zero(void) {
    TEST_ASSERT_EQUAL(10, subtract(10, 0));
    TEST_ASSERT_EQUAL(-5, subtract(0, 5));
}

void test_subtract_underflow(void) {
    int result = subtract(INT_MIN, 1);
    TEST_ASSERT_TRUE(result > 0);
}

void test_subtract_overflow(void) {
    int result = subtract(INT_MAX, -1);
    TEST_ASSERT_TRUE(result < 0);
}

// Test multiplication cases

void test_multiply_positive(void) {
    TEST_ASSERT_EQUAL(42, multiply(6, 7));
    TEST_ASSERT_EQUAL(42, multiply(7, 6));
}

void test_multiply_negative_and_positive(void) {
    TEST_ASSERT_EQUAL(-50, multiply(5, -10));
    TEST_ASSERT_EQUAL(-50, multiply(-5, 10));
}

void test_multiply_negative(void) {
    TEST_ASSERT_EQUAL(64, multiply(-8, -8));
}

void test_multiply_zero(void) {
    TEST_ASSERT_EQUAL(0, multiply(0, 27));
    TEST_ASSERT_EQUAL(0, multiply(89, 0));
}

void test_multiply_overflow(void) {
    int result = multiply(INT_MAX, 2);
    TEST_ASSERT_TRUE(result < 1);
}
//I have no idea if this one works or not. May need troubleshooting
void test_multiply_underflow(void) {
    int result = multiply(INT_MIN, 2);
    TEST_ASSERT_TRUE(result > 1);
}
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_positive_numbers);
    RUN_TEST(test_add_positive_and_negative_numbers);
    RUN_TEST(test_add_negative_numbers);
    RUN_TEST(test_add_zero);
    RUN_TEST(test_add_overflow);
    RUN_TEST(test_add_underflow);
    RUN_TEST(test_subtract_positive);
    RUN_TEST(test_subtract_negative);
    RUN_TEST(test_subtract_negative_from_positive);
    RUN_TEST(test_subtract_negative_from_negative);
    RUN_TEST(test_subtract_with_zero);
    RUN_TEST(test_subtract_underflow);
    RUN_TEST(test_subtract_overflow);
    RUN_TEST(test_multiply_positive);
    RUN_TEST(test_multiply_negative);
    RUN_TEST(test_multiply_negative_and_positive);
    RUN_TEST(test_multiply_zero);
    RUN_TEST(test_multiply_overflow);
    RUN_TEST(test_multiply_underflow);
    return UNITY_END();
}
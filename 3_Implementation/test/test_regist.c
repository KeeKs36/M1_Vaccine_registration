#include "unity.h"
#include "regist.h"

#define PROJECT_NAME    "Vaccine_Registration"

// Prototypes 
void test_regist_state(void);
void test_vaccine_state(void);

void setUp(){}

void tearDown(){}

int main()
{
  UNITY_BEGIN();

// Run Test functions for registration and vaccine status
  RUN_TEST(test_regist_state);
  RUN_TEST(test_vaccine_state);
  
  return UNITY_END();
}

// Test functions
void test_regist_status(void) {
  TEST_ASSERT_EQUAL(-1, regist_state(123));
  
  TEST_ASSERT_EQUAL(-1, regist_state(150)); // Fail condition
}

void test_vaccine_status(void) {
  TEST_ASSERT_EQUAL(1, vaccine_state(1));
  
  TEST_ASSERT_EQUAL(2, vaccine_state(1)); // Fail condition
}

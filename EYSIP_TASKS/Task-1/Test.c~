#include "/home/vinay/Desktop/Unity-master/src/unity.h"
#include "Arithmetic_Header.h"

void test(void)
{
TEST_ASSERT_EQUAL_INT (15, GCD(15,15));
TEST_ASSERT_EQUAL_INT (5, GCD(-5,15));
TEST_ASSERT_EQUAL_INT (5, GCD(-5,-15));
TEST_ASSERT_EQUAL_INT (9000, GCD(0,15));
TEST_ASSERT_EQUAL_INT (9000, GCD(0,0));
TEST_ASSERT_EQUAL_INT (1, GCD(-5,19));

}

int main(void)
{
UNITY_BEGIN();
RUN_TEST(test);
return UNITY_END();
}

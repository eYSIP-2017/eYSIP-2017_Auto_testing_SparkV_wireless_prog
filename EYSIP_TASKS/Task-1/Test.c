// This was a unit test written in order to test the functions I had written earlier. 
// This was task was used to help me learn the different functions Unity has to offer and the procedure to write Unit Tests.

#include "/home/vinay/Desktop/Unity-master/src/unity.h" // Include the Unity Header files 
#include "Arithmetic_Header.h" 

void test(void)
{
TEST_ASSERT_EQUAL_INT (15, GCD(15,15)); // Assert Statements written to check the validity of a GCD function under different cases
TEST_ASSERT_EQUAL_INT (5, GCD(-5,15));
TEST_ASSERT_EQUAL_INT (5, GCD(-5,-15));
TEST_ASSERT_EQUAL_INT (9000, GCD(0,15));
TEST_ASSERT_EQUAL_INT (9000, GCD(0,0));
TEST_ASSERT_EQUAL_INT (1, GCD(-5,19));

}

int main(void)
{
UNITY_BEGIN();
RUN_TEST(test); // Running the Unit Test for testing the GCD function
return UNITY_END();
}

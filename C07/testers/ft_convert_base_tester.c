#include "../includes/tuligma_C07.h"

int main()
{
    // Test 1: Valid Input
    char *result1 = ft_convert_base("1010", "01", "0123456789");
    printf("\nTest 1 - Expected: 10, Actual: %s\n", result1);
    free(result1);

    // Test 2: Empty Input String
    char *result2 = ft_convert_base("", "01", "0123456789");
    printf("Test 2 - Expected: 0, Actual: %s\n", result2);
    free(result2);

    // Test 3: Empty Base
    char *result3 = ft_convert_base("1010", "", "0123456789");
    printf("Test 3 - Expected: (null), Actual: %s\n", result3);
    free(result3);

    // Test 4: Base Size 1
    char *result4 = ft_convert_base("1010", "0", "0123456789");
    printf("Test 4 - Expected: (null), Actual: %s\n", result4);
    free(result4);

    // Test 5: Duplicate Characters in Base
    char *result5 = ft_convert_base("1010", "001", "0123456789");
    printf("Test 5 - Expected: (null), Actual: %s\n", result5);
    free(result5);

    // Test 6: Whitespace in Base
    char *result6 = ft_convert_base("1010", "01 ", "0123456789");
    printf("Test 6 - Expected: (null), Actual: %s\n", result6);
    free(result6);

    // Test 7: Invalid Character in Input String
    char *result7 = ft_convert_base("10102", "01", "0123456789");
    printf("Test 7 - Expected: (null), Actual: %s\n", result7);
    free(result7);

    // Test 8: Number Exceeds INT_MAX
    char *result8 = ft_convert_base("2147483648", "0123456789", "01");
    printf("Test 8 - Expected: (null), Actual: %s\n", result8);
    free(result8);

    // Test 9: Number Less Than INT_MIN
    char *result9 = ft_convert_base("-2147483649", "0123456789", "01");
    printf("Test 9 - Expected: (null), Actual: %s\n", result9);
    free(result9);

    // Test 10: Valid Negative Number
    char *result10 = ft_convert_base("-1010", "01", "0123456789");
    printf("Test 10 - Expected: -10, Actual: %s\n", result10);
    free(result10);

    char *result11 = ft_convert_base("15", "0123456789", "01");
    printf("Test 11 - Expected: 1111, Actual: %s\n", result11);
    free(result11);

    char *result12 = ft_convert_base("10000", "01", "0123456789");
    printf("Test 12 - Expected: 16, Actual: %s\n", result12);
    free(result12);

    char *result13 = ft_convert_base("-31", "0123456789", "0123456789abcdef");
    printf("Test 13 - Expected: -1f, Actual: %s\n", result13);
    free(result13);

    char *result14 = ft_convert_base("+1f", "0123456789abcdef", "0123456789");
    printf("Test 14 - Expected: 31, Actual: %s\n", result14);
    free(result14);

    char *result15 = ft_convert_base("0", "0123456789", "0123456789abcdef");
    printf("Test 15 - Expected: 0, Actual: %s\n", result15);
    free(result15);

    char *result16 = ft_convert_base("0.1234567", "0123456789", "0123456789");
    printf("Test 16 - Expected: 0, Actual: %s\n", result16);
    free(result16);

    char *result17 = ft_convert_base("2147483647", "0123456789", "0123456789abcdef");
    printf("Test 17 - Expected: 7fffffff, Actual: %s\n", result17);
    free(result17);

    char *result18 = ft_convert_base("-80000000", "0123456789abcdef", "0123456789");
    printf("Test 18 - Expected: -2147483648, Actual: %s\n\n", result18);
    free(result18);

    
}
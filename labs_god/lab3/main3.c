#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH  100002
#define CHAR_BIT    8
#define OPER_SIZE   6

int sign(const unsigned char *n);
void add_base10_digit(unsigned char *base256, int digit);
void add_base256_digit(unsigned char *base10, int digit);
void addition(const unsigned char *n1, const unsigned char *n2, unsigned char *res);
void clear(unsigned char *array);
void from_base256_to_base10(unsigned char *base10, const unsigned char *base256, int is_negative);
void from_base256_to_decimal_string(unsigned char *str, const unsigned char *base256);
void from_decimal_string_to_base256(unsigned char *base256, const unsigned char *str, int len, int sign);
void multiplication(const unsigned char *n1, const unsigned char *n2, unsigned char *res);
void multiply_by_10(unsigned char *n);
void multiply_by_256(unsigned char *base10);
void negate(unsigned char *n);
void reverse(unsigned char *str, int len);
void substraction(const unsigned char *n1, const unsigned char *n2, unsigned char *res);
void fact(const unsigned char *n, unsigned char *res);
int compare(const unsigned char *n1, const unsigned char *n2);
void power(unsigned char *base, unsigned int exponent, unsigned char *result);
void sum_from_n_to_m(const unsigned char *n, const unsigned char *m, unsigned char *res);

// Есть ли операция в списке
bool check(char *str, char array[][OPER_SIZE], size_t size)
{
    for (int x = 0; x < OPER_SIZE; x++){
        if (!strcmp(array[x], str)){
            return true;
        }
    }

    return false;
}

// Заменяем \n
void change(char *str, size_t size)
{
    for (int i = 0; i < size; ++i){
        if (str[i] == '\n'){
            str[i] = '\0';
            return;
        }
    }
}

// Вводим только 1 число
void one_number(unsigned char arr[])
{
    printf("Enter number: ");
    scanf("%1001s", arr);
}

// Вводим 2 числа
void two_numbers(unsigned char arr1[], unsigned char arr2[])
{
    printf("Enter first number: ");
    scanf("%1001s", arr1);

    printf("Enter second number: ");
    scanf("%1001s", arr2);
}

// Ввод пользователем операции
void get_operation(char *str, size_t size)
{
    printf("Enter the operation (add; sub; mult; pow; fact; sum): ");
    fgets(str, OPER_SIZE, stdin);
}

//
void from_decimal_string_to_base256(unsigned char *base256, const unsigned char *str, int len, int sign)
{
    for (int i = 0; i < len; i++)
    {
        multiply_by_10(base256);
        add_base10_digit(base256, str[i] - '0');
    }
    if (sign)
        negate(base256);
}

//
void from_base256_to_base10(unsigned char *base10, const unsigned char *base256, int is_negative)
{
    unsigned char tmp[MAX_LENGTH] = {0};
    memcpy(tmp, base256, MAX_LENGTH);

    if (is_negative)
        negate(tmp);
    for (int i = MAX_LENGTH - 1; i >= 0; --i)
    {
        multiply_by_256(base10);
        add_base256_digit(base10, tmp[i]);
    }
}

//
void multiply_by_256(unsigned char *base10)
{
    unsigned int carry = 0;
    for (int i = 0; i < MAX_LENGTH; ++i)
    {
        unsigned int current = base10[i] * 256 + carry;
        base10[i] = current % 10;
        carry = current / 10;
    }
}

//
void add_base256_digit(unsigned char *base10, int digit)
{
    unsigned int carry = digit;
    for (int i = 0; i < MAX_LENGTH; ++i)
    {
        unsigned int current = base10[i] + carry;
        base10[i] = current % 10;
        carry = current / 10;
    }
}

//
void multiply_by_10(unsigned char *base256)
{
    unsigned int carry = 0;
    for (int i = 0; i < MAX_LENGTH; ++i)
    {
        unsigned int current = base256[i] * 10 + carry;
        base256[i] = current & 0xFF;
        carry = current >> CHAR_BIT;
    }
}

//
void add_base10_digit(unsigned char *base256, int digit)
{
    unsigned int carry = digit;
    for (int i = 0; i < MAX_LENGTH; ++i)
    {
        unsigned int current = base256[i] + carry;
        base256[i] = current & 0xFF;
        carry = current >> CHAR_BIT;
    }
}

// Переводим число в дополнительный код
void negate(unsigned char *n)
{
    for (int i = 0; i < MAX_LENGTH; ++i)
    {
        n[i] = ~n[i];
    }
    unsigned char one[MAX_LENGTH] = {0};
    one[0] = 1;
    addition(n, one, n);
}

// Помасивное сложение
void addition(const unsigned char *n1, const unsigned char *n2, unsigned char *res)
{
    unsigned long long int tmp;
    unsigned char carry = 0;
    for (int i = 0; i < MAX_LENGTH; ++i)
    {
        tmp = n1[i] + n2[i] + carry;
        res[i] = tmp & 0xFF;
        carry = tmp >> CHAR_BIT;
    }
}


void copy(unsigned char *dst, const unsigned char *src)
{
    for (int i = 0; i < MAX_LENGTH; ++i)
    {
        dst[i] = src[i];
    }
}

// Вычитание путем переведения чисел в дополнительный код
void substraction(const unsigned char *n1, const unsigned char *n2, unsigned char *res)
{
    unsigned char tmp[MAX_LENGTH] = {0};
    memcpy(tmp, n2, MAX_LENGTH);
    negate(tmp);
    addition(n1, tmp, res);
}

// Умножение с помощью формулы для многочлена
void multiplication(const unsigned char *num1, const unsigned char *num2, unsigned char *result)
{
    clear(result);
    
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        unsigned short carry = 0;
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            unsigned short product = num1[i] * (unsigned short)num2[j] + result[i + j] + carry;
            result[i + j] = product & 0xFF;
            carry = product >> CHAR_BIT;
        }
    }
}


int sign(const unsigned char *n)
{
    return n[MAX_LENGTH - 1] >> (CHAR_BIT - 1);
}

// Очищаем массив
void clear(unsigned char *array)
{
    memset(array, 0, MAX_LENGTH);
}

// 
void reverse(unsigned char *str, int len)
{
    unsigned char *ptr1 = str;
    unsigned char *ptr2 = str + len - 1;
    while (ptr1 < ptr2)
    {
        unsigned char tmp = *ptr1;
        *ptr1++ = *ptr2;
        *ptr2-- = tmp;
    }
}

//
void from_base256_to_decimal_string(unsigned char *str, const unsigned char *base256)
{
    int is_negative = sign(base256);
    unsigned char base10[MAX_LENGTH] = {0};
    from_base256_to_base10(base10, base256, is_negative);
    int index = 0;
    if (is_negative)
        str[index++] = '-';

    int len;
    int i = MAX_LENGTH - 1;
    while (base10[i] == 0 && i > 0)
        --i;
    len = i + 1;

    for (; i >= 0; --i)
    {
        base10[i] = base10[i] + '0';
    }
    reverse(base10, len);
    memcpy(str + index, base10, len);
}



void power(unsigned char *base, unsigned int exponent, unsigned char *result)
{

    result[0] = 0x01;

    unsigned char temp_base[MAX_LENGTH] = {0};
    memcpy(temp_base, base, MAX_LENGTH);

    while (exponent > 0)
    {
        if (exponent & 1)
        {
            unsigned char temp_result[MAX_LENGTH] = {0};
            multiplication(result, temp_base, temp_result);
            memcpy(result, temp_result, MAX_LENGTH);
        }
        unsigned char temp_power[MAX_LENGTH] = {0};
        multiplication(temp_base, temp_base, temp_power);
        memcpy(temp_base, temp_power, MAX_LENGTH);
        exponent >>= 1;
        printf("exponent: %d\n", exponent);
    }
}

void fact(const unsigned char *n, unsigned char *res)
{
    unsigned char temp_result[MAX_LENGTH] = {0};
    unsigned char tmp[MAX_LENGTH] = {0};
    unsigned char one[MAX_LENGTH] = {0};
    temp_result[0] = tmp[0] = one[0] = 1;

    while (compare(n, tmp) != -1){
        multiplication(temp_result, tmp, res);
        addition(tmp, one, tmp);
        memcpy(temp_result, res, MAX_LENGTH);
    }

    memcpy(res, temp_result, MAX_LENGTH);
}

// -1 если n1>
int compare(const unsigned char *n1, const unsigned char *n2)
{
    unsigned char n1_copy[MAX_LENGTH] = {0};
    unsigned char n2_copy[MAX_LENGTH] = {0};
    memcpy(n1_copy, n1, MAX_LENGTH);
    memcpy(n2_copy, n2, MAX_LENGTH);

    int sign1 = sign(n1_copy), sign2 = sign(n2_copy);
    if (sign1)
        negate(n1_copy);
    if (sign2)
        negate(n2_copy);
    if (sign1 > sign2)
        return -1;
    else if (sign1 < sign2)
        return 1;

    for (int i = MAX_LENGTH - 1; i >= 0; --i)
    {
        if (n1_copy[i] > n2_copy[i])
            return sign1 == 0 ? 1 : -1;
        if (n1_copy[i] < n2_copy[i])
            return sign1 == 0 ? -1 : 1;
    }

    return 0;
}

void sum_from_n_to_m(const unsigned char *n, const unsigned char *m, unsigned char *res)
{
    unsigned char one[MAX_LENGTH] = {0};
    unsigned char next[MAX_LENGTH] = {0};
    one[0] = 1;
    memcpy(next, n, MAX_LENGTH);

    while (compare(next, m) == -1)
    {
        addition(res, next, res);
        addition(next, one, next);
    }
}

int main()
{
    unsigned char n1[MAX_LENGTH] = {0}, n2[MAX_LENGTH] = {0}, res[MAX_LENGTH] = {0};
    unsigned char input1[MAX_LENGTH] = {0}, input2[MAX_LENGTH] = {0};
    unsigned char base10[MAX_LENGTH] = {0};
    unsigned char output[MAX_LENGTH] = {0};

    // scanf("%1001s", input1);
    // scanf("%1001s", input2);
    char operation[OPER_SIZE];
    char allowed_operations[OPER_SIZE][OPER_SIZE] = {"add", "sub", "mult", "pow", "fact", "sum"};

    get_operation(operation, OPER_SIZE);

    change(operation, OPER_SIZE);
    if (!check(operation, allowed_operations, OPER_SIZE)){
        printf("Wrong operation!\nEnd of the programm!");
        return 0;
    }

    if (!strcmp(operation, "fact") || !strcmp(operation, "pow"))
        one_number(input1);
    else
        two_numbers(input1, input2);

    int sign1 = 0, sign2 = 0;
    unsigned char *ptr1 = input1, *ptr2 = input2;
    
    if (input1[0] == '-'){
        sign1 = 1;
        ++ptr1;
    }

    if (input2[0] == '-'){
        sign2 = 1;
        ++ptr2;
    }

    int len1 = strlen(ptr1);
    int len2 = strlen(ptr2);

    from_decimal_string_to_base256(n1, ptr1, len1, sign1);
    from_decimal_string_to_base256(n2, ptr2, len2, sign2);

    // printf("First number: %s\n", input1);
    // printf("Second number: %s\n", input2);

    if (!strcmp(operation, "add")){
        addition(n1, n2, res);
        from_base256_to_decimal_string(output, res);
        printf("Addition: %s\n", output);
        clear(res);
        clear(output);
    }

    else if (!strcmp(operation, "sub")){
        substraction(n1, n2, res);
        from_base256_to_decimal_string(output, res);
        printf("Substraction: %s\n", output);
        clear(res);
        clear(output);
    }

    else if (!strcmp(operation, "mult")){
        multiplication(n1, n2, res);
        from_base256_to_decimal_string(output, res);
        printf("Multiplication: %s\n", output);
        clear(res);
        clear(output);
    }

    else if (!strcmp(operation, "pow")){
        printf("Enter power: ");
        unsigned exponent;
        scanf("%u", &exponent);

        power(n1, exponent, res);
        from_base256_to_decimal_string(output, res);
        printf("%s^%u: %s\n", input1, exponent, output);
        clear(res);
        clear(output);
    }

    else if (!strcmp(operation, "fact")){
        fact(n1, res);
        from_base256_to_decimal_string(output, res);
        printf("Factorial: %s\n", output);
        clear(res);
        clear(output);
    }

    else if (!strcmp(operation, "sum")){
        sum_from_n_to_m(n1, n2, res);
        from_base256_to_decimal_string(output, res);
        printf("Sum from %s to %s: %s\n", input1, input2, output);
        clear(res);
        clear(output);
    }

    return 0;
}
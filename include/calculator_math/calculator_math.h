#ifndef CALCULATOR_MATH_CALCULATOR_MATH_H
#define CALCULATOR_MATH_CALCULATOR_MATH_H

#include <limits.h>

namespace calculator_math
{

inline bool add(int left, int right, int* result)
{
    if (result == 0)
    {
        return false;
    }

    if ((right > 0 && left > INT_MAX - right) ||
        (right < 0 && left < INT_MIN - right))
    {
        return false;
    }

    *result = left + right;
    return true;
}

inline bool subtract(int left, int right, int* result)
{
    if (result == 0)
    {
        return false;
    }

    if ((right < 0 && left > INT_MAX + right) ||
        (right > 0 && left < INT_MIN + right))
    {
        return false;
    }

    *result = left - right;
    return true;
}

inline bool multiply(int left, int right, int* result)
{
    if (result == 0)
    {
        return false;
    }

    const long long value =
        static_cast<long long>(left) * static_cast<long long>(right);

    if (value > INT_MAX || value < INT_MIN)
    {
        return false;
    }

    *result = static_cast<int>(value);
    return true;
}

inline bool divide(int left, int right, int* result)
{
    if (result == nullptr)
    {
        return false;
    }

    if (right == 0)
    {
        return false;
    }

    if (left == INT_MIN && right == -1)
    {
        return false;
    }

    *result = left / right;
    return true;
}

inline bool power(int base, int exponent, int* result)
{
    if (result == 0)
    {
        return false;
    }

    if (exponent < 0)
    {
        return false;
    }

    int value = 1;

    for (int i = 0; i < exponent; ++i)
    {
        if (!multiply(value, base, &value))
        {
            return false;
        }
    }

    *result = value;
    return true;
}

inline bool factorial(int value, int* result)
{
    if (result == 0)
    {
        return false;
    }

    if (value < 0)
    {
        return false;
    }

    if (value == 0 || value == 1)
    {
        *result = 1;
        return true;
    }

    int previous = 0;

    if (!factorial(value - 1, &previous))
    {
        return false;
    }

    return multiply(value, previous, result);
}

} // namespace calculator_math

#endif // CALCULATOR_MATH_CALCULATOR_MATH_H
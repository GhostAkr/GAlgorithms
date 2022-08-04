#ifndef _TEMPLATE_FACTORIAL_HPP_
#define _TEMPLATE_FACTORIAL_HPP_

int recursiveFactorial(int n);

template<int n>
class TemplateFactorial
{
public:
    int _value;

public:
    TemplateFactorial() : 
        _value(n * TemplateFactorial<n - 1>().value())
    {}

    int value() const
    {
        return _value;
    }
};

template<>
class TemplateFactorial<0>
{
public:
    int _value;

public:
    TemplateFactorial() : 
        _value(1)
    {}

    int value() const
    {
        return _value;
    }
};

#endif  // _TEMPLATE_FACTORIAL_HPP_

#include <iostream>
#include <string>
#include <limits>

template <typename T>
void decimalUnderOverFlow(unsigned int numIterations)
{
    T under = (T)1;
    T over = (T)1;
    
    for(unsigned int i = 0; i < numIterations; ++i)
    {
        std::cout << "loop number: " << i << ", under: " << under << ", over: " << over << '\n';
        under /= 2;
        over *= 2;
    } 
}

template <typename T>
void intUnderOverFlow(unsigned int numIterations)
{
    T under = (T)0;
    T over = (T)0;
    
    for(unsigned int i = 0; i < numIterations; ++i)
    {
        std::cout << "loop number: " << i << ", under: " << under << ", over: " << over << '\n';
        under -= 1;
        over += 1;
    } 
}

int main()
{
    std::cout << "Float:\n";
    decimalUnderOverFlow<float>(200);

    std::cout << "\n\nDouble:\n";
    decimalUnderOverFlow<double>(1100);

    std::cout << "\n\nInteger:\n";
    intUnderOverFlow<int>(std::numeric_limits<int>::max());

    std::cout << "\n\nUnsigned Integer:\n";
    intUnderOverFlow<unsigned int>(std::numeric_limits<unsigned int>::max());

    return 0;
}

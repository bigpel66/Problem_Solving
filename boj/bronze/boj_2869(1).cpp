#include <iostream>

int main()
{
    int a, b, n;
    
    std::cin >> a >> b>> n;
    std::cout << ((n - b - 1) / (a - b)) + 1;
    
    return 0;
}

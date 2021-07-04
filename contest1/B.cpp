#include <iostream>
int main()
{
    int a, b, c; 
    std::cin >> a >> b >> c; 
    if (a + b > c && a + c > b && c + b > a)
        std::cout << "YES";
    else
        std::cout << "NO"; 
}
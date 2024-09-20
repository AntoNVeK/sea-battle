#include <iostream>
#include <string>
#include <vector>
#include "./headers/ManagerShips.h"


int main()
{
    ManagerShips manager(5, {ONE, TWO, TWO, THREE, FOUR});
    
    Ship& element = manager[1];
    element.shoot(1);
    const std::vector<States>& segments = element.GetSegments();
    for (std::size_t i = 0; i < segments.size(); i++)
    {
        std::cout << segments[i] << "\n";
    }
    return 0;
}

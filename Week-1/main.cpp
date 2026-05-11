#include <iostream>
#include "longboard.h"

namespace UI {

void run() {
    Domain::Longboard& first = Domain::Longboard::getInstance("rivira", 89);
    Domain::Longboard& second = Domain::Longboard::getInstance("Decatlon", 104);

    std::cout << std::boolalpha;
    std::cout << "Zelfde adres: " << (&first == &second) << std::endl;
    std::cout << first.description() << std::endl;
    std::cout << "Merk: " << first.getBrand() << std::endl;
    std::cout << "Lengte: " << first.getLengthCm() << " cm" << std::endl;
    std::cout << second.description() << std::endl;
    std::cout << "Merk: " << second.getBrand() << std::endl;
    std::cout << "Lengte: " << second.getLengthCm() << " cm" << std::endl;
}

} // namespace UI

int main() {
    UI::run();
    return 0;
}
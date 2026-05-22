#include "ui/ConsoleObserver.h"

#include <iostream>

namespace ui {
void ConsoleObserver::onTemperature(const std::string& motorName, int temperature) {
	events_.emplace_back(motorName, temperature);
	std::cout << motorName << ": " << temperature << '\n';
}

const std::vector<std::pair<std::string, int>>& ConsoleObserver::events() const {
	return events_;
}
}  // namespace ui
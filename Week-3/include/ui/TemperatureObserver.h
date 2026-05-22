#pragma once

#include <string>

namespace ui {
class TemperatureObserver {
public:
	virtual ~TemperatureObserver() = default;
	virtual void onTemperature(const std::string& motorName, int temperature) = 0;
};
}  // namespace ui
#pragma once

#include <utility>
#include <vector>

#include "ui/TemperatureObserver.h"

namespace ui {
class ConsoleObserver : public TemperatureObserver {
public:
	void onTemperature(const std::string& motorName, int temperature) override;

	const std::vector<std::pair<std::string, int>>& events() const;

private:
	std::vector<std::pair<std::string, int>> events_;
};
}  // namespace ui
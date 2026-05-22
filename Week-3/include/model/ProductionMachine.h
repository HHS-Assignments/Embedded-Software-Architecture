#pragma once

#include <vector>

#include "model/Machine.h"
#include "model/Mone.h"
#include "model/Mtwo.h"
#include "ui/TemperatureObserver.h"

namespace model {
class ProductionMachine : public Machine {
public:
	ProductionMachine();

	void attachObserver(ui::TemperatureObserver& observer);

	void run() override;
	void halt() override;
	Motor& motor1() override;
	Motor& motor2() override;

	Mone& mone();
	Mtwo& mtwo();

private:
	void notify(const Motor& motor, int temperature);

	Mone mone_;
	Mtwo mtwo_;
	std::vector<ui::TemperatureObserver*> observers_;
};
}  // namespace model
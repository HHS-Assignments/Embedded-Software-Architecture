#include "model/ProductionMachine.h"

namespace model {
ProductionMachine::ProductionMachine() = default;

void ProductionMachine::attachObserver(ui::TemperatureObserver& observer) {
	observers_.push_back(&observer);
}

void ProductionMachine::run() {
	mone_.start();
	const int temperature1 = mone_.tsensor().read();
	mone_.tsensor().temperatuur();
	notify(mone_, temperature1);

	mtwo_.start();
	const int temperature2 = mtwo_.tsensor().read();
	mtwo_.tsensor().temperatuur();
	notify(mtwo_, temperature2);
}

void ProductionMachine::halt() {
	mtwo_.stop();
	mone_.stop();
}

Motor& ProductionMachine::motor1() {
	return mone_;
}

Motor& ProductionMachine::motor2() {
	return mtwo_;
}

Mone& ProductionMachine::mone() {
	return mone_;
}

Mtwo& ProductionMachine::mtwo() {
	return mtwo_;
}

void ProductionMachine::notify(const Motor& motor, int temperature) {
	for (ui::TemperatureObserver* observer : observers_) {
		if (observer != nullptr) {
			observer->onTemperature(motor.name(), temperature);
		}
	}
}
}  // namespace model
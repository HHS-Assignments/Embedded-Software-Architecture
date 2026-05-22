#include "sensor/TSensor.h"

namespace sensor {
TSensor::TSensor(int& temperatureSource)
	: temperatureSource_(&temperatureSource), lastRead_(temperatureSource) {
}

int TSensor::read() {
	if (temperatureSource_ == nullptr) {
		lastRead_ = 0;
		return lastRead_;
	}

	lastRead_ = *temperatureSource_;
	return lastRead_;
}

int TSensor::temperatuur() const {
	return lastRead_;
}
}  // namespace sensor
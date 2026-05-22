#include "model/Motor.h"

#include <utility>

namespace model {
Motor::Motor(std::string name, int baseTemperature)
	: name_(std::move(name)),
	  baseTemperature_(baseTemperature),
	  running_(false),
	  currentTemperature_(baseTemperature),
	  sensor_(currentTemperature_) {
}

void Motor::start() {
	running_ = true;
	currentTemperature_ = baseTemperature_ + runningTemperatureDelta();
}

void Motor::stop() {
	running_ = false;
	currentTemperature_ = baseTemperature_;
}

sensor::TSensor& Motor::tsensor() {
	return sensor_;
}

const sensor::TSensor& Motor::tsensor() const {
	return sensor_;
}

const std::string& Motor::name() const {
	return name_;
}

bool Motor::running() const {
	return running_;
}

int Motor::temperature() const {
	return currentTemperature_;
}

int Motor::runningTemperatureDelta() const {
	return 30;
}
}  // namespace model
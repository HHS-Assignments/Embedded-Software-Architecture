#pragma once

#include <string>

#include "sensor/TSensor.h"

namespace model {
class Motor {
public:
	Motor(std::string name, int baseTemperature);
	virtual ~Motor() = default;

	Motor(const Motor&) = delete;
	Motor& operator=(const Motor&) = delete;

	virtual void start();
	virtual void stop();

	sensor::TSensor& tsensor();
	const sensor::TSensor& tsensor() const;

	const std::string& name() const;
	bool running() const;
	int temperature() const;

protected:
	virtual int runningTemperatureDelta() const;

private:
	std::string name_;
	int baseTemperature_;
	bool running_;
	int currentTemperature_;
	sensor::TSensor sensor_;
};
}  // namespace model
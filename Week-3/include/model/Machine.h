#pragma once

namespace model {
class Motor;

class Machine {
public:
	virtual ~Machine() = default;
	virtual void run() = 0;
	virtual void halt() = 0;
	virtual Motor& motor1() = 0;
	virtual Motor& motor2() = 0;
};
}  // namespace model
#pragma once

namespace sensor {
class TSensor {
public:
	explicit TSensor(int& temperatureSource);

	int read();
	int temperatuur() const;

private:
	int* temperatureSource_;
	int lastRead_;
};
}  // namespace sensor
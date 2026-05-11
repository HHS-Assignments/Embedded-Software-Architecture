#ifndef LONGBOARD_H
#define LONGBOARD_H

#include <string>
#include <utility>

namespace Domain {

class Longboard {
public:
	static Longboard& getInstance(const std::string& brand = "Arbor", int lengthCm = 104) {
		static Longboard instance(brand, lengthCm);
		return instance;
	}

	Longboard(const Longboard&) = delete;
	Longboard& operator=(const Longboard&) = delete;
	Longboard(Longboard&&) = delete;
	Longboard& operator=(Longboard&&) = delete;

	const std::string& getBrand() const {
		return brand_;
	}

	int getLengthCm() const {
		return lengthCm_;
	}

	std::string description() const;

private:
	Longboard(std::string brand, int lengthCm)
		: brand_(std::move(brand)), lengthCm_(lengthCm) {}

	std::string brand_;
	int lengthCm_;
};

} // namespace Domain

#endif

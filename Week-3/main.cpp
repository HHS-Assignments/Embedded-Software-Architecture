#include <cassert>

#include "model/ProductionMachine.h"
#include "ui/ConsoleObserver.h"

int main() {
	model::ProductionMachine machine;
	ui::ConsoleObserver consoleObserver;

	machine.attachObserver(consoleObserver);

	machine.run();

	assert(consoleObserver.events().size() == 2);
	assert(consoleObserver.events().at(0).first == "Mone");
	assert(consoleObserver.events().at(1).first == "Mtwo");
	assert(consoleObserver.events().at(0).second == 70);
	assert(consoleObserver.events().at(1).second == 75);
	assert(machine.motor1().running());
	assert(machine.motor2().running());

	machine.halt();

	assert(!machine.motor1().running());
	assert(!machine.motor2().running());

	return 0;
}

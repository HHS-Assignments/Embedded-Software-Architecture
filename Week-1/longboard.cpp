#include "longboard.h"

namespace Domain {

std::string Longboard::description() const {
    return brand_ + " longboard van " + std::to_string(lengthCm_) + " cm";
}

} // namespace Domain

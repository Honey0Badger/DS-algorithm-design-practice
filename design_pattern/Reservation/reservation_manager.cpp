#include "reservation.hpp"

static ReservationManager& ReservationManager::getInstance() {
	static ReservationManager instance;
	return instance;
}

#pragma once

#include<vector>
#include<set>


class ReservationManager {
      public:
	  static ReservationManager& getInstance();
	  ReservationManager(const ReservationManager&)  = delete;
	  void operator=(const ReservationManager& ) = delete;
      private:
	  ReservationManager(){}
	  std::vector<Table> tables;
	  std::set<Reservation> res;
};

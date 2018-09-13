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

class Table {
     public:
	 Table();
     private:
	 int ID;
	 int Nseats;
	 Schedule s;
};

class Schedule {
    private:
	 bool avail;
};

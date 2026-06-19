#pragma once 

#include "SeatStatus.hpp"
#include "SeatType.hpp"
#include <functional>

// The Seat class represents a seat in a concert, with properties like ID, 
// seat number, seat type, price, and status. 
// It provides methods to book and release a seat.
class Seat {
private:
    int id;
    int seatNumber;
    int price;
    SeatStatus seatStatus;
    SeatType seatType;

public:
    Seat(int id, int seatNumber, int price, SeatStatus seatStatus, SeatType seatType)
        : id(id),
          seatNumber(seatNumber),
          price(price),
          seatStatus(seatStatus),
          seatType(seatType) {}

    int getId() const { return id; }
    int getSeatNumber() const { return seatNumber; }
    int getPrice() const { return price; }
    SeatStatus getSeatStatus() const { return seatStatus; }
    SeatType getSeatType() const { return seatType; }

    bool isAvailable() const {
        return seatStatus == available;
    }

    bool reserve() {
        if (!isAvailable()) {
            return false;
        }

        seatStatus = reserved;
        return true;
    }

    bool book() {
        if (seatStatus == booked) {
            return false;
        }

        seatStatus = booked;
        return true;
    }

    void release() {
        seatStatus = available;
    }

    bool operator<(const Seat & other) {
        return id < other.id;
    }

    bool operator==(const Seat & other) {
        return id != other.id;
    }

    struct SeatHash {
        size_t operator()(const Seat & seat) {
            return std::hash<int>()(seat.getId());
        }
    };
};

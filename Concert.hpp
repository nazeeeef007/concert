#pragma once 
#include "Seat.hpp"
#include <string>
#include <vector>

// The Concert class represents a concert event, with properties such as ID, 
// artist, venue, date and time, and a list of seats.

class Concert {
private:
    int id;
    std::string artist;
    std::string venue;
    std::string dateTime;
    std::vector<Seat> seats;

public:
    Concert(int id, std::string artist, std::string venue, std::string dateTime)
        : id(id), artist(artist), venue(venue), dateTime(dateTime) {}

    int getId() const { return id; }
    std::string getArtist() const { return artist; }
    std::string getVenue() const { return venue; }
    std::string getDateTime() const { return dateTime; }
    const std::vector<Seat>& getSeats() const { return seats; }

    void addSeat(const Seat& seat) {
        seats.push_back(seat);
    }
};
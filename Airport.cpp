# include "Airport.h"

Airport::Airport() { }

Airport::~Airport() {
    airport_ID = 0;
    airport_name = "";
    airport_IATAcode = "";
    airport_position = std::make_pair(0,0);
    airport_location = std::make_pair("", "");
}

Airport::Airport(const Airport& other) {
    airport_ID = other.getAirportID();
    airport_name = other.getAirportName();
    airport_IATAcode = other.getAirportIATACode();
    airport_position = other.getAirportPosition();
    airport_location = other.getAirportLocation();
}

Airport::Airport(unsigned ID, string name, string IATAcode, double latitude, double longitude, string city = "", string country = "", double altitude = 0) {
    airport_ID = ID;
    airport_name = name;
    airport_IATAcode = IATAcode;
    airport_position = std::make_pair(latitude, longitude);
    airport_location = std::make_pair(city, country);
    airport_altitude = altitude;
}

// getters for airports
unsigned Airport::getAirportID() const {
    return airport_ID;
}

string Airport::getAirportName() const {
    return airport_name;
}
    
string Airport::getAirportIATACode() const {
    return airport_IATAcode;
}
    
pair<double, double> Airport::getAirportPosition() const {
    return airport_position;
}
    
pair<std::string, std::string> Airport::getAirportLocation() const {
    return airport_location;
}

double Airport::getAirportAltitude() const {
    return airport_altitude;
}

// delete the get altitude here
bool Airport::operator==(const Airport& other) const {
    if (airport_ID != other.airport_ID || airport_name != other.airport_name || airport_position != other.airport_position
        || airport_location != other.airport_location) {
        return false;
    }
    return true;
}


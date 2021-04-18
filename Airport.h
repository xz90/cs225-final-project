# pragma once
# include <string>

using namespace std;
class Airport
{
private:
    /* data */
    unsigned airport_ID;
    string airport_name;
    string airport_IATAcode;
    pair<double, double> airport_position; // <latitude, longitude> of certain airport
    pair<string, string> airport_location; // <city, country> of certain airport
    double airport_altitude;

public:

    Airport();
    /**
     * Copy Constructor  
     */
    Airport(const Airport& other);

    /**
     * string city, string country, double altitude: these 3 variables have default values, no need to use if unnecessary
     */
    Airport(unsigned ID, string name, string IATAcode, double latitude, double longitude, string city, string country, double altitude);

    ~Airport();

    
    // getter functions
    unsigned getAirportID() const;
    string getAirportName() const;
    string getAirportIATACode() const;
    pair<double, double> getAirportPosition() const;
    pair<string, string> getAirportLocation() const;
    double getAirportAltitude() const;
    
    // overload operator
    bool operator==(const Airport& other) const;


};



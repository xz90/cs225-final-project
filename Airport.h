# pragma once
# include <string>

using namespace std;
class Airport
{
private:
    /* data */ //start to count from 0
    unsigned airport_ID;    //0
    string airport_name;    //1
    string airport_IATAcode;    //4
    pair<double, double> airport_position; // <latitude, longitude> of certain airport  //5, 6
    pair<string, string> airport_location; // <city, country> of certain airport    //2, 3
    double airport_altitude;    //8

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



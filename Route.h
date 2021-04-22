# pragma once
# include <string>
# include "Airport.h"

using namespace std;
class Route
{
private:
    /* data */ 
    //unsigned route_ID;    //1
    string route_IATAcode;  //0
    Airport source_airport; //2
    Airport detination_airport; //4
    unsigned route_stops;   //7
    double route_distance;  //

public:

    /**
     * string city, string country, double altitude: these 3 variables have default values, no need to use if unnecessary
     */
    Route(string IATAcode, Airport& source, Airport& destination, unsigned stops);
    
    // getter functions
    //unsigned getRouteID() const;
    string getRouteIATACode() const;
    const Airport& getSourceAirport() const;
    const Airport& getDestinationAirport() const;
    double getRouteStops() const;
    double getDistance() const;
    
    // calculate the distance between two airports
    double calculateDistance() const;

};
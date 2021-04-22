# pragma once
# include <string>
# include "Airport.h"

using namespace std;
class Route
{
private:
    /* data */ 
    unsigned route_ID;    
    string route_IATAcode;  
    Airport source_airport;
    Airport detination_airport;
    unsigned route_stops;
    double route_distance;

public:

    /**
     * string city, string country, double altitude: these 3 variables have default values, no need to use if unnecessary
     */
    Route(unsigned ID, string IATAcode, Airport& source, Airport& destination, unsigned stops);
    
    // getter functions
    unsigned getRouteID() const;
    string getRouteIATACode() const;
    const Airport& getSourceAirport() const;
    const Airport& getDestinationAirport() const;
    double getRouteStops() const;
    double getDistance() const;
    
    // calculate the distance between two airports
    double calculateDistance() const;

};
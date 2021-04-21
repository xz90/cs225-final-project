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
    const Airport& source_airport;
    const Airport& detination_airport;
    unsigned route_stops;
    double route_distance;

public:

    /**
     * string city, string country, double altitude: these 3 variables have default values, no need to use if unnecessary
     */
    Route(unsigned ID, string IATAcode, const Airport& source, const Airport& destination, unsigned stops);
    
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

# include "Route.cpp"

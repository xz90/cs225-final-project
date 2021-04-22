# include "Route.h"
#include <cmath>

#define pi 3.14159265358979323846


Route::Route(unsigned ID, string IATAcode, Airport& source, Airport& destination, unsigned stops) : source_airport(source), detination_airport(destination) {
    route_ID = ID;
    route_IATAcode = IATAcode;
    route_stops = stops;
    route_distance = calculateDistance();
}

unsigned Route::getRouteID() const {
    return route_ID;
}

std::string Route::getRouteIATACode() const {
    return route_IATAcode;
}
   
const Airport& Route::getSourceAirport() const {
    return source_airport;
}
    
const Airport& Route::getDestinationAirport() const {
    return detination_airport;
}
    
double Route::getRouteStops() const {
    return route_stops;
}

double Route::getDistance() const {
    return route_distance;
}

double toRad(double degree) {
    return degree/180 * pi;
}
double Route::calculateDistance() const {
    double dist;
    double lat1 = source_airport.getAirportPosition().first;
    double long1 = source_airport.getAirportPosition().second;
    double lat2 = detination_airport.getAirportPosition().first;
    double long2 = detination_airport.getAirportPosition().second;
    dist = sin(toRad(lat1)) * sin(toRad(lat2)) + cos(toRad(lat1)) * cos(toRad(lat2)) * cos(toRad(long1 - long2));
    dist = acos(dist);
    dist = 6371 * dist;
    return dist;
}


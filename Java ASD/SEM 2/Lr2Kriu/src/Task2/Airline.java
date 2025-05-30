package Task2;

import java.util.*;

class Airline {
    private final List<Flight> flights = new ArrayList<>();

    public void addFlight(Flight flight) {
        flights.add(flight);
    }

    public void removeFlight(String destination) {
        List<Flight> toRemove = new ArrayList<>();
        for (Flight flight : flights) {
            if (flight.getDestination().equalsIgnoreCase(destination)) {
                toRemove.add(flight);
            }
        }
        if (!toRemove.isEmpty()) {
            flights.removeAll(toRemove);
            System.out.println("Flight(s) removed successfully.");
        } else {
            System.out.println("No flights found with that destination.");
        }
    }


    public void searchByDepartureTime(String departureTime) {
        boolean found = false;
        for (Flight flight : flights) {
            if (flight.getDepartureTime().equals(departureTime)) {
                System.out.println(flight);
                found = true;
            }
        }
        if (!found) {
            System.out.println("No flights found with that departure time.");
        }
    }

    public void searchByAirlineName(String airlineName) {
        boolean found = false;
        for (Flight flight : flights) {
            if (flight.getAirlineName().equalsIgnoreCase(airlineName)) {
                System.out.println(flight);
                found = true;
            }
        }
        if (!found) {
            System.out.println("No flights found with that airline name.");
        }
    }

    public void searchByDestination(String destination) {
        boolean found = false;
        for (Flight flight : flights) {
            if (flight.getDestination().equalsIgnoreCase(destination)) {
                System.out.println(flight);
                found = true;
            }
        }
        if (!found) {
            System.out.println("No flights found for the given destination.");
        }
    }

    public void printFlights() {
        for (Flight flight : flights) {
            System.out.println(flight);
        }
    }
}


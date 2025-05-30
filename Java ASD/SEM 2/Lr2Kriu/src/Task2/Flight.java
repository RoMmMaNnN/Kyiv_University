package Task2;

class Flight {
    private final String destination;
    private final String departureTime;
    private final String airlineName;

    public Flight(String destination, String departureTime, String airlineName) {
        this.destination = destination;
        this.departureTime = departureTime;
        this.airlineName = airlineName;
    }

    public String getDestination() {
        return destination;
    }

    public String getDepartureTime() {
        return departureTime;
    }

    public String getAirlineName() {
        return airlineName;
    }

    @Override
    public String toString() {
        return "Flight [Destination: " + destination + ", Departure Time: " + departureTime + ", Airline: " + airlineName + "]";
    }
}


package com.avaj;

public class Aircraft {
    protected long id;
    protected String name;
    protected Coordinates coordinates;
    private static long idCounter = 0;

    protected Aircraft(String name, Coordinates coordinates) {
        this.id = this.nextId();
        this.name = name;
        this.coordinates = coordinates;
    }

    private long nextId() {
        Aircraft.idCounter++;
        return Aircraft.idCounter;
    }

    public String aircraftLocation() {
        return "Longitude: " + this.coordinates.getLongitude() + ", latitude: " + this.coordinates.getLatitude();
    }

    protected void modifyCoordinates(int[] newCoords) {
        this.coordinates.setLongitude(newCoords[0]);
        this.coordinates.setLatitude(newCoords[1]);
        this.coordinates.setHeight(Math.min(newCoords[2], 100));
    }
}

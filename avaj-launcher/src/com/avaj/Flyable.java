package com.avaj;

public interface Flyable {
    void updateConditions();

    void registerTower(WeatherTower weatherTower);

    String aircraftIdentity();

    String aircraftLocation();
}

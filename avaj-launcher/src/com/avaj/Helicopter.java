package com.avaj;

import java.util.Map;

public class Helicopter extends Aircraft implements Flyable {
    private WeatherTower weatherTower;

    Helicopter(String name, Coordinates coordinates) {
        super(name, coordinates);
    }

    public void updateConditions() {
        String weather = this.weatherTower.getWeather(this.coordinates);
        Map<String, int[]> coordinatesChanges = Map.of(
                "RAIN", new int[]{this.coordinates.getLongitude() + 5, this.coordinates.getLatitude(), this.coordinates.getHeight()},
                "FOG", new int[]{this.coordinates.getLongitude() + 1, this.coordinates.getLatitude(), this.coordinates.getHeight()},
                "SUN", new int[]{this.coordinates.getLongitude() + 10, this.coordinates.getLatitude(), this.coordinates.getHeight() + 2},
                "SNOW", new int[]{this.coordinates.getLongitude(), this.coordinates.getLatitude(), this.coordinates.getHeight() - 12}
        );
        Map<String, String> weatherReaction = Map.of(
                "RAIN", this.aircraftIdentity() + ": It's raining men, hallelujah, it's raining men, amen.",
                "FOG", this.aircraftIdentity() + ": I was looking into this fog, and just thinking how did I get here?",
                "SUN", this.aircraftIdentity() + ": Sunshine, sunshine reggae, don't worry, don't hurry, take it easy!",
                "SNOW", this.aircraftIdentity() + ": we need more blankets, this people are going to freeze in here."
        );
        this.modifyCoordinates(coordinatesChanges.get(weather));
        this.weatherTower.addMessage(weatherReaction.get(weather));
        if (this.coordinates.getHeight() <= 0) {
            this.weatherTower.unregister(this);
        }
    }

    public void registerTower(WeatherTower weatherTower) {
        this.weatherTower = weatherTower;
    }

    public String aircraftIdentity() {
        return "Helicopter#" + this.name + "(" + this.id + ")";
    }
}

package com.avaj;

import java.util.Map;

public class Baloon extends Aircraft implements Flyable {
    private WeatherTower weatherTower;

    Baloon(String name, Coordinates coordinates) {
        super(name, coordinates);
    }

    public void updateConditions() {
        String weather = this.weatherTower.getWeather(this.coordinates);
        Map<String, int[]> coordinatesChanges = Map.of(
                "RAIN", new int[]{this.coordinates.getLongitude(), this.coordinates.getLatitude(), this.coordinates.getHeight() - 5},
                "FOG", new int[]{this.coordinates.getLongitude(), this.coordinates.getLatitude(), this.coordinates.getHeight() - 3},
                "SUN", new int[]{this.coordinates.getLongitude() + 2, this.coordinates.getLatitude(), this.coordinates.getHeight() + 4},
                "SNOW", new int[]{this.coordinates.getLongitude(), this.coordinates.getLatitude(), this.coordinates.getHeight() - 15}
        );
        Map<String, String> weatherReaction = Map.of(
                "RAIN", this.aircraftIdentity() + ": it's water, water is everywhere, I don't like it.",
                "FOG", this.aircraftIdentity() + ": can not see anything this fucking fog.",
                "SUN", this.aircraftIdentity() + ": Sun is shining, the weather is sweet.",
                "SNOW", this.aircraftIdentity() + ": it was wonderful ride, we almost freeze our asses off on that balloon."
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
        return "Baloon#" + this.name + "(" + this.id + ")";
    }
}

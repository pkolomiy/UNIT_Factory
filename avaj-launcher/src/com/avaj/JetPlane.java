package com.avaj;

import java.util.Map;

public class JetPlane extends Aircraft implements Flyable {
    private WeatherTower weatherTower;

    JetPlane(String name, Coordinates coordinates) {
        super(name, coordinates);
    }

    public void updateConditions() {
        String weather = this.weatherTower.getWeather(this.coordinates);
        Map<String, int[]> coordinatesChanges = Map.of(
                "RAIN", new int[]{this.coordinates.getLongitude(), this.coordinates.getLatitude() + 5, this.coordinates.getHeight()},
                "FOG", new int[]{this.coordinates.getLongitude(), this.coordinates.getLatitude() + 1, this.coordinates.getHeight()},
                "SUN", new int[]{this.coordinates.getLongitude(), this.coordinates.getLatitude() + 10, this.coordinates.getHeight() + 2},
                "SNOW", new int[]{this.coordinates.getLongitude(), this.coordinates.getLatitude(), this.coordinates.getHeight() - 7}
        );
        Map<String, String> weatherReaction = Map.of(
                "RAIN", this.aircraftIdentity() + ": attention passengers this is your captain speaking, we seem to be experiencing a little turbulence.",
                "FOG", this.aircraftIdentity() + ": I can't see anything, we better not hit any mountains..",
                "SUN", this.aircraftIdentity() + ": good think I didn't forget to take my sunglasses with me.",
                "SNOW", this.aircraftIdentity() + ": we saw beautiful frost patterns on our windows."
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
        return "JetPlane#" + this.name + "(" + this.id + ")";
    }
}

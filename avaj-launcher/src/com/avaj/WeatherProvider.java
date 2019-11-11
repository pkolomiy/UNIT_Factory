package com.avaj;

import java.util.Random;

public class WeatherProvider {
    private static WeatherProvider weatherProvider = new WeatherProvider();
    private static String[] weather = {"RAIN", "FOG", "SUN", "SNOW"};

    private WeatherProvider() {
    }

    public static WeatherProvider getProvider() {
        return WeatherProvider.weatherProvider;
    }

    public String getCurrentWeather(Coordinates coordinates) {
        return weather[((coordinates.getHeight() % 4) +
                        (coordinates.getLatitude() % 4) +
                        (coordinates.getLongitude() % 4) +
                        new Random().nextInt(4)) % 4];
    }
}

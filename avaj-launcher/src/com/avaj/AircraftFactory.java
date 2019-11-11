package com.avaj;

public class AircraftFactory {
    public static Flyable newAircraft(String type, String name, int longitude, int latitude, int height) {
        try {
            return (Flyable) Class.forName("com.avaj." + type)
                    .getDeclaredConstructor(String.class, Coordinates.class)
                    .newInstance(name, new Coordinates(longitude, latitude, height));
        } catch (Exception e) {
            System.out.println("Class name " + e.getMessage() + " not found");
        }
        return null;
    }
}

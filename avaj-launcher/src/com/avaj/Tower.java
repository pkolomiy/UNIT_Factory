package com.avaj;

import java.util.ArrayList;

public class Tower {
    private ArrayList<Flyable> observers = new ArrayList<>();
    private ArrayList<String> out = new ArrayList<>();

    protected void conditionsChanged() {
        ArrayList<Flyable> temp = new ArrayList<>(this.observers);
        for (Flyable aircraft : temp) {
            aircraft.updateConditions();
        }
    }

    public void register(Flyable flyable) {
        this.observers.add(flyable);
        out.add("Tower says: " + flyable.aircraftIdentity() + " registered to weather tower.");
    }

    public void unregister(Flyable flyable) {
        this.observers.remove(flyable);
        out.add(flyable.aircraftIdentity() + " landing. " + flyable.aircraftLocation());
        out.add("Tower says: " + flyable.aircraftIdentity() + " unregistered from weather tower.");
    }

    public void addMessage(String message) {
        out.add(message);
    }

    public String dump() {
        return String.join("\n", this.out);
    }
}

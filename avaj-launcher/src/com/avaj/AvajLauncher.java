package com.avaj;

import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.concurrent.TimeUnit;

public class AvajLauncher {
    public static void main(String[] args) {
        try {
            Simulator simulator = readFile(args);
            simulator.run();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private static Simulator readFile(String[] args) throws Exception {
        if (args.length != 1) {
            throw new Usage();
        }
        Path path = Paths.get(args[0]);
        if (!Files.isReadable(path)) {
            throw new InvalidFile();
        }
        List<String> allLines = Files.readAllLines(path);
        if (allLines.size() < 2) {
            throw new InvalidFile();
        }
        return new Simulator(allLines);
    }
}

class Simulator {
    private List<String> lines;
    private int counter;
    private long prevTime;

    Simulator(List<String> allLines) {
        this.lines = allLines;
        this.prevTime = System.currentTimeMillis();
    }

    void run() throws Exception {
        this.validateCounter();
        WeatherTower tower = new WeatherTower();
        int lineNumber = 2;
        for (String line : this.lines) {
            prevTime = System.currentTimeMillis();
            tower.register(this.newAircraft(line, lineNumber, tower));
            lineNumber++;
        }
        while (this.counter != 0) {
            tower.conditionsChanged();
            this.counter--;
        }
        PrintWriter writer = new PrintWriter("simulation.txt", StandardCharsets.UTF_8);
        writer.println(tower.dump());
        writer.close();
    }

    private int getNumber(String number) throws Exception {
        if (number.length() == 32) {
            long currentTime = System.currentTimeMillis();
            if (currentTime - this.prevTime < 6000) {
                TimeUnit.SECONDS.sleep(6);
                this.prevTime = System.currentTimeMillis();
            }
            if ((number = Md5Decode.decode(number)) == null) {
                throw new Exception();
            }
        }
        return Integer.parseInt(number);
    }

    private void validateCounter() throws Exception {
        String counter = this.lines.get(0).trim();
        this.lines.remove(0);
        try {
            this.counter = this.getNumber(counter);
        } catch (Exception e) {
            throw new InvalidCounter();
        }
        if (this.counter < 1) {
            throw new InvalidCounter();
        }
    }

    private Flyable newAircraft(String line, int lineNumber, WeatherTower tower) throws Exception {
        String[] splitted = Arrays.stream(line.split(" "))
                .filter(s -> !s.trim().isEmpty()).toArray(String[]::new);
        if (splitted.length != 5) {
            throw new InvalidAircraft(lineNumber);
        }
        String type = splitted[0];
        Map<String, String> allTypes = Map.of("994736b4f0aec72f6e5ae580051d012f", "Baloon",
                "554cd647d6b135f7e36ab1214c5e816a", "JetPlane",
                "2ab8b43468e8b92b0fc5c81e70e35a2d", "Helicopter",
                "Baloon", "Baloon", "JetPlane", "JetPlane", "Helicopter", "Helicopter");
        if (!allTypes.containsKey(type)) {
            throw new InvalidAircraftType(lineNumber);
        }
        type = allTypes.get(type);
        int longitude, latitude, height;
        try {
            longitude = this.getNumber(splitted[2]);
            latitude = this.getNumber(splitted[3]);
            height = this.getNumber(splitted[4]);
            if (height < 0 || height > 100) {
                throw new Exception();
            }
        } catch (Exception e) {
            throw new InvalidAircraftCoordinates(lineNumber);
        }
        Flyable aircraft = AircraftFactory.newAircraft(type, splitted[1], longitude, latitude, height);
        aircraft.registerTower(tower);
        return aircraft;
    }
}

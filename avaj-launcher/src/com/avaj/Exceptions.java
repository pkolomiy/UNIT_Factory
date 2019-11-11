package com.avaj;

class Usage extends Exception {
    @Override
    public String getMessage() {
        return "usage: ./run filename";
    }
}

class InvalidFile extends Exception {
    @Override
    public String getMessage() {
        return "Invalid file";
    }
}

class InvalidCounter extends Exception {
    @Override
    public String getMessage() {
        return "Invalid number of simulations";
    }
}

class InvalidAircraft extends Exception {
    int lineNumber;
    InvalidAircraft(int lineNumber) {
        this.lineNumber = lineNumber;
    }

    @Override
    public String getMessage() {
        return "Invalid aircraft on line: " + lineNumber;
    }
}

class InvalidAircraftType extends InvalidAircraft {
    InvalidAircraftType(int lineNumber) {
        super(lineNumber);
    }

    @Override
    public String getMessage() {
        return "Invalid aircraft type on line: " + lineNumber;
    }
}

class InvalidAircraftCoordinates extends InvalidAircraft {
    InvalidAircraftCoordinates(int lineNumber) {
        super(lineNumber);
    }

    @Override
    public String getMessage() {
        return "Invalid aircraft coordinates on line: " + lineNumber;
    }
}


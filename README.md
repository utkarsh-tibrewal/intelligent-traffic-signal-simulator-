# Intelligent Traffic Signal Simulator

A beginner-friendly, menu-driven C project that simulates traffic signal green-time allocation for a four-way intersection.

## Overview

The program collects vehicle and pedestrian counts for the North, South, East, and West lanes. It then calculates a green-light duration for each lane using a simple predefined formula.

Users can view the current intersection status and save traffic cycle reports to a text file.

## Features

* Four-way intersection simulation
* Vehicle and pedestrian data entry
* Validation of negative counts
* Automatic green-time calculation
* Maximum green-time limit of 60 seconds
* Display of intersection status
* File handling to save traffic cycle reports

## Green-Time Calculation

The program starts with a base green time of 10 seconds.

* An additional 2 seconds are added for every complete group of 5 vehicles.
* An additional 5 seconds are added when the pedestrian count exceeds 3.
* The final green time is capped at 60 seconds.

**Note:** This is a simplified educational formula, not a real-world traffic control algorithm.

## Concepts Practised

* Structures (`struct`)
* Arrays
* Functions
* Loops and conditional statements
* Input validation
* File handling using `FILE`, `fopen()`, `fprintf()`, and `fclose()`

## How to Run

1. Install a C compiler such as GCC.

2. Download or clone this repository.

3. Open a terminal in the project directory.

4. Compile the program:

   ```bash
   gcc traffic_simulator.c -o traffic_simulator
   ```

5. Run it on Linux or macOS:

   ```bash
   ./traffic_simulator
   ```

   On Windows, using a compatible terminal:

   ```powershell
   .\traffic_simulator.exe
   ```

## Menu Options

1. Enter traffic data and calculate green time.
2. Display the current intersection status.
3. Save the current traffic cycle to a log file.
4. Exit the simulator.

## Future Improvements

* Handle non-numeric input safely.
* Add timestamps to traffic cycle reports.
* Load previously saved traffic data.
* Improve the traffic allocation formula.

## Author

A first-year B.Tech CSE (AI & ML) student learning C programming through hands-on projects.

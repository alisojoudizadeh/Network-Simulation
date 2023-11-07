# Queuing Simulation Program

This is a C++ program that simulates a queuing system using arrival and service time distributions.

## Overview

This program simulates a queuing system and provides statistics on customer waiting times, queue length, and time spent by customers in the system. It consists of the following steps:

1. Arrival Time Table Information: Enter the arrival times and their probabilities.
2. Service Time Table Information: Enter the service times and their probabilities.
3. Time Between Arrivals Determination: Generate random time between arrivals.
4. Service Time Determination: Generate random service times.
5. Simulation Table: Create a simulation table for the queuing problem.
6. Average Waiting Time For Customer: Calculate the average waiting time for customers.
7. Average Queue Length: Calculate the average queue length.
8. Average Time Spent by a Customer: Calculate the average time spent by a customer.

## Usage

1. Compile the code using a C++ compiler.
2. Run the program and follow the prompts to input parameters.
3. Choose from various options to view distribution tables and simulation results.
4. Exit the program when you're done.

## Example Usage

```shell
$ g++ queuing_simulation.cpp -o queuing_simulation
$ ./queuing_simulation


	•	1: Show distribution table of time between arrivals.
	•	2: Show distribution table of service time.
	•	3: Show TBA Determination.
	•	4: Show ST Determination.
	•	5: Show Simulation Table.
	•	6: Average Waiting Time For Customer.
	•	7: Average Queue Length.
	•	8: Average Time Spent by a Customer.
	•	0: Exit the program.

License

This code is available under the "Sahand University of Technology" License.

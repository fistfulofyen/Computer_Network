# Computer_Network

## Overview

This repository contains simulation projects for Computer Network Communications. This simulation is designed to help students understand and experiment with various concepts related to computer networks, internet protocols, and advanced communication techniques. These simulation uses Simlib library, it consists of a set of C functions which facilitate learning about discrete event simulation of computer networks.

## Features

- **Performance of a Single Server Queueing System**: This lab is an introduction to the performance of single-server queueing systems. A program written in C is used to investigate the behaviour of single server queueing systems where customers with fixed service times arrive according to a Poisson process.

- **Packet Switched Network and Integrated Voice Performance**: This lab is an introduction to discrete-event simulation using the Simlib library. The provided C code simulation models a system where packets arrive at a packet switching node and are stored in a buffer, awaiting transmission on an output link. It is assumed that the packets are fixed in length and arrive according to a Poisson process.

- **Call Blocking in Circuit Switched Networks**: This lab first investigates call blocking in a circuit switched network. Call arrivals occur to a cellular basestation containing N communication channels. If a channel is available when a call arrives, it is assigned to the call for its duration, otherwise the call is blocked. A computer simulation is used to assess the blocking behaviour of the system with Poisson process call arrivals and exponentially distributed call holding times. The simulation results are compared to theory using the Erlang B formula.

- **The ALOHA Media Access Control Protocol**: This lab investigates the performance of the ALOHA media access control proto- col. In the provided ALOHA simulation code, the random backoff used by the stations is exponentially distributed with a fixed mean. Performance results are obtained us- ing this simulation for various combinations of numbers of stations and mean backoff.

## Getting Started

To get started with this simulation, follow these steps:

1. **Clone the Repository**: Clone this repository to your local machine. I used VScode, you can use whatever you like.

## License

Copyright (C) ~~our lord and savior~~ Dr. Terence D. Todd Hamilton, Ontario, CANADA,
Todd@mcmaster.ca

Happy simulating![]-(￣▽￣)~*

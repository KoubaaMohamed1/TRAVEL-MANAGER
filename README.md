# TRAVEL-MANAGER
Travel-Manager is a simple CMD application for managing a travel agency coded in C language. It allows users to view all available trips between two dates and manage the dates of the trips.

Travel-Manager also has the following features:

ajouter(): adds a new trip to the list of trips.
description(): displays the description of a specific trip.
supprimer(): removes a trip from the list of trips.
modifier(): modifies the information for a specific trip.
recherche(): searches for available trips between two specified dates.
afficher(): displays the list of all trips.

The program uses a linked list data structure to store information about the trips, with the following fields:
nom: the name of the trip.
destination: the destination of the trip.
debut: the start date of the trip (in jjmmaaaa format).
fin: the end date of the trip (in jjmmaaaa format).
prix: the price of the trip.
next: a pointer to the next trip in the linked list.

The struct Trip type is defined to store the information about a single trip. It contains fields for the destination, name, price, start and end dates, and a pointer to the next trip in the list. 

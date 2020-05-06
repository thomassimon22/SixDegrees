/*
 * Filename: Actor.h
 * Contains: Implementation of the template Actors class 
 * Part of: Homework 5 assignment "Graph Traversal" for Comp 15 Spring 2019
 *
 */

#include "Actor.h"

// Function: constructor
Actor::Actor(){
	name = "";
}
 
// Function: paramererized constructor
Actor::Actor(string name){
	this->name = name;
}

// Function: ==
// Parameters: actor
// Returns: bool
// Does: returns true if the actors names are the same
bool Actor::operator==(const Actor& other){
	return name == other.name;
}

// Function: !=
// Parameters: actor
// Returns: bool
// Does: Returns true if two actors aren't the same
bool Actor::operator!=(const Actor& other){
	if (*this == other){
		return false;
	}
	else {
		return true;
	}
}

// Function: <<
// Parameters: ostream & actor
// Returns: ostream object
// Does: Prints actors name to ostream
ostream & operator<<(ostream& os, const Actor& actor){
	os << actor.name;
	return os;
}

// Function: insert_movie
// Parameters: string name of movie
// Returns: N/A
// Does: Insert movie into actors movies
void Actor::insert_movie(string movie){
	movies.insert(movie);
}

// Function: acted
// Parameters: string name of movie
// Returns: boolean
// Does: returns true if an actor has acted in a movie
bool Actor::acted(string movie) const {
	bool found = false;
	movies.find(movie, found);
	return found;
}

// Function: connect
// Parameters: other actor
// Returns: string movie name
// Does: Returns the same movies an actor and other  
//		 actor have both been in
string Actor::connect(const Actor& other) const
{
    bool connection = false;  
    int size = movies.get_length();
    string movie = "";

    for (int i = 0; i < size and !connection; i++) {
        movie = movies.get_value_at(i);
        connection = other.acted(movie);
    }

    // return accordingly
    if (connection == true) {
        return movie;
    } else {
        return "";
    }
}









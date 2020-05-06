/*
 * Filename: Actor.h
 * Contains: Interface of the template Actor class 
 * Part of: Homework 5 assignment "Graph Traversal" for Comp 15 Spring 2019
 *
 */

#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include "LinkedList.h"
#include "Graph.h"

using namespace std;

class Actor{
	public: 
		Actor();
		Actor(string);
		bool operator!=(const Actor&);
		bool operator==(const Actor&);
		friend ostream & operator<<(ostream&, const Actor&);

		void insert_movie(string);
		bool acted(string movie) const;
		string connect(const Actor&) const;

		string name;
		LinkedList<string> movies;

};

#endif

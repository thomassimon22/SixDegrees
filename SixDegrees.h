/*
 * Filename: SixDegrees.h
 * Contains: Interface of the template SixDegrees
 * Part of: Homework 5 assignment "Graph Traversal" for Comp 15 Spring 2019
 *
 */

#ifndef SIXDEGREES_H
#define SIXDEGREES_H

#include <fstream>
#include <string>
#include <vector>
#include "Actor.h"
#include "Graph.h"

using namespace std;

class SixDegrees{
	public: 
		void run(istream &in, ostream &out);
		void BFS(Actor a, Actor b, ostream &out);
	private:
		void read_in_actors(istream&);

		Graph<string> actor_grid;
};

#endif

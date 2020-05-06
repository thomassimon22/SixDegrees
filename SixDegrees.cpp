/*
 * Filename: SixDegrees.cpp
 * Contains: Implementation of the template SixDegrees class 
 * Part of: Homework 5 assignment "Graph Traversal" for Comp 15 Spring 2019
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include "SixDegrees.h"
#include "Queue.h"
#include "LinkedList.h"
#include "Graph.h"
#include "Actor.h"

using namespace std;

//Function: read_in_actors
//Inputs: none
//Outputs: none
//Does: fills in the graph
void SixDegrees::read_in_actors(istream& inStream){
	string aname;
	vector<Actor> actors;
	int count = 0;

	while(getline(inStream, aname)){
		Actor actor;
		actor.name = aname;
		string movie;
		count ++;
		while(getline(inStream, movie)){
			if (movie == "*"){
				break;
			}
			actor.movies.insert(movie);
		}

		actors.push_back(actor);
	}
	actor_grid.initialize_graph(actors.size());

	for (unsigned int i = 0; i < actors.size(); i++){
		actor_grid.add_vertex(actors[i].name);
	}

	for(unsigned int i = 0; i < actors.size(); i++){	
		for (unsigned int j = 0; j < actors.size(); j++){
			if (i == j){
				actor_grid.add_edge(actors[i].name, actors[j].name, NULL_EDGE);
			} else {
				for (int k = 0; k < actors[i].movies.get_length(); k++){
					string movie1 = actors[i].movies.get_value_at(k);
					bool breaking = false;
					for (int l = 0; l < actors[j].movies.get_length(); l++){
						string movie2 = actors[j].movies.get_value_at(l);
						if (movie1 == movie2){
							actor_grid.add_edge(actors[i].name, actors[j].name, movie1);
							breaking = true;
							break;
						}
					}
					if (breaking) {
						break;
					}
				}
			}
		}
	}

}

// Function: run
// Parameters: ostream to print
// Returns: none
// Does: runs all of sixdegrees
void SixDegrees::run(istream &in, ostream &out){
	ifstream actors("actors.txt");
	read_in_actors(actors);


	string name1;
	string name2;
    
    Actor actor1;
    Actor actor2;

    out << "Enter two actor names separated by a new line." << endl;
    out << "Press ctrl-D to quit" << endl;

    while (!in.eof()){
    	
        getline(in, name1);
        actor1.name = name1;
        
        while (!actor_grid.is_vertex(name1) and !in.eof()){
            out << "Sorry, " << actor1.name << " is not in the list" << endl << endl;
            getline(in, name1);
            actor1.name = name1;
        }

        getline(in, name2);
        actor2.name = name2;
      
        while (!actor_grid.is_vertex(name2) and !in.eof())
        {
            out << "Sorry, " << actor2.name << " is not in the list" << endl << endl;
            getline(in, name2);
            actor2.name = name2;
        }

        if (!(actor1.name == "" or actor2.name == "")){
        	BFS(actor1, actor2, out);
        }
        out << endl;
    }
    
}

// Function: BFS
// Parameters: ostream to print, start and end vertices
// Returns: void
// Does: Breath first seach of actors grid
void SixDegrees::BFS(Actor a, Actor b, ostream &out){
    actor_grid.clear_marks();
    actor_grid.initialize_path();

    Queue<string> v;
    Queue<string> n;

    if (a == b){
    	out << "Same actor" << endl << endl;
    	return;
    }

    v.enqueue(a.name);

    bool path_found = true;
     
    while (!v.is_empty()){
        string check;
        v.dequeue(check);
	if (check == b.name){
		path_found = true;
		break;
	}

	actor_grid.mark_vertex(check);
    actor_grid.get_to_vertices(check, n);

	while (!n.is_empty()){
		string neighbor;
		n.dequeue(neighbor);
		if (actor_grid.is_marked(neighbor)){
			continue;
		}
		v.enqueue(neighbor);
		actor_grid.update_predecessor(check, neighbor);
	}
    }

    if (path_found == true){
    	actor_grid.report_path(out, a.name, b.name);
    	out << endl;
    } else {
    	out << a.name << " and " << b.name << ": No connection" << endl << endl;
    } 
}





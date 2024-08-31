//UMBC - CSEE - CMSC 341 - Fall 2022 - Proj1
#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;
enum DIRECTION {NORTH, SOUTH, EAST, WEST, NONE};
const int DEFNUMPASS = 10; // default number of passengers
class Grader;
class Tester;
class Railroad;
class Station{
    public:
    friend class Grader;
    friend class Tester;
    friend class Railroad;
    // Empty constructor
    // code and passengers are 0
    Station():m_code(0), m_passengers(0), 
        // previous and next station are nullptr
        m_next(nullptr), m_previous(nullptr),
        // north and south are nullptr
        m_north(nullptr), m_south(nullptr),
        // east and west are nullptr
        m_east(nullptr), m_west(nullptr){}
    // Overloaded constructor with code and number of passengers
    Station(int c, int p):m_code(c), m_passengers(p), 
        // previous and next station are nullptr
        m_next(nullptr), m_previous(nullptr),
        // north and south are nullptr
        m_north(nullptr),m_south(nullptr),
        // east and west are nullptr
        m_east(nullptr), m_west(nullptr){}
    // Overloaded constructor with all values
    Station(int c, int p, Station* n, Station* s, Station* e, Station* w):
       // code and passengers values
        m_code(c),m_passengers(p), 
        // north and south values
        m_north(n),m_south(s),
        // east and west values
        m_east(e),m_west(w){}
    // Destructor... does nothing
    ~Station(){}
    // setter for station code
    void setStationCode(int aValue){m_code = aValue;}
    // geter for station code
    int getStationCode(){return m_code;}
    // setter for number of passengers
    void setNumPassengers(int p){m_passengers=p;}
    // getter for number of passengers
    int getNumPassegers(){return m_passengers;}
    // setter for setting next station
    void setNext(Station * aNode){m_next=aNode;}
    // getter for next station
    Station * getNext(){return m_next;}
    // setter for previous station
    void setPrevious(Station * aNode){m_previous = aNode;}
    // getter for previous station
    Station * getPrevious(){return m_previous;}
    // setter for North
    void setNorth(Station * aNode){m_north = aNode;}
    // getter for North
    Station * getNorth(){return m_north;}
    // setter for South
    void setSouth(Station * aNode){m_south = aNode;}
    // getter for South
    Station * getSouth(){return m_south;}
    // setter for East
    void setEast(Station * aNode){m_east = aNode;}
    // getter for East
    Station * getEast(){return m_east;}
    // setter for West
    void setWest(Station * aNode){m_west = aNode;}
    // getter for West
    Station * getWest(){return m_west;}

    private:
    int m_code;//stores the station code number
    int m_passengers;// the number of passengers who board the train
    Station * m_next; // next station
    Station * m_previous; // previous station
    Station * m_north; // North station
    Station * m_south; // South station
    Station * m_east; // East station
    Station * m_west; // West station
};

class Railroad{
    public:
    friend class Grader;
    friend class Tester;
    Railroad();
    Railroad(const Railroad & rhs);// copy constructor
    ~Railroad();// delete all memory
    void dump();// print the list of stations
    const Railroad & operator=(const Railroad & rhs);// overloaded assignment operator
    bool extendAtHead(int newCode, int passengers);
    bool extendAtTail(int newCode, int passengers);
    bool makeRoute(list< pair<int,DIRECTION> > route);
    int travel(list< pair<int,DIRECTION> > route);
    bool removeStation(int aCode);// this removes a node from the list
    void clearAllRoutes();// this clears all routes, resets all direction pointers
    bool setNumPassengers(int code, int passengers);
    void clearNetwork();// delete all memory and reset all member variables
    void copyOverStationDirections(int storingArray[][3], int amountStations);

    Station* returnHead();
    Station* returnTail();
    int returnNumStations();

    private:
    int m_numStations;// number of stations in the network
    Station * m_head;
    Station * m_tail;

    // ***************************************************
    // Any private helper functions must be delared here!
    // ***************************************************
};
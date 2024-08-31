//UMBC - CSEE - CMSC 341 - Fall 2022 - Proj1
#include "railroad.h"
Railroad::Railroad(){
    // Initializes variables
    m_numStations = 0;
    m_head = nullptr;
    m_tail = nullptr;
}

Railroad::~Railroad(){
    clearNetwork();
}

void Railroad::clearNetwork(){
    // Create a pointer for the linked list
    Station * tempStation = nullptr;

    // If we have not reached the end of the linked list
    while (m_head != nullptr){
        // Point the pointer to the head of the linked list
        tempStation = m_head;
        // Make the next element the new head
        m_head = m_head->m_next;

        // If the node is pointing to any other stations, set it back to nullptr
        if(tempStation->getEast() != nullptr){
            tempStation->setEast(nullptr);
        }
        if(tempStation->getSouth() != nullptr){
            tempStation->setSouth(nullptr);
        }
        if(tempStation->getWest() != nullptr){
            tempStation->setWest(nullptr);
        }
        if(tempStation->getNorth() != nullptr){
            tempStation->setNorth(nullptr);
        }

        // Delete the old head
        delete tempStation;
    }

    // Resets the variables back to default
    m_head = nullptr;
    m_tail = nullptr;
    m_numStations = 0;
}

bool Railroad::extendAtHead(int newCode, int passengers){
    if(newCode < 0 || passengers < 0){
        return false;
    }

    // If there are currently no stations
    if (m_numStations == 0){
        // Creates a new station object
        Station * newStation = new Station;
        // Sets the code and amount of passengers
        newStation->setStationCode(newCode);
        newStation->setNumPassengers(passengers);
        // This station is the head and the tail of the linked list
        m_head = newStation;
        m_tail = newStation;
        m_numStations++;
        // Success
        return true;
    }
    // If there is at least one other station
    else{
        // Create a pointer to the head of the linked list
        Station *tempStation = m_head;
        // While we have yet to reach the end of the linked list
        while(tempStation != nullptr){
            // If the station code is already in the linked list, return false
            if(tempStation->getStationCode() == newCode){
                //cout << "This station code already exists. Will not add new station." << endl;
                // Failure
                return false;
            }
            // Moves to the next station
            tempStation = tempStation->getNext();
        }
        // Creates a new station object
        Station * newStation = new Station;
        // Sets the code and amount of passengers
        newStation->setStationCode(newCode);
        newStation->setNumPassengers(passengers);
        // Sets the new station's next node to be the old head
        newStation->m_next = m_head;
        // Sets the previous of the old head to be the new station
        m_head->m_previous = newStation;
        // Sets the new station to be the new head
        m_head = newStation;
        m_numStations++;
        // Success
        return true;
    }
}

bool Railroad::extendAtTail(int newCode, int passengers){
    if(newCode < 0 || passengers < 0){
        return false;
    }


    // If there are currently no stations
    if (m_numStations == 0){
        // Creates a new station object
        Station * newStation = new Station;
        // Sets the code and amount of passengers
        newStation->setStationCode(newCode);
        newStation->setNumPassengers(passengers);
        // This station is the head and the tail of the linked list
        m_head = newStation;
        m_tail = newStation;
        // Adds 1 more station
        m_numStations++;
        // Success
        return true;
    }
    // If there is at least one other station
    else{
        // Create a pointer to the head of the linked list
        Station *tempStation = m_head;
        // While we have yet to reach the end of the linked list
        while(tempStation != nullptr){
            // If the station code is already in the linked list, return false
            if(tempStation->getStationCode() == newCode){
                //cout << "This station code already exists. Will not add new station." << endl;
                // Failure
                return false;
            }
            // Moves to the next station
            tempStation = tempStation->getNext();
        }
        // Creates a new station object
        Station * newStation = new Station;
        // Sets the code and amount of passengers
        newStation->setStationCode(newCode);
        newStation->setNumPassengers(passengers);
        // Sets the next node of the old tail to be the new node
        m_tail->m_next = newStation;
        // Sets the previous node of the new node to be the old tail
        newStation->m_previous = m_tail;
        // The new tail is the new node
        m_tail = newStation;
        // Adds one more station
        m_numStations++;
        // Success
        return true;
    }
}

void Railroad::dump(){
    // If the linked list is not empty
    if (m_head != nullptr){
        // Declare an int for each direction's code
        int northCode, southCode, eastCode, westCode;
        // Pointer to head of the linked list
        Station *temp = m_head;
        // While not at the end of the linked list
        while(temp != nullptr){
            // If the pointer has a North, get the North code
            if (temp->m_north != nullptr) northCode = temp->m_north->m_code;
            // If the pointer does not have a North
            else northCode = -1;
            // If the pointer has a South, get the South code
            if (temp->m_south != nullptr) southCode = temp->m_south->m_code;
            // If the pointer does not have a South
            else southCode = -1;
            // If the pointer has a East, get the East code
            if (temp->m_east != nullptr) eastCode = temp->m_east->m_code;
            // If the pointer does not have an East
            else eastCode = -1;
            // If the pointer has a West, get the West code
            if (temp->m_west != nullptr) westCode = temp->m_west->m_code;
            // If the pointer does not have a West
            else westCode = -1;
            // Prints the code of the current node
            cout << temp->m_code << 
                    " (" << 
                    // Prints the amount of passengers of the current node
                    "P: " << temp->m_passengers << 
                    // Prints the North code
                    ", N: " << northCode <<
                    // Prints the South code
                    ", S: " << southCode <<
                    // Prints the East Code
                    ", E: " << eastCode <<
                    // Prints the West code
                    ", W: " << westCode <<
                    ")" << endl;
            // Moves to the next node
            temp = temp->m_next;
        }
    }
}

bool Railroad::makeRoute(list< pair<int,DIRECTION> > route){
     // Declares and intializes some int variables
    int currStationPointTo = -1;
    int currStation = -1;
    int currStationDirection = -1;

    // Fixes super specific case, best to explain with example:
    // aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
    // aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
    // aRoute.push_back(pair<int,DIRECTION>(8,NONE));
    // aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
    // aRoute.push_back(pair<int,DIRECTION>(6,NONE));

    // Station 2 points North to 5 and then points North to 6
    // This would be illegal, thus the route should never be created

    int amountOfThePairs = 0;

    // Getting the amount of pairs for the 2-D array
    for(list<pair<int,DIRECTION>>::iterator it = route.begin(); it != route.end(); ++it){
        amountOfThePairs++;
    }

    int counter67 = 0;

    // Storing all of the stations to see if one station points in the same direction to 2 other stations
    int Awesomearray[amountOfThePairs-1][3];
    
    for(list<pair<int,DIRECTION>>::iterator it = route.begin(); it != route.end(); ++it){

        // We are using this counter to skip the first pair as we don't yet know where the station is pointing to
        if(counter67 > 0){
            currStationPointTo = it->first;
            it--;
            currStation = it->first;
            currStationDirection = it->second;

            // If the station points to itself
            if(currStation == currStationPointTo){
                //cout << "station can't point to itself" << endl;
                return false;
            }

            // Stores all the parts of the route into array
            Awesomearray[counter67-1][0] = currStation;
            Awesomearray[counter67-1][1] = currStationDirection;
            Awesomearray[counter67-1][2] = currStationPointTo;

        counter67++;
        it++;
        }else{
            counter67++;
        }
    }

    // Loops through making sure station is pointing in same direction to two other stations
    for(int i = 0; i < amountOfThePairs-1; i++){
        for(int j = 0; j < amountOfThePairs-1; j++){
            // Not comparing the same pair to itself
            if(j != i){
                // Station pointing in same direction to 2 other stations
                if(Awesomearray[i][0] == Awesomearray[j][0] && Awesomearray[i][1] == Awesomearray[j][1]){
                    //cout << "Station pointing in the same direction to 2 different stations" << endl;
                    return false;
                }
            }
            // Station pointing to NONE when not last pair in the route
            if(Awesomearray[i][1] == 4){
                //cout << "Station pointing to NONE without being the last pair in the route" << endl;
                return false;
            }
        }
    }

    int counter68 = 0;

    // With this loop we are looking to see if any of the nodes are already pointing at a station
    // If any node is already pointing at another station in the given direction, the route is invalid
    for(list<pair<int,DIRECTION>>::iterator it = route.begin(); it != route.end(); ++it){
        // We are using this counter to skip the first pair as we don't yet know where the station is pointing to
        if(counter68 > 0){
            currStationPointTo = it->first;
            it--;
            currStation = it->first;
            currStationDirection = it->second;

            // Fixes super specific case, best to explain with example:
            // aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
            // aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
            // aRoute.push_back(pair<int,DIRECTION>(8,NONE));
            // aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
            // aRoute.push_back(pair<int,DIRECTION>(6,NONE));

            // Station 2 points North to 5 and then points North to 6
            // This would be illegal, thus the route should never be created
           // int awesomeArray[];

            // Create a pointer to the head of the linked list
            Station *tempStation = m_head;

            // Looping through the linked list
            while(tempStation != nullptr){
                // If the station exists
                if(tempStation->getStationCode() == currStation){
                    // If station direction is North
                    if(currStationDirection == 0){
                        // If station is already pointing North to another station
                        if(tempStation->getNorth() != nullptr){
                            //cout << "Station " << tempStation->getStationCode() << " already points North to another station" << endl;
                            // Failure
                            return false;
                        }
                    // If station direction is South
                    }else if(currStationDirection == 1){
                        // If station is already pointing South to another station
                        if(tempStation->getSouth() != nullptr){
                            //cout << "Station " << tempStation->getStationCode() << " already points South to another station" << endl;
                            // Failure
                            return false;
                        }
                    // If station direction is East
                    }else if(currStationDirection == 2){
                        // If station is already pointing East to another station
                        if(tempStation->getEast() != nullptr){
                            //cout << "Station " << tempStation->getStationCode() << " already points East to another station" << endl;
                            // Failure
                            return false;
                        }
                    // If station direction is West
                    }else if(currStationDirection == 3){
                        // If station is already pointing West to another station
                        if(tempStation->getWest() != nullptr){
                            //cout << "Station " << tempStation->getStationCode() << " already points West to another station" << endl;
                            // Failure
                            return false;
                        }
                    }
                }

                // Moves to next node
                tempStation = tempStation->getNext();
            }

            it++;
        }

        counter68++;
    }
    // Declares and intializes 2 counter variables
    // Use for seeing if the first node of the route is in the linked list
    int counter = 0;
    // Will be set to 1 if the first node in the route actually is in the linked list
    int counter2 = 0;

    for(list<pair<int,DIRECTION>>::iterator it = route.begin(); it != route.end(); ++it){
        //cout << "Pair: " << it->first << ":" << it->second << endl;
        // Checking to make sure the first node of the route exists in the linked list
        if(counter == 0){
            // Stores the code of the first station
            int currStationCode = it->first;
            // Create a pointer to the head of the linked list
            Station *tempStation = m_head;
            // While we have yet to reach the end of the linked list
            while(tempStation != nullptr){
                // The first node of the route exists in the linked list
                if(tempStation->getStationCode() == currStationCode){
                   // Sets the counter2 to 1. 
                   // When the while loop is over, counter2 being set to 1 will bypass the return false
                   counter2++; 
                }
                // Moves to the next station
                tempStation = tempStation->getNext();
            }
            // The first node of the route does not exist in the linked list
            if(counter2 == 0){
                //cout << "The first node of the route does not exist in the linked list!" << endl;
                // Failure
                return false;
            }
            // Increment counter
            // No longer on first node of the route
            counter++;
        // No longer on first node
        }else{
            // This is the station being pointed to
            currStationPointTo = it->first;
            // Goes back one pair
            it--;
            // This is the station that is pointing
            currStation = it->first;
            // This is the direction
            currStationDirection = it->second;

            // Used for keeping track of whether or not the station that is pointing exists
            int counter4 = 0;

            // Create a pointer to the head of the linked list
            Station *tempStation = m_head;
            // While we have yet to reach the end of the linked list
            while(tempStation != nullptr){
                // If we find the station we are looking for (pointing)
                if(tempStation->getStationCode() == currStation){
                    // The station pointing exists
                    counter4++;
                    // Used for keeping track of whether the station being pointed to does exist
                    int counter3 = 0;
                    // Create another pointer to the head of the linked list again
                    Station *tempStation2 = m_head;
                    // While we have yet to reach the end of the linked list
                    while(tempStation2 != nullptr){
                        // If we find the station we are looking for (pointed to)
                        if(tempStation2->getStationCode() == currStationPointTo){
                            // Sets the pointer based off of direction
                            if(currStationDirection == 0){
                                tempStation->setNorth(tempStation2);
                                
                            }else if(currStationDirection == 1){
                                tempStation->setSouth(tempStation2);
                            }else if(currStationDirection == 2){
                                tempStation->setEast(tempStation2);
                            }else if(currStationDirection == 3){
                                tempStation->setWest(tempStation2);
                            }
                            // The station being pointed to does exist
                            counter3++;
                        }
                        // Moves to the next station
                        tempStation2 = tempStation2->getNext();
                    }
                    // If the station being pointed to does not exist
                    if(counter3 == 0){
                        // Creates a new station at the tail
                        extendAtTail(currStationPointTo, 10);
                        // Sets the pointer based off of direction
                        if(currStationDirection == 0){
                            tempStation->setNorth(m_tail);
                        }else if(currStationDirection == 1){
                            tempStation->setSouth(m_tail);
                        }else if(currStationDirection == 2){
                            tempStation->setEast(m_tail);
                        }else if(currStationDirection == 3){
                            tempStation->setWest(m_tail);
                        }
                    }

                }
                // Moves to the next station
                tempStation = tempStation->getNext();
            }
            // If the station pointing does not exist
            if(counter4 == 0){
               // Creates a new station at the tail
                extendAtTail(currStation, 10);

                // Create another pointer to the head of the linked list
                Station *tempStation = m_head;

                // For keeping track if the station being pointed to exists
                int counter5 = 0;
                
                // Loops through the linked list
                while(tempStation != nullptr){
                    // If we found the station being pointed to
                    if(tempStation->getStationCode() == currStationPointTo){
                        // Sets the pointer based off of direction
                        if(currStationDirection == 0){
                            m_tail->setNorth(tempStation);
                        }else if(currStationDirection == 1){
                            m_tail->setSouth(tempStation);
                        }else if(currStationDirection == 2){
                            m_tail->setEast(tempStation);
                        }else if(currStationDirection == 3){
                            m_tail->setWest(tempStation);
                        }
                        // The station being pointed to exists
                        counter5++;
                    }
                    // Traverses
                    tempStation = tempStation->getNext();
                }
                // The station being pointed to does not exist
                if(counter5 == 0){
                  // Creates a new station at the head
                extendAtHead(currStationPointTo, 10);  

                // Sets the pointer based off of direction
                if(currStationDirection == 0){
                    m_tail->setNorth(m_head);
                }else if(currStationDirection == 1){
                    m_tail->setSouth(m_head);
                }else if(currStationDirection == 2){
                    m_tail->setEast(m_head);
                }else if(currStationDirection == 3){
                    m_tail->setWest(m_head);
                }

                }
                } 
                // Goes forward one pair to stop infinite loop
                it++;
            }
        }
        // Success
        return true;
    }

int Railroad::travel(list< pair<int,DIRECTION> > route){
    // Declares and intializes some int variables
    int currStationPointTo = -1;
    int currStation = -1;
    int currStationDirection = -1;

    int amountPassengers = 0;

    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;

    int amountOfPairs = 0;
    int currentPair = 1;

    // Going to loop through and count the amount of pairs
    // Using this because when we approach the last stop on the route, we aren't including the...
    // ...passengers from the last stop
    for(list<pair<int,DIRECTION>>::iterator it = route.begin(); it != route.end(); ++it){
        amountOfPairs++;
    }

    // Loops through the route
    for(list<pair<int,DIRECTION>>::iterator it = route.begin(); it != route.end(); ++it){
        //cout << "Pair: " << it->first << ":" << it->second << endl;
        // For the first pair, nothing is being pointed to
        // Just making sure the first station exists
        if(counter == 0){
            // Stores the first station
            currStation = it->first;

            // Creates a pointer to the head of the linked list
            Station *tempStation = m_head;

            // While we have yet to reach the end of the linked list
            while(tempStation != nullptr){
                // The station exists
                if(tempStation->getStationCode() == currStation){
                    // Increment the counter2
                    counter2++;
                }
                // Traverses the linked list
                tempStation = tempStation->m_next;
            }
            // The first station does not exist
            if(counter2 == 0){
                //cout << "First station is missing" << endl;
                // Failure
                return -1;
            }
            // No longer on the first pair
            counter++;

        // Not on the first pair
        }else{
            currentPair++;
            currStationPointTo = it->first;

            it--;

            currStation = it->first;
            currStationDirection = it->second;

            // Creates a pointer to the head of the linked list
            Station *tempStation = m_head;


            //Running this while loop to make sure both stations exist:

            // While we have yet to reach the end of the linked list
            while(tempStation != nullptr){
                // The station exists
                if(tempStation->getStationCode() == currStation){
                    //cout << "currStation: " << currStation << endl;
                    // Increment the counter2
                    counter3++;
                }
                if(tempStation->getStationCode() == currStationPointTo){
                    //cout << "currStationPointTo: " << currStationPointTo << endl;
                    counter3++;
                }
                // Traverses the linked list
                tempStation = tempStation->m_next;
            }

            //cout << "counter3: " << counter3 << endl;
            // One or both of the stations does not exit
            if(counter3 < 2){
                //cout << "Missing station" << endl;
                // Failure
                return -1;
            }


            // Creates a pointer to the head of the linked list
            Station *tempStation2 = m_head;

            // Use for storing the current station
            Station *tempStation3 = m_head;

            // While we have yet to reach the end of the linked list
            while(tempStation2 != nullptr){
                // We found the station
                if(tempStation2->getStationCode() == currStation){
                    tempStation3 = tempStation2;
                }
                tempStation2 = tempStation2->m_next;
            }


            // Creates a pointer to the head of the linked list
            Station *tempStation4 = m_head;

            // Use for storing the pointed to station
            Station *tempStation5 = m_head;

            // While we have yet to reach the end of the linked list
            while(tempStation4 != nullptr){
                // We found the station
                if(tempStation4->getStationCode() == currStationPointTo){
                    tempStation5 = tempStation4;
                }
                tempStation4 = tempStation4->m_next;
            }


            // North
            if(currStationDirection == 0){
                // If the station actually does point North to the other station
                if(tempStation3->getNorth() == tempStation5){
                    amountPassengers = amountPassengers + tempStation3->getNumPassegers();
                }else{
                    //cout << "Station " << tempStation3->getStationCode() << " does not point North to " << tempStation5->getStationCode() << endl;
                    return -1;
                }
            // South
            }else if(currStationDirection == 1){
                // If the station actually does point South to the other station
                if(tempStation3->getSouth() == tempStation5){
                    amountPassengers = amountPassengers + tempStation3->getNumPassegers();
                }else{
                    //cout << "Station " << tempStation3->getStationCode() << " does not point South to " << tempStation5->getStationCode() << endl;
                    return -1;
                }
            // East
            }else if(currStationDirection == 2){
                // If the station actually does point East to the other station
                if(tempStation3->getEast() == tempStation5){
                    amountPassengers = amountPassengers + tempStation3->getNumPassegers();
                }else{
                    //cout << "Station " << tempStation3->getStationCode() << " does not point East to " << tempStation5->getStationCode() << endl;
                    return -1;
                }
            // West
            }else if(currStationDirection == 3){
                // If the station actually does point West to the other station
                if(tempStation3->getWest() == tempStation5){
                    amountPassengers = amountPassengers + tempStation3->getNumPassegers();
                }else{
                    //cout << "Station " << tempStation3->getStationCode() << " does not point West to " << tempStation5->getStationCode() << endl;
                    return -1;
                }
            }
            // On the last stop
            if(currentPair == amountOfPairs){
                // Getting the passengers from the last stop
                amountPassengers = amountPassengers + tempStation5->getNumPassegers();
            }

            it++;
            // Reset back to 0
            counter3 = 0;
        }
    }
    // Returns the amount of passengers from the trip
    return amountPassengers;
}

bool Railroad::setNumPassengers(int code, int passengers){
    // If there are currently no stations
    if (m_numStations == 0){
        //cout << "There are no stations" << endl;
        // Failure
        return false;
    }
    // If there is at least one other station
    else{
        // Create a pointer to the head of the linked list
        Station *tempStation = m_head;
        // While we have yet to reach the end of the linked list
        while(tempStation != nullptr){
            // If we have found the station we are looking for
            if(tempStation->getStationCode() == code){
                // Change the amount of passengers
                tempStation->setNumPassengers(passengers);
                // Success
                return true;
            }
            // Moves to the next station
            tempStation = tempStation->getNext();
        }
        // The code does not exist
        //cout << "That code does not exist" << endl;
        // Failure
        return false;
    }
}

bool Railroad::removeStation(int aCode){

    int counter = 0;

    // If the linked list is empty
    if(m_head == nullptr){
        //cout << "The linked list is empty" << endl;
        return false;
    // If only 1 station left
    }else if(m_numStations == 1){
        // Deletes the node
        delete m_head;
        // Blanks the linked list
        m_head = nullptr;
        m_tail = nullptr;
        m_numStations = 0;
        // Did what we wanted
        return true;
    }
    // If more than 1 station
    else{

// Pointer to the head of the linked list
    Station *tempStation45 = m_head;

    // Loops through, making sure none of the other nodes still pointing to the deleted node
    while(tempStation45 != nullptr){

        // If the North direction isn't nullptr
        if(tempStation45->getNorth() != nullptr){
            // If the North direction matches the station number that was removed
           if(tempStation45->getNorth()->getStationCode() == aCode){
            // Sets the North direction to nullptr
            //cout << "STATION NUMBER: " << tempStation45->getStationCode() << endl;
            tempStation45->setNorth(nullptr);
            } 
        }

        if(tempStation45->getSouth() != nullptr){
           if(tempStation45->getSouth()->getStationCode() == aCode){
            tempStation45->setSouth(nullptr);
            } 
        }

        if(tempStation45->getEast() != nullptr){
           if(tempStation45->getEast()->getStationCode() == aCode){
            tempStation45->setEast(nullptr);
            } 
        }

        if(tempStation45->getWest() != nullptr){
           if(tempStation45->getWest()->getStationCode() == aCode){
            tempStation45->setWest(nullptr);
            } 
        }

        // Traverses
        tempStation45 = tempStation45->m_next;
    }
        // If we want to remove from the head of the linked list
        if(m_head->getStationCode() == aCode){
            // Sets a pointer to the head node
            Station *tempStation = m_head;
            // Sets the head to be the next node in the linked list
            m_head = m_head->getNext();
            // Deletes the head node
            delete tempStation;
            // The node previous to the new head is nullptr
            m_head->setPrevious(nullptr);
            m_numStations--;
        // If we want to remove from the tail of the linked list
        }else if(m_tail->getStationCode() == aCode){
            // Pointer to the tail of the linked list
            Station *tempStation = m_tail;
            // A second pointer to one before the tail of the linked list
            Station *tempStation2 = tempStation->getPrevious();

            // Sets the next of the node one before the tail to nullptr
            tempStation2->setNext(nullptr);

            // Deletes the tail of the linked list
            delete tempStation;

            // The new tail
            m_tail = tempStation2;
            m_numStations--;
        // If we want to remove a node that is neither the head or the tail
        }else{
           // Pointer to the head of the linked list
            Station *tempStation = m_head;
            // A second pointer set to nullptr
            Station *tempStation2 = nullptr;

            // While we have yet to reach the end of the linked list
            while(tempStation != nullptr){
                // If we found the station we are looking for
                if(tempStation->getStationCode() == aCode){
                    // Get the node previous to the node that will be deleted
                    tempStation2 = tempStation->m_previous;
                    // Get the node after the node that will be deleted
                    tempStation2->m_next = tempStation->m_next;
                    // Confusion
                    tempStation->m_next->m_previous = tempStation2;
                    delete tempStation;
                    counter++;
                }
                // Traverses
                tempStation = tempStation->m_next;

            }
            // If the station does not exist
            if(counter == 0){
                //cout << "That station does not exist" << endl;
                return false;
            }
        }
    // Good stuff happened 
    return true;
    }
}

void Railroad::clearAllRoutes(){
    // If the linked list is empty
    if(m_head == nullptr){
        //cout << "There are no stations!" << endl;
    // If the linked list is not empty
    }else{
        // Creates a pointer to the head of the linked list
        Station *tempStation = m_head;

        // While we have yet to reach the end of the linked list
        while(tempStation != nullptr){
            // For each direction, if it is not nullptr, set it to nullptr
            if(tempStation->getNorth() != nullptr){
                tempStation->setNorth(nullptr);
            }
            if(tempStation->getSouth() != nullptr){
                tempStation->setSouth(nullptr);
            }
            if(tempStation->getEast() != nullptr){
                tempStation->setEast(nullptr);
            }
            if(tempStation->getWest() != nullptr){
                tempStation->setWest(nullptr);
            }
            // Traverses
            tempStation = tempStation->m_next;
        }
    }
}

const Railroad & Railroad::operator=(const Railroad & rhs){
    //cout << "OVERLOAD" << endl;
    // We are looking to make sure that the memory address of other is not equal to the memory address...
   // ... of the thing we are working on.
   if(this != &rhs){
    // Empty old linked list
    clearNetwork();

    // Array for storing all the station direction pointers
    int storingArray[500][3];
    // For storing the current index in storingArray
    int counter = 0;

    // Storing -1 into the entire array
    for(int i = 0; i < 500; i++){
        storingArray[i][0] = -1;
        storingArray[i][1] = -1;
        storingArray[i][2] = -1;
    }

    // Sets the head of the linked list to be nullptr
   m_head = nullptr;
   m_tail = nullptr;
   m_numStations = 0;


   // Creates a node for traversing. Sets it equal to the head of the linked list
   Station *tempStation = rhs.m_head;

   // While we have yet to reach the end of the linked list
   while(tempStation != nullptr){
      // Add the data from the other linked list
      extendAtTail(tempStation->getStationCode(), tempStation->getNumPassegers());
      // Move pointer 1 index

      // If the station at North is pointing to another station
      if(tempStation->getNorth()!= nullptr){
        // Store the station
        storingArray[counter][0] = tempStation->getStationCode();
        // Store the direction
        storingArray[counter][1] = 0;
        // Store the staion pointing to
        storingArray[counter][2] = tempStation->getNorth()->getStationCode();

        // Increment counter 
        counter++;
      }

      // If the station at South is pointing to another station
      if(tempStation->getSouth()!= nullptr){
        // Store the station
        storingArray[counter][0] = tempStation->getStationCode();
        // Store the direction
        storingArray[counter][1] = 1;
        // Store the staion pointing to
        storingArray[counter][2] = tempStation->getSouth()->getStationCode();

        // Increment counter 
        counter++;
      }

      // If the station at East is pointing to another station
      if(tempStation->getEast()!= nullptr){
        // Store the station
        storingArray[counter][0] = tempStation->getStationCode();
        // Store the direction
        storingArray[counter][1] = 2;
        // Store the staion pointing to
        storingArray[counter][2] = tempStation->getEast()->getStationCode();

        // Increment counter 
        counter++;
      }

      // If the station at West is pointing to another station
      if(tempStation->getWest()!= nullptr){
        // Store the station
        storingArray[counter][0] = tempStation->getStationCode();
        // Store the direction
        storingArray[counter][1] = 3;
        // Store the staion pointing to
        storingArray[counter][2] = tempStation->getWest()->getStationCode();

        // Increment counter 
        counter++;
      }
      tempStation = tempStation->m_next;

    }

   // for(int i = 0; i < 500; i++){
     //   if(storingArray[i][0] != -1){
       //     cout << i << ". " << storingArray[i][0] << " " << storingArray[i][1] << " " << storingArray[i][2] << endl;
     //   }
   // }

    copyOverStationDirections(storingArray, counter);

    //m_head = rhs.m_head;
    //m_tail = rhs.m_tail;
    m_numStations = rhs.m_numStations;


   }
   return *this;
}

Railroad::Railroad(const Railroad & rhs){
    //cout << "COPY CONSTRUCTOR" << endl;

    // Array for storing all the station direction pointers
    int storingArray[500][3];
    // For storing the current index in storingArray
    int counter = 0;

    // Storing -1 into the entire array
    for(int i = 0; i < 500; i++){
        storingArray[i][0] = -1;
        storingArray[i][1] = -1;
        storingArray[i][2] = -1;
    }

    // Sets the head of the linked list to be nullptr
   m_head = nullptr;
   m_tail = nullptr;
   m_numStations = 0;


   // Creates a node for traversing. Sets it equal to the head of the linked list
   Station *tempStation = rhs.m_head;

   // While we have yet to reach the end of the linked list
   while(tempStation != nullptr){
      // Add the data from the other linked list
      extendAtTail(tempStation->getStationCode(), tempStation->getNumPassegers());
      // Move pointer 1 index

      // If the station at North is pointing to another station
      if(tempStation->getNorth()!= nullptr){
        // Store the station
        storingArray[counter][0] = tempStation->getStationCode();
        // Store the direction
        storingArray[counter][1] = 0;
        // Store the staion pointing to
        storingArray[counter][2] = tempStation->getNorth()->getStationCode();

        // Increment counter 
        counter++;
      }

      // If the station at South is pointing to another station
      if(tempStation->getSouth()!= nullptr){
        // Store the station
        storingArray[counter][0] = tempStation->getStationCode();
        // Store the direction
        storingArray[counter][1] = 1;
        // Store the staion pointing to
        storingArray[counter][2] = tempStation->getSouth()->getStationCode();

        // Increment counter 
        counter++;
      }

      // If the station at East is pointing to another station
      if(tempStation->getEast()!= nullptr){
        // Store the station
        storingArray[counter][0] = tempStation->getStationCode();
        // Store the direction
        storingArray[counter][1] = 2;
        // Store the staion pointing to
        storingArray[counter][2] = tempStation->getEast()->getStationCode();

        // Increment counter 
        counter++;
      }

      // If the station at West is pointing to another station
      if(tempStation->getWest()!= nullptr){
        // Store the station
        storingArray[counter][0] = tempStation->getStationCode();
        // Store the direction
        storingArray[counter][1] = 3;
        // Store the staion pointing to
        storingArray[counter][2] = tempStation->getWest()->getStationCode();

        // Increment counter 
        counter++;
      }
      tempStation = tempStation->m_next;

    }

   // for(int i = 0; i < 500; i++){
     //   if(storingArray[i][0] != -1){
       //     cout << i << ". " << storingArray[i][0] << " " << storingArray[i][1] << " " << storingArray[i][2] << endl;
     //   }
   // }

    copyOverStationDirections(storingArray, counter);

    //m_head = rhs.m_head;
    //m_tail = rhs.m_tail;
    m_numStations = rhs.m_numStations;

}

Station* Railroad::returnHead(){
    return m_head;
}

Station* Railroad::returnTail(){
    return m_tail;
}

int Railroad::returnNumStations(){
    return m_numStations;
}

void Railroad::copyOverStationDirections(int storingArray[][3], int amountStations){
    for(int i = 0; i < amountStations; i++){
        //cout << i << ". " << storingArray[i][0] << " " << storingArray[i][1] << " " << storingArray[i][2] << endl;
    }

    Station *tempStation = m_head;

    // Loops through
    while(tempStation != nullptr){
        // Loops through array
        for(int i = 0; i < amountStations; i++){
            //cout << i << endl;
            //cout << "Station Code: " << tempStation->getStationCode() << endl;
            // If the current station is pointing to another station
            if(tempStation->getStationCode() == storingArray[i][0]){
                // If the current station is pointing North
                if(storingArray[i][1] == 0){

                    // Pointer to the head of the linked list again
                    Station *tempStation2 = m_head;

                    // Loops through
                    while(tempStation2 != nullptr){
                        // If we find the station the first station is pointing to
                        if(tempStation2->getStationCode() == storingArray[i][2]){
                            // Points the station North to the second station
                            tempStation->setNorth(tempStation2);
                        }
                        // Traverses
                        tempStation2 = tempStation2->getNext();
                    }
                }

                // If the current station is pointing South
                if(storingArray[i][1] == 1){

                    // Pointer to the head of the linked list again
                    Station *tempStation2 = m_head;

                    // Loops through
                    while(tempStation2 != nullptr){
                        // If we find the station the first station is pointing to
                        if(tempStation2->getStationCode() == storingArray[i][2]){
                            // Points the station South to the second station
                            tempStation->setSouth(tempStation2);
                        }
                        // Traverses
                        tempStation2 = tempStation2->getNext();
                    }
                }

                // If the current station is pointing East
                if(storingArray[i][1] == 2){

                    // Pointer to the head of the linked list again
                    Station *tempStation2 = m_head;

                    // Loops through
                    while(tempStation2 != nullptr){
                        // If we find the station the first station is pointing to
                        if(tempStation2->getStationCode() == storingArray[i][2]){
                            // Points the station East to the second station
                            tempStation->setEast(tempStation2);
                        }
                        // Traverses
                        tempStation2 = tempStation2->getNext();
                    }
                }

                // If the current station is pointing West
                if(storingArray[i][1] == 3){

                    // Pointer to the head of the linked list again
                    Station *tempStation2 = m_head;

                    // Loops through
                    while(tempStation2 != nullptr){
                        // If we find the station the first station is pointing to
                        if(tempStation2->getStationCode() == storingArray[i][2]){
                            // Points the station West to the second station
                            tempStation->setWest(tempStation2);
                        }
                        // Traverses
                        tempStation2 = tempStation2->getNext();
                    }
                }
            }  
        }
        // Traverses to next node
        tempStation = tempStation->getNext();
    }
}
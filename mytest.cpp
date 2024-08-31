// UMBC - CMSC 341 - Fall 2022 - Proj1
#include "railroad.h"
//#include "railroad.cpp"

class Tester{
    public:
    

    /******************************************
    * Test function declarations go here! *
    ******************************************/
    bool extendAtHeadNormalCase(Railroad &myRailroad);
    bool extendAtHeadOneNode(Railroad &myRailroad);
    // Station number less than 0
    bool extendAtHeadErrorCaseOne(Railroad &myRailroad);
    // Station number already used
    bool extendAtHeadErrorCaseTwo(Railroad &myRailroad);
    // Passengers less than 0
    bool extendAtHeadErrorCaseThree(Railroad &myRailroad);

    bool extendAtTailNormalCase(Railroad &myRailroad);
    bool extendAtTailOneNode(Railroad &myRailroad);
    // Station number less than 0
    bool extendAtTailErrorCaseOne(Railroad &myRailroad);
    // Station number already used
    bool extendAtTailErrorCaseTwo(Railroad &myRailroad);
    // Passengers less than 0
    bool extendAtTailErrorCaseThree(Railroad &myRailroad);

    bool removeAllStations(Railroad &myRailroad);
    // Station does not exist
    bool removeStationErrorCaseOne(Railroad &myRailroad);
    bool removeStationAllLinksRemoved(Railroad &myRailroad);

    // The first node in the route does not exist
    bool makeRouteErrorCaseOne(Railroad &myRailroad);
    // There is a NONE that is not the last pair in the route
    bool makeRouteErrorCaseTwo(Railroad &myRailroad);
    // The same station is pointing in the same direction to 2 different stations
    bool makeRouteErrorCaseThree(Railroad &myRailroad);
    // Adding to the route a station that already is pointing to a different station in that direction already
    bool makeRouteErrorCaseFour(Railroad &myRailroad);
    // Station not allowed to point to itself
    bool makeRouteErrorCaseFive(Railroad &myRailroad);
    bool makeRouteNormalCase(Railroad &myRailroad);
    // Adding a station that is not first and does not exist
    bool makeRouteEdgeCase(Railroad &myRailroad);

    bool travelNormalCase(Railroad &myRailroad);
    // The first station does not exist
    bool travelErrorCaseOne(Railroad &myRailroad);
    // A different station does not exist
    bool travelErrorCaseTwo(Railroad &myRailroad);
    // A station does not actually point to a different station
    bool travelErrorCaseThree(Railroad &myRailroad);

    bool copyConstructorNormalCase(Railroad &myRailroad, Railroad &myRailroad2);
    // Railroad with one station
    bool copyConstructorEdgeCaseOne(Railroad &myRailroad, Railroad &myRailroad2);
    // Railroad with two stations
    bool copyConstructorEdgeCaseTwo(Railroad &myRailroad, Railroad &myRailroad2);

    bool overloadedOperatorNormalCase(Railroad &myRailroad, Railroad &myRailroad2);
    // Railroad with one station
    bool overloadedOperatorEdgeCaseOne(Railroad &myRailroad, Railroad &myRailroad2);
    // Railroad with two stations
    bool overloadedOperatorEdgeCaseTwo(Railroad &myRailroad, Railroad &myRailroad2);
};

int main () {
    
    Tester tester;

    {
        Railroad myRailroad;
        cout << "\nTesting the normal case of extend at head:\n\n";
        if (tester.extendAtHeadNormalCase(myRailroad) == true)
            cout << "\tNormal case of extend at head passed!\n";
        else
            cout << "\tNormal case of extend at head failed!\n";
    }

    {
        Railroad myRailroad;
        cout << "\nTesting the case of inserting one node into the linked list at the head:\n\n";
        if (tester.extendAtHeadOneNode(myRailroad) == true)
            cout << "\tInserting one node at head passed!\n";
        else
            cout << "\tInserting one node at head failed!\n";
    }

    {
        Railroad myRailroad;
        cout << "\nTesting the case of inserting a negative station number at the head:\n\n";
        if (tester.extendAtHeadErrorCaseOne(myRailroad) == true)
            cout << "\tInserting a negative station number at the head passed!\n";
        else
            cout << "\tInserting a negative station number at the head failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting the case of inserting a station number that is already used at the head:\n\n";
        if (tester.extendAtHeadErrorCaseTwo(myRailroad) == true)
            cout << "\tInserting a used station number at the head passed!\n";
        else
            cout << "\tInserting a used station number at the head failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting the case of inserting a negative amount of passengers at the head:\n\n";
        if (tester.extendAtHeadErrorCaseThree(myRailroad) == true)
            cout << "\tInserting a negative passenger number at the head passed!\n";
        else
            cout << "\tInserting a negative passenger number at the head failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting the normal case of extend at tail:\n\n";
        if (tester.extendAtTailNormalCase(myRailroad) == true)
            cout << "\tNormal case of extend at tail passed!\n";
        else
            cout << "\tNormal case of extend at tail failed!\n";
    }


    {
        Railroad myRailroad;
        cout << "\nTesting the case of inserting one node into the linked list at the tail:\n\n";
        if (tester.extendAtTailOneNode(myRailroad) == true)
            cout << "\tInserting one node into the linked list at the tail passed!\n";
        else
            cout << "\tInserting one node into the linked list at the tail failed!\n";
    }

    {
        Railroad myRailroad;
        cout << "\nTesting the case of inserting a negative station number at the tail:\n\n";
        if (tester.extendAtTailErrorCaseOne(myRailroad) == true)
            cout << "\tInserting a negative station number at the tail passed!\n";
        else
            cout << "\tInserting a negative station number at the tail failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting the case of inserting a station number that is already used at the tail:\n\n";
        if (tester.extendAtTailErrorCaseTwo(myRailroad) == true)
            cout << "\tInserting a used station number at the tail passed!\n";
        else
            cout << "\tInserting a used station number at the tail failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting the case of inserting a negative amount of passengers at the tail:\n\n";
        if (tester.extendAtTailErrorCaseThree(myRailroad) == true)
            cout << "\tInserting a negative passenger number at the tail passed!\n";
        else
            cout << "\tInserting a negative passenger number at the tail failed!\n";  
    }


  {
        Railroad myRailroad;
        cout << "\nTesting the case of removing all stations:\n\n";
        if (tester.removeAllStations(myRailroad) == true)
            cout << "\tRemoving all stations has passed!\n";
        else
            cout << "\tRemoving all stations has failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting the case of removing a station that does not exist:\n\n";
        if (tester.removeStationErrorCaseOne(myRailroad) == true)
            cout << "\tRemoving station that does not exist passed!\n";
        else
            cout << "\tRemoving station that does not exist failed!\n";  
    }

    
    {
        Railroad myRailroad;
        cout << "\nTesting the case of removing all links to the removed station:\n\n";
        if (tester.removeStationAllLinksRemoved(myRailroad) == true)
            cout << "\tRemoving all links to removed station passed!\n";
        else
            cout << "\tRemoving all links to removed station failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting building a route with the head of the route not being a station:\n\n";
        if (tester.makeRouteErrorCaseOne(myRailroad) == true)
            cout << "\tNot building a route with the head of the route not being a station passed!\n";
        else
            cout << "\tNot building a route with the head of the route not being a station failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting building a route with a station that is not the last station pointing to NONE:\n\n";
        if (tester.makeRouteErrorCaseTwo(myRailroad) == true)
            cout << "\tNot building a route with a station that is not the last station pointing to NONE passed!\n";
        else
            cout << "\tNot building a route with a station that is not the last station pointing to NONE failed\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting building a route with a station that that points in the same direction to 2 different stations:\n\n";
        if (tester.makeRouteErrorCaseThree(myRailroad) == true)
            cout << "\tNot building a route with a station that points in the same direction to 2 other stations passed!\n";
        else
            cout << "\tNot building a route with a station that points in the same direction to 2 other stations failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting adding to the route a station that is already pointing in a direction to a different station:\n\n";
        if (tester.makeRouteErrorCaseFour(myRailroad) == true)
            cout << "\tNot adding to the route a station that is already pointing in a direction to a different station passed!\n";
        else
            cout << "\tNot adding to the route a station that is already pointing in a direction to a different station failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting adding to the route a station that points to itself:\n\n";
        if (tester.makeRouteErrorCaseFive(myRailroad) == true)
            cout << "\tNot building a route with a station that points to itself passed!\n";
        else
            cout << "\tNot building a route with a station that points to itself failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting normal case of creating a route:\n\n";
        if (tester.makeRouteNormalCase(myRailroad) == true)
            cout << "\tBuilding a normal route passed!\n";
        else
            cout << "\tBuilding a normal route failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting edge case of creating a route:\n\n";
        if (tester.makeRouteEdgeCase(myRailroad) == true)
            cout << "\tBuilding a route with a station that does not exist (not first station) passed!\n";
        else
            cout << "\tBuilding a route with a station that does not exist (not first station) failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting the normal case of traveling the route:\n\n";
        if (tester.travelNormalCase(myRailroad) == true)
            cout << "\tNormal case of travel passed!\n";
        else
            cout << "\tNormal case of travel failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting travelling a route where the head station does not exist:\n\n";
        if (tester.travelErrorCaseOne(myRailroad) == true)
            cout << "\tNot traveling the route when the head station does not exist passed!\n";
        else
            cout << "\tNot traveling the route when the head station does not exist failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting travelling a route where a station (not the head station) does not exist:\n\n";
        if (tester.travelErrorCaseTwo(myRailroad) == true)
            cout << "\tNot traveling the route when one of the stations does not exist passed!\n";
        else
            cout << "\tNot traveling the route when one of the stations does not exist failed!\n";  
    }

    {
        Railroad myRailroad;
        cout << "\nTesting travelling a route where a station does not actually point to the station it says it does:\n\n";
        if (tester.travelErrorCaseThree(myRailroad) == true)
            cout << "\tNot traveling the route when one of the stations does not actually point to the station it says it does passed!\n";
        else
            cout << "\tNot traveling the route when one of the stations does not actually point to the station it says it does failed!\n";  
    }

    {
        Railroad myRailroad;

        for (int i=1;i<10;i++)
        myRailroad.extendAtTail(i,i*2);
        
        list<pair<int,DIRECTION>> aRoute;

        aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
        aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
        aRoute.push_back(pair<int,DIRECTION>(8,NONE));
        myRailroad.makeRoute(aRoute);

        Railroad myRailroad2 = Railroad(myRailroad);

        cout << "\nTesting the normal case of the copy constructor:\n\n";
        if (tester.copyConstructorNormalCase(myRailroad, myRailroad2) == true)
            cout << "\tNormal case of copy constructor passed!\n";
        else
            cout << "\tNormal case of copy constructor failed!\n";  
    }

    {
        Railroad myRailroad;

        myRailroad.extendAtTail(1,1*2);


        Railroad myRailroad2 = Railroad(myRailroad);

        cout << "\nTesting edge case of 1 station for the copy constructor:\n\n";
        if (tester.copyConstructorEdgeCaseOne(myRailroad, myRailroad2) == true)
            cout << "\tCopying one station in copy constructor passed!\n";
        else
            cout << "\tCopying one station in copy constructor failed!\n";  
    }

    {
        Railroad myRailroad;

        myRailroad.extendAtTail(1,1*2);
        myRailroad.extendAtTail(2,2*2);
        
        list<pair<int,DIRECTION>> aRoute;

        aRoute.push_back(pair<int,DIRECTION>(1,NORTH));
        aRoute.push_back(pair<int,DIRECTION>(2,NONE));
        myRailroad.makeRoute(aRoute);


        Railroad myRailroad2 = Railroad(myRailroad);

        cout << "\nTesting edge case of 2 stations for the copy constructor:\n\n";
        if (tester.copyConstructorEdgeCaseTwo(myRailroad, myRailroad2) == true)
            cout << "\tCopying two stations in copy constructor passed!\n";
        else
            cout << "\tCopying two stations in copy constructor failed!\n";  
    }

    {
        Railroad myRailroad;

        for (int i=1;i<10;i++)
        myRailroad.extendAtTail(i,i*2);
        
        list<pair<int,DIRECTION>> aRoute;

        aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
        aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
        aRoute.push_back(pair<int,DIRECTION>(8,NONE));
        myRailroad.makeRoute(aRoute);

        Railroad myRailroad2;

        for (int i=1;i<7;i++)
        myRailroad2.extendAtTail(i,i*2);
        
        list<pair<int,DIRECTION>> aRoute2;

        aRoute2.push_back(pair<int,DIRECTION>(8,EAST));
        aRoute2.push_back(pair<int,DIRECTION>(2,NORTH));
        aRoute2.push_back(pair<int,DIRECTION>(8,WEST));
        aRoute2.push_back(pair<int,DIRECTION>(9,NONE));
        myRailroad2.makeRoute(aRoute2);

        myRailroad2 = myRailroad;

        cout << "\nTesting the normal case of the overloaded operator:\n\n";
        if (tester.overloadedOperatorNormalCase(myRailroad, myRailroad2) == true)
            cout << "\tNormal case of overloaded operator passed!\n";
        else
            cout << "\tNormal case of overloaded operator failed!\n";  
    }

    {
        Railroad myRailroad;

        myRailroad.extendAtTail(1,1*2);
        

        Railroad myRailroad2;

        for (int i=1;i<7;i++)
        myRailroad2.extendAtTail(i,i*2);
        
        list<pair<int,DIRECTION>> aRoute2;

        aRoute2.push_back(pair<int,DIRECTION>(8,EAST));
        aRoute2.push_back(pair<int,DIRECTION>(2,NORTH));
        aRoute2.push_back(pair<int,DIRECTION>(8,WEST));
        aRoute2.push_back(pair<int,DIRECTION>(9,NONE));
        myRailroad2.makeRoute(aRoute2);

        myRailroad2 = myRailroad;

        cout << "\nTesting the overloaded operator for one station:\n\n";
        if (tester.overloadedOperatorNormalCase(myRailroad, myRailroad2) == true)
            cout << "\tOverloaded operator for one station passed!\n";
        else
            cout << "\tOverloaded operator for one station failed!\n";  
    }

    {
        Railroad myRailroad;

        myRailroad.extendAtTail(1,1*2);
        myRailroad.extendAtTail(2,2*2);

        list<pair<int,DIRECTION>> aRoute;

        aRoute.push_back(pair<int,DIRECTION>(1,EAST));
        aRoute.push_back(pair<int,DIRECTION>(2,NONE));

        Railroad myRailroad2;

        for (int i=1;i<7;i++)
        myRailroad2.extendAtTail(i,i*2);
        
        list<pair<int,DIRECTION>> aRoute2;

        aRoute2.push_back(pair<int,DIRECTION>(8,EAST));
        aRoute2.push_back(pair<int,DIRECTION>(2,NORTH));
        aRoute2.push_back(pair<int,DIRECTION>(8,WEST));
        aRoute2.push_back(pair<int,DIRECTION>(9,NONE));
        myRailroad2.makeRoute(aRoute2);

        myRailroad2 = myRailroad;

        cout << "\nTesting the overloaded operator for two stations:\n\n";
        if (tester.overloadedOperatorNormalCase(myRailroad, myRailroad2) == true)
            cout << "\tOverloaded operator for two stations passed!\n";
        else
            cout << "\tOverloaded operator for two stations failed!\n";  
    }

    return 0;
}
bool Tester::extendAtHeadNormalCase(Railroad &myRailroad){
    for(int i = 1;i < 10; i++){
        // False is bad, means the station was not inserted
        // Every station should be inserted as they are all unique
        if(myRailroad.extendAtHead(i, i*2) == false){
            // Failure
            return false;
        }
    }

    // Pointer to head of the linked list
    Station *myStation = myRailroad.returnHead();


    int counter = 9;

    // Going all the way to the end of the linked list
    while(myStation != nullptr){


        // Making sure the nodes line up with the previous "for loop"
        if(myStation->getStationCode() != counter || myStation->getNumPassegers() != (counter*2)){
            return false;
        }

        counter--;

        // Traverses
        myStation = myStation->getNext();
    }

    // Passed the tests
    return true;
}

bool Tester::extendAtHeadOneNode(Railroad &myRailroad){
    // False is bad, means the station was not inserted
    // Every station should be inserted as they are all unique
    if(myRailroad.extendAtHead(1, 2) == false){
        // Failure
        return false;
    }

    // Pointer to head of linked list
    Station *headStation = myRailroad.returnHead();
    // Pointer to the tail of the linked list
    Station *tailStation = myRailroad.returnTail();

    // Both head and tail should be the same

    if(headStation->getStationCode() != 1 || headStation->getNumPassegers() != 2){
        return false;
    }
    
    if(tailStation->getStationCode() != 1 || tailStation->getNumPassegers() != 2){
        return false;
    }

    return true;
}

bool Tester::extendAtHeadErrorCaseOne(Railroad &myRailroad){
    // Should return false, station number is negative
    if(myRailroad.extendAtHead(-1, 1) == false){
        return true;
    }
    return false;
}

bool Tester::extendAtHeadErrorCaseTwo(Railroad &myRailroad){
    myRailroad.extendAtHead(1, 2);

    // Should return false, station number is already used
    if(myRailroad.extendAtHead(1, 3) == false){
        return true;
    }
    return false;
}

bool Tester::extendAtHeadErrorCaseThree(Railroad &myRailroad){
    // Should return false, amount of passengers is negative
    if(myRailroad.extendAtHead(1, -1) == false){
        return true;
    }
    return false;
}

bool Tester::extendAtTailNormalCase(Railroad &myRailroad){
    for(int i = 1;i < 10; i++){
        // False is bad, means the station was not inserted
        // Every station should be inserted as they are all unique
        if(myRailroad.extendAtTail(i, i*2) == false){
            // Failure
            return false;
        }
    }

    // Pointer to head of the linked list
    Station *myStation = myRailroad.returnHead();


    int counter = 1;

    // Going all the way to the end of the linked list
    while(myStation != nullptr){


        // Making sure the nodes line up with the previous "for loop"
        if(myStation->getStationCode() != counter || myStation->getNumPassegers() != (counter*2)){
            return false;
        }

        counter++;

        // Traverses
        myStation = myStation->getNext();
    }

    // Passed the tests
    return true;
}

bool Tester::extendAtTailOneNode(Railroad &myRailroad){
    // False is bad, means the station was not inserted
    // Every station should be inserted as they are all unique
    if(myRailroad.extendAtTail(1, 2) == false){
        // Failure
        return false;
    }

    // Pointer to head of linked list
    Station *headStation = myRailroad.returnHead();
    // Pointer to the tail of the linked list
    Station *tailStation = myRailroad.returnTail();

    // Both head and tail should be the same

    if(headStation->getStationCode() != 1 || headStation->getNumPassegers() != 2){
        return false;
    }
    
    if(tailStation->getStationCode() != 1 || tailStation->getNumPassegers() != 2){
        return false;
    }

    return true;
}

bool Tester::extendAtTailErrorCaseOne(Railroad &myRailroad){
     // Should return false, station number is negative
    if(myRailroad.extendAtTail(-1, 1) == false){
        return true;
    }
    return false;
}

bool Tester::extendAtTailErrorCaseTwo(Railroad &myRailroad){
    myRailroad.extendAtTail(1, 2);

    // Should return false, station number is already used
    if(myRailroad.extendAtTail(1, 3) == false){
        return true;
    }
    return false;
}

bool Tester::extendAtTailErrorCaseThree(Railroad &myRailroad){
    // Should return false, amount of passengers is negative
    if(myRailroad.extendAtTail(1, -1) == false){
        return true;
    }
    return false;
}

bool Tester::removeAllStations(Railroad &myRailroad){
    for(int i = 1;i < 10; i++){
        // False is bad, means the station was not inserted
        // Every station should be inserted as they are all unique
        if(myRailroad.extendAtTail(i, i*2) == false){
            // Failure
            return false;
        }
    }

    for(int i = 1; i < 10; i++){
        // False is bad, menas the station was not removed
        if(myRailroad.removeStation(i) == false){
            return false;
        }
    }

    // Pointer to head of the linked list
    Station *myStationHead = myRailroad.returnHead();

    // Pointer to tail of the linked list
    Station *myStationTail = myRailroad.returnTail();

    // Linked list should be empty
    if(myStationHead != nullptr || myStationTail != nullptr){
        return false;
    }

    // Did what we wanted
    return true;
}

bool Tester::removeStationErrorCaseOne(Railroad &myRailroad){
    for(int i = 1;i < 10; i++){
        // False is bad, means the station was not inserted
        // Every station should be inserted as they are all unique
        if(myRailroad.extendAtTail(i, i*2) == false){
            // Failure
            return false;
        }
    }

    // Should return false, station does not exist
    if(myRailroad.removeStation(11) == true){
        return false;
    }

    // Did what we wanted
    return true;
}

bool Tester::removeStationAllLinksRemoved(Railroad &myRailroad){
    // Loops through 9 times
    for (int i=1;i<10;i++){
        // code is i
        // amount passengers is i * 2
        myRailroad.extendAtTail(i,i*2);  
    }
    
    list<pair<int,DIRECTION>> aRoute;
    
    aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(9,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(8,WEST));
    aRoute.push_back(pair<int,DIRECTION>(9,EAST));
    aRoute.push_back(pair<int,DIRECTION>(6,NONE));

    // Should work, breaks no rules
    if(myRailroad.makeRoute(aRoute) == false){
        return false;
    }

    myRailroad.removeStation(9);

    Station *tempStation = myRailroad.returnHead();

    // Station 9 should no longer exist
    while(tempStation != nullptr){
        if(tempStation->getStationCode() == 9){
            return false;
        }
        tempStation = tempStation->getNext();
    }

    Station *tempStation2 = myRailroad.returnHead();

    // Stations 2 and 8 should no longer point to 9
    while(tempStation2 != nullptr){
        if(tempStation2->getStationCode() == 2){
            if(tempStation2->getNorth() != nullptr){
                return false;
            }
        if(tempStation2->getStationCode() == 8){
            if(tempStation2->getWest()!= nullptr){
                return false;
            }
        }
        }
        tempStation2 = tempStation2->getNext();
    }


    // It does what it is supposed to do
    return true;
}

bool Tester::makeRouteErrorCaseOne(Railroad &myRailroad){
    // Loops through 9 times
    for (int i=1;i<10;i++){
        // code is i
        // amount passengers is i * 2
        myRailroad.extendAtTail(i,i*2);  
    }
    
    list<pair<int,DIRECTION>> aRoute;
    
    aRoute.push_back(pair<int,DIRECTION>(14,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(8,EAST));
    aRoute.push_back(pair<int,DIRECTION>(2,WEST));
    aRoute.push_back(pair<int,DIRECTION>(6,NONE));
    // Should not work as 14 is the first node and does not exist
    if(myRailroad.makeRoute(aRoute) == true){
        return false;
    }

    // It does what it is supposed to do
    return true;
}

bool Tester::makeRouteErrorCaseTwo(Railroad &myRailroad){
    // Loops through 9 times
    for (int i=1;i<10;i++){
        // code is i
        // amount passengers is i * 2
        myRailroad.extendAtTail(i,i*2);  
    }
    
    list<pair<int,DIRECTION>> aRoute;
    
    aRoute.push_back(pair<int,DIRECTION>(1,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(8,NONE));
    aRoute.push_back(pair<int,DIRECTION>(2,WEST));
    aRoute.push_back(pair<int,DIRECTION>(6,NONE));
    // Should not work as the middle pair points to NONE
    if(myRailroad.makeRoute(aRoute) == true){
        return false;
    }

    // It does what it is supposed to do
    return true;
}

bool Tester::makeRouteErrorCaseThree(Railroad &myRailroad){
    // Loops through 9 times
    for (int i=1;i<10;i++){
        // code is i
        // amount passengers is i * 2
        myRailroad.extendAtTail(i,i*2);  
    }
    
    list<pair<int,DIRECTION>> aRoute;
    
    aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(8,WEST));
    aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(6,NONE));
    // Should not work as station 2 points North to stations 5 and 6
    if(myRailroad.makeRoute(aRoute) == true){
        return false;
    }

    // It does what it is supposed to do
    return true;
}

bool Tester::makeRouteErrorCaseFour(Railroad &myRailroad){
    // Loops through 9 times
    for (int i=1;i<10;i++){
        // code is i
        // amount passengers is i * 2
        myRailroad.extendAtTail(i,i*2);  
    }
    
    list<pair<int,DIRECTION>> aRoute;
    
    aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(8,WEST));
    aRoute.push_back(pair<int,DIRECTION>(2,EAST));
    aRoute.push_back(pair<int,DIRECTION>(6,NONE));
    // Should work, follows all rules
    if(myRailroad.makeRoute(aRoute) == false){
        return false;
    }

    list<pair<int,DIRECTION>> aRoute2;

    aRoute2.push_back(pair<int,DIRECTION>(8,WEST));
    aRoute2.push_back(pair<int,DIRECTION>(3,NONE));

    // Should fail, 8 already points West to 2
    if(myRailroad.makeRoute(aRoute2) == true){
        return false;
    }

    // It does what it is supposed to do
    return true;
}

bool Tester::makeRouteNormalCase(Railroad &myRailroad){
    // Loops through 9 times
    for (int i=1;i<10;i++){
        // code is i
        // amount passengers is i * 2
        myRailroad.extendAtTail(i,i*2);  
    }
    
    list<pair<int,DIRECTION>> aRoute;
    
    aRoute.push_back(pair<int,DIRECTION>(5,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(7,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(8,WEST)); 
    aRoute.push_back(pair<int,DIRECTION>(9,NONE)); 

    myRailroad.makeRoute(aRoute);

    // Gets the head of the linked list
    Station *tempStation = myRailroad.returnHead();


    // Testing that all of the stations are pointing correctly
    while(tempStation != nullptr){
        if(tempStation->getStationCode() == 5){
            if(tempStation->getNorth()->getStationCode() != 7){
                return false;
            }
        }
        if(tempStation->getStationCode() == 7){
            if(tempStation->getSouth()->getStationCode() != 8){
                return false;
            }
        }
        if(tempStation->getStationCode() == 8){
            if(tempStation->getWest()->getStationCode() != 9){
                return false;
            }
        }
        tempStation = tempStation->getNext();
    }

    // It did its thing yo
    return true;
}

bool Tester::makeRouteEdgeCase(Railroad &myRailroad){
    // Loops through 9 times
    for (int i=1;i<10;i++){
        // code is i
        // amount passengers is i * 2
        myRailroad.extendAtTail(i,i*2);  
    }
    
    list<pair<int,DIRECTION>> aRoute;
    
    aRoute.push_back(pair<int,DIRECTION>(5,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(7,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(66,WEST));
    aRoute.push_back(pair<int,DIRECTION>(9,NONE)); 

    myRailroad.makeRoute(aRoute);

    // Gets the head of the linked list
    Station *tempStation = myRailroad.returnHead();


    // Testing that all of the stations are pointing correctly
    while(tempStation != nullptr){
        if(tempStation->getStationCode() == 5){
            if(tempStation->getNorth()->getStationCode() != 7){
                return false;
            }
        }
        if(tempStation->getStationCode() == 7){
            if(tempStation->getSouth()->getStationCode() != 66){
                return false;
            }
        }
        if(tempStation->getStationCode() == 66){
            if(tempStation->getWest()->getStationCode() != 9){
                return false;
            }
        }
        tempStation = tempStation->getNext();
    }

    // It did its thing yo
    return true;
}

bool Tester::makeRouteErrorCaseFive(Railroad &myRailroad){
    // Loops through 9 times
    for (int i=1;i<10;i++){
        // code is i
        // amount passengers is i * 2
        myRailroad.extendAtTail(i,i*2);  
    }
    
    list<pair<int,DIRECTION>> aRoute;
    
    aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(2,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(8,WEST));
    aRoute.push_back(pair<int,DIRECTION>(3,EAST));
    aRoute.push_back(pair<int,DIRECTION>(6,NONE));

    // Should fail, station 2 points to itself
    if(myRailroad.makeRoute(aRoute) == true){
        return false;
    }


    // It does what it is supposed to do
    return true;
}

bool Tester::travelNormalCase(Railroad &myRailroad){
    Railroad aNetwork;

    for (int i=1;i<10;i++){
        aNetwork.extendAtTail(i,i*2);
    }

    list<pair<int,DIRECTION>> aRoute;

    aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(8,NONE));

    aNetwork.makeRoute(aRoute);

    int totalPassengers = 0;

    Station *tempStation = aNetwork.returnHead();

    while(tempStation != nullptr){
        if(tempStation->getStationCode() == 2 || tempStation->getStationCode() == 5 || tempStation->getStationCode() == 8)
        totalPassengers += tempStation->getNumPassegers();

        tempStation = tempStation->getNext();
    }

    // Should be equivalent
    if(aNetwork.travel(aRoute) != totalPassengers){
        return false;
    }
    
    // Did the job
    return true;
}

bool Tester::travelErrorCaseOne(Railroad &myRailroad){
    Railroad aNetwork;

    for (int i=1;i<10;i++)
        aNetwork.extendAtTail(i,i*2);

    list<pair<int,DIRECTION>> aRoute;

    aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(8,NONE));
    aNetwork.makeRoute(aRoute);

    list<pair<int,DIRECTION>> aRoute2;

    aRoute2.push_back(pair<int,DIRECTION>(68,NORTH));
    aRoute2.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute2.push_back(pair<int,DIRECTION>(5,SOUTH));
    aRoute2.push_back(pair<int,DIRECTION>(8,NONE));

    // Should be -1, station 68 does not exist
    if(aNetwork.travel(aRoute2) != -1){
        return false;
    }else{
        return true;
    }

}

bool Tester::travelErrorCaseTwo(Railroad &myRailroad){
    Railroad aNetwork;

    for (int i=1;i<10;i++)
        aNetwork.extendAtTail(i,i*2);

    list<pair<int,DIRECTION>> aRoute;

    aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(8,NONE));
    aNetwork.makeRoute(aRoute);

    list<pair<int,DIRECTION>> aRoute2;

    aRoute2.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute2.push_back(pair<int,DIRECTION>(5,SOUTH));
    aRoute2.push_back(pair<int,DIRECTION>(68,NORTH));
    aRoute2.push_back(pair<int,DIRECTION>(8,NONE));

    // Should be -1, station 68 does not exist
    if(aNetwork.travel(aRoute2) != -1){
        return false;
    }else{
        return true;
    }

}

bool Tester::travelErrorCaseThree(Railroad &myRailroad){
    Railroad aNetwork;

    for (int i=1;i<10;i++)
        aNetwork.extendAtTail(i,i*2);

    list<pair<int,DIRECTION>> aRoute;

    aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(8,NONE));
    aNetwork.makeRoute(aRoute);

    list<pair<int,DIRECTION>> aRoute2;

    aRoute2.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute2.push_back(pair<int,DIRECTION>(5,EAST));
    aRoute2.push_back(pair<int,DIRECTION>(8,NONE));

    // Should be -1, station 5 does not point East to station 8
    if(aNetwork.travel(aRoute2) != -1){
        return false;
    }else{
        return true;
    }

}

bool Tester::copyConstructorNormalCase(Railroad &myRailroad, Railroad &myRailroad2){
    // Should have different memory addresses
    if(&myRailroad != &myRailroad2){
        // Point to the head of each of the linked lists
        Station *tempStation = myRailroad.returnHead();
        Station *tempStation2 = myRailroad2.returnHead();

        // Loops through linked list
        while(tempStation != nullptr){
            // If any value is different -> fails
            if(tempStation->getNumPassegers() != tempStation2->getNumPassegers()){
                return false;
            }
            if(tempStation->getStationCode() != tempStation2->getStationCode()){
                return false;
            }

            if(tempStation->getNorth() != nullptr && tempStation2->getNorth() != nullptr){
                if(tempStation->getNorth()->getStationCode() != tempStation2->getNorth()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getNorth() != nullptr && tempStation2->getNorth() == nullptr){
                return false;
            }
            
            if(tempStation->getNorth() == nullptr && tempStation2->getNorth() != nullptr){
                return false;
            }


            if(tempStation->getWest() != nullptr && tempStation2->getWest() != nullptr){
                if(tempStation->getWest()->getStationCode() != tempStation2->getWest()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getWest() != nullptr && tempStation2->getWest() == nullptr){
                return false;
            }

            if(tempStation->getWest() == nullptr && tempStation2->getWest() != nullptr){
                return false;
            }



            if(tempStation->getEast() != nullptr && tempStation2->getEast() != nullptr){
                if(tempStation->getEast()->getStationCode() != tempStation2->getEast()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getEast() != nullptr && tempStation2->getEast() == nullptr){
                return false;
            }

            if(tempStation->getEast() == nullptr && tempStation2->getEast() != nullptr){
                return false;
            }


            if(tempStation->getSouth() != nullptr && tempStation2->getSouth() != nullptr){
                if(tempStation->getSouth()->getStationCode() != tempStation2->getSouth()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getSouth() == nullptr && tempStation2->getSouth() != nullptr){
                return false;
            }

            if(tempStation->getSouth() != nullptr && tempStation2->getSouth() == nullptr){
                return false;
            }

            // Traverses both linked lists
            tempStation = tempStation->getNext();
            tempStation2 = tempStation2->getNext();
        }
    }
    // Great work
    return true;
}

bool Tester::copyConstructorEdgeCaseTwo(Railroad &myRailroad, Railroad &myRailroad2){
    // Should have different memory addresses
    if(&myRailroad != &myRailroad2){
        // Point to the head of each of the linked lists
        Station *tempStation = myRailroad.returnHead();
        Station *tempStation2 = myRailroad2.returnHead();

        // Loops through linked list
        while(tempStation != nullptr){
            // If any value is different -> fails
            if(tempStation->getNumPassegers() != tempStation2->getNumPassegers()){
                return false;
            }
            if(tempStation->getStationCode() != tempStation2->getStationCode()){
                return false;
            }

            if(tempStation->getNorth() != nullptr && tempStation2->getNorth() != nullptr){
                if(tempStation->getNorth()->getStationCode() != tempStation2->getNorth()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getNorth() != nullptr && tempStation2->getNorth() == nullptr){
                return false;
            }
            
            if(tempStation->getNorth() == nullptr && tempStation2->getNorth() != nullptr){
                return false;
            }


            if(tempStation->getWest() != nullptr && tempStation2->getWest() != nullptr){
                if(tempStation->getWest()->getStationCode() != tempStation2->getWest()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getWest() != nullptr && tempStation2->getWest() == nullptr){
                return false;
            }

            if(tempStation->getWest() == nullptr && tempStation2->getWest() != nullptr){
                return false;
            }



            if(tempStation->getEast() != nullptr && tempStation2->getEast() != nullptr){
                if(tempStation->getEast()->getStationCode() != tempStation2->getEast()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getEast() != nullptr && tempStation2->getEast() == nullptr){
                return false;
            }

            if(tempStation->getEast() == nullptr && tempStation2->getEast() != nullptr){
                return false;
            }


            if(tempStation->getSouth() != nullptr && tempStation2->getSouth() != nullptr){
                if(tempStation->getSouth()->getStationCode() != tempStation2->getSouth()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getSouth() == nullptr && tempStation2->getSouth() != nullptr){
                return false;
            }

            if(tempStation->getSouth() != nullptr && tempStation2->getSouth() == nullptr){
                return false;
            }

            // Traverses both linked lists
            tempStation = tempStation->getNext();
            tempStation2 = tempStation2->getNext();
        }
    }
    // Great work
    return true;
}

bool Tester::copyConstructorEdgeCaseOne(Railroad &myRailroad, Railroad &myRailroad2){
    // Should have different memory addresses
    if(&myRailroad != &myRailroad2){
        // Point to the head of each of the linked lists
        Station *tempStation = myRailroad.returnHead();
        Station *tempStation2 = myRailroad2.returnHead();

        // Loops through linked list
        while(tempStation != nullptr){
            // If any value is different -> fails
            if(tempStation->getNumPassegers() != tempStation2->getNumPassegers()){
                return false;
            }
            if(tempStation->getStationCode() != tempStation2->getStationCode()){
                return false;
            }

            if(tempStation->getNorth() != nullptr && tempStation2->getNorth() != nullptr){
                if(tempStation->getNorth()->getStationCode() != tempStation2->getNorth()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getNorth() != nullptr && tempStation2->getNorth() == nullptr){
                return false;
            }
            
            if(tempStation->getNorth() == nullptr && tempStation2->getNorth() != nullptr){
                return false;
            }


            if(tempStation->getWest() != nullptr && tempStation2->getWest() != nullptr){
                if(tempStation->getWest()->getStationCode() != tempStation2->getWest()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getWest() != nullptr && tempStation2->getWest() == nullptr){
                return false;
            }

            if(tempStation->getWest() == nullptr && tempStation2->getWest() != nullptr){
                return false;
            }



            if(tempStation->getEast() != nullptr && tempStation2->getEast() != nullptr){
                if(tempStation->getEast()->getStationCode() != tempStation2->getEast()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getEast() != nullptr && tempStation2->getEast() == nullptr){
                return false;
            }

            if(tempStation->getEast() == nullptr && tempStation2->getEast() != nullptr){
                return false;
            }


            if(tempStation->getSouth() != nullptr && tempStation2->getSouth() != nullptr){
                if(tempStation->getSouth()->getStationCode() != tempStation2->getSouth()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getSouth() == nullptr && tempStation2->getSouth() != nullptr){
                return false;
            }

            if(tempStation->getSouth() != nullptr && tempStation2->getSouth() == nullptr){
                return false;
            }

            // Traverses both linked lists
            tempStation = tempStation->getNext();
            tempStation2 = tempStation2->getNext();
        }
    }
    // Great work
    return true;
}

bool Tester::overloadedOperatorNormalCase(Railroad &myRailroad, Railroad &myRailroad2){
    // Should have different memory addresses
    if(&myRailroad != &myRailroad2){
        // Point to the head of each of the linked lists
        Station *tempStation = myRailroad.returnHead();
        Station *tempStation2 = myRailroad2.returnHead();

        // Loops through linked list
        while(tempStation != nullptr){
            // If any value is different -> fails
            if(tempStation->getNumPassegers() != tempStation2->getNumPassegers()){
                return false;
            }
            if(tempStation->getStationCode() != tempStation2->getStationCode()){
                return false;
            }

            if(tempStation->getNorth() != nullptr && tempStation2->getNorth() != nullptr){
                if(tempStation->getNorth()->getStationCode() != tempStation2->getNorth()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getNorth() != nullptr && tempStation2->getNorth() == nullptr){
                return false;
            }
            
            if(tempStation->getNorth() == nullptr && tempStation2->getNorth() != nullptr){
                return false;
            }


            if(tempStation->getWest() != nullptr && tempStation2->getWest() != nullptr){
                if(tempStation->getWest()->getStationCode() != tempStation2->getWest()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getWest() != nullptr && tempStation2->getWest() == nullptr){
                return false;
            }

            if(tempStation->getWest() == nullptr && tempStation2->getWest() != nullptr){
                return false;
            }



            if(tempStation->getEast() != nullptr && tempStation2->getEast() != nullptr){
                if(tempStation->getEast()->getStationCode() != tempStation2->getEast()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getEast() != nullptr && tempStation2->getEast() == nullptr){
                return false;
            }

            if(tempStation->getEast() == nullptr && tempStation2->getEast() != nullptr){
                return false;
            }


            if(tempStation->getSouth() != nullptr && tempStation2->getSouth() != nullptr){
                if(tempStation->getSouth()->getStationCode() != tempStation2->getSouth()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getSouth() == nullptr && tempStation2->getSouth() != nullptr){
                return false;
            }

            if(tempStation->getSouth() != nullptr && tempStation2->getSouth() == nullptr){
                return false;
            }

            // Traverses both linked lists
            tempStation = tempStation->getNext();
            tempStation2 = tempStation2->getNext();
        }
    }
    // Great work
    return true;
}

bool Tester::overloadedOperatorEdgeCaseOne(Railroad &myRailroad, Railroad &myRailroad2){
    // Should have different memory addresses
    if(&myRailroad != &myRailroad2){
        // Point to the head of each of the linked lists
        Station *tempStation = myRailroad.returnHead();
        Station *tempStation2 = myRailroad2.returnHead();

        // Loops through linked list
        while(tempStation != nullptr){
            // If any value is different -> fails
            if(tempStation->getNumPassegers() != tempStation2->getNumPassegers()){
                return false;
            }
            if(tempStation->getStationCode() != tempStation2->getStationCode()){
                return false;
            }

            if(tempStation->getNorth() != nullptr && tempStation2->getNorth() != nullptr){
                if(tempStation->getNorth()->getStationCode() != tempStation2->getNorth()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getNorth() != nullptr && tempStation2->getNorth() == nullptr){
                return false;
            }
            
            if(tempStation->getNorth() == nullptr && tempStation2->getNorth() != nullptr){
                return false;
            }


            if(tempStation->getWest() != nullptr && tempStation2->getWest() != nullptr){
                if(tempStation->getWest()->getStationCode() != tempStation2->getWest()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getWest() != nullptr && tempStation2->getWest() == nullptr){
                return false;
            }

            if(tempStation->getWest() == nullptr && tempStation2->getWest() != nullptr){
                return false;
            }



            if(tempStation->getEast() != nullptr && tempStation2->getEast() != nullptr){
                if(tempStation->getEast()->getStationCode() != tempStation2->getEast()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getEast() != nullptr && tempStation2->getEast() == nullptr){
                return false;
            }

            if(tempStation->getEast() == nullptr && tempStation2->getEast() != nullptr){
                return false;
            }


            if(tempStation->getSouth() != nullptr && tempStation2->getSouth() != nullptr){
                if(tempStation->getSouth()->getStationCode() != tempStation2->getSouth()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getSouth() == nullptr && tempStation2->getSouth() != nullptr){
                return false;
            }

            if(tempStation->getSouth() != nullptr && tempStation2->getSouth() == nullptr){
                return false;
            }

            // Traverses both linked lists
            tempStation = tempStation->getNext();
            tempStation2 = tempStation2->getNext();
        }
    }
    // Great work
    return true;
}

bool Tester::overloadedOperatorEdgeCaseTwo(Railroad &myRailroad, Railroad &myRailroad2){
    // Should have different memory addresses
    if(&myRailroad != &myRailroad2){
        // Point to the head of each of the linked lists
        Station *tempStation = myRailroad.returnHead();
        Station *tempStation2 = myRailroad2.returnHead();

        // Loops through linked list
        while(tempStation != nullptr){
            // If any value is different -> fails
            if(tempStation->getNumPassegers() != tempStation2->getNumPassegers()){
                return false;
            }
            if(tempStation->getStationCode() != tempStation2->getStationCode()){
                return false;
            }

            if(tempStation->getNorth() != nullptr && tempStation2->getNorth() != nullptr){
                if(tempStation->getNorth()->getStationCode() != tempStation2->getNorth()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getNorth() != nullptr && tempStation2->getNorth() == nullptr){
                return false;
            }
            
            if(tempStation->getNorth() == nullptr && tempStation2->getNorth() != nullptr){
                return false;
            }


            if(tempStation->getWest() != nullptr && tempStation2->getWest() != nullptr){
                if(tempStation->getWest()->getStationCode() != tempStation2->getWest()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getWest() != nullptr && tempStation2->getWest() == nullptr){
                return false;
            }

            if(tempStation->getWest() == nullptr && tempStation2->getWest() != nullptr){
                return false;
            }



            if(tempStation->getEast() != nullptr && tempStation2->getEast() != nullptr){
                if(tempStation->getEast()->getStationCode() != tempStation2->getEast()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getEast() != nullptr && tempStation2->getEast() == nullptr){
                return false;
            }

            if(tempStation->getEast() == nullptr && tempStation2->getEast() != nullptr){
                return false;
            }


            if(tempStation->getSouth() != nullptr && tempStation2->getSouth() != nullptr){
                if(tempStation->getSouth()->getStationCode() != tempStation2->getSouth()->getStationCode()){
                    return false;
                }
            }

            if(tempStation->getSouth() == nullptr && tempStation2->getSouth() != nullptr){
                return false;
            }

            if(tempStation->getSouth() != nullptr && tempStation2->getSouth() == nullptr){
                return false;
            }

            // Traverses both linked lists
            tempStation = tempStation->getNext();
            tempStation2 = tempStation2->getNext();
        }
    }
    // Great work
    return true;
}
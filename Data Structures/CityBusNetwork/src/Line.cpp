#include "Line.h"
#include <iostream>
using namespace std;
int compareByDistance(LineStationData dataOne, LineStationData dataTwo)
{
    if(dataOne.distance > dataTwo.distance)
        return 1;
    else if(dataOne.distance == dataTwo.distance)
        return 0;
    else
        return -1;
}
int compareById(LineStationData dataOne, LineStationData dataTwo)
{
    if(dataOne.stnId == dataTwo.stnId)
        return true;
    else
        return false;
}
Line::Line()
{
    lineNb = -1;//lineNb;       //Identification number for a line.
    nbStations = 0;   //Number of stations on a line
    changed = false;
    stationsList = new List<LineStationData>(compareByDistance, compareById); //Line of stations
}
Line::~Line()
{
    delete stationsList;
}
Line& Line::operator=(Line& old){
    lineNb = old.getLineNb();//Identification number for a line.
    nbStations = old.getNumStations(); //Number of stations on a line
    changed = old.getStatus();
    stationsList = old.getStationsList();
    return *this;
}
/*int Line::compareFunction1(LineStationData dataOne, LineStationData dataTwo)
{
    if(dataOne.distance > dataTwo.distance)
        return 1;
    else if(dataOne.distance == dataTwo.distance)
        return 0;
    else
        return -1;
}*/
bool Line::addStation(LineStationData station)
{
    if(stationsList->insert(station)){
        nbStations++;
        changed = true;
        return true;
    };
    return false;
};
bool Line::deleteStation(int stnId)
{
    LineStationData station;
    station.stnId = stnId;
    //station.distance = distance;
    if(stationsList->remove(station)){
        nbStations--;
        changed = true;
        return true;
    };
    return false;
}
///Displays all informations of all stations when traversing a line in the forward direction
void Line::traverseForward(Stations& stations) {
    Node<LineStationData>* p = Line::stationsList->getFront();
	cout<<"Line: " << this->lineNb << endl;
    cout<<"Number of Stations: " << this->nbStations<< endl;
	while (p  != NULL) {
		cout <<p->data.stnId << " (" << stations.mapStation(p->data.stnId)<<") ";
	 	if (p->next)
            cout << " -> ";
        p = p->next;
	}
	cout << endl<<endl;
}
///Displays all informations of all stations when traversing a line in the backward direction
void Line::traverseBackward(Stations& stations) {
    Node<LineStationData>* p = Line::stationsList->getBack();
	cout<<"Line: "<< this->lineNb << endl;
    cout<<"Number of Stations: " << this->nbStations<< endl;
	while (p  != NULL) {
		cout <<p->data.stnId << " (" << stations.mapStation(p->data.stnId )<<") ";
	 	if (p->prev)
            cout << " -> ";
	 	p = p->prev;
	}
	cout << endl<<endl;
}

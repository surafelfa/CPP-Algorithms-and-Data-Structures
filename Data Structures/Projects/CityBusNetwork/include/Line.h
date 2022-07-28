#ifndef LINE_H
#define LINE_H
#include "List.h"
#include "Stations.h"
#include "../src/List.cpp"

struct LineStationData{
	int  stnId; // station number
	float distance; // distance from the beginning
};
////structure for city line.
class Line
{
    public:
        Line();
        virtual ~Line();
        Line& operator=(Line&old);
        bool addStation(LineStationData station);//add station to a line
        bool deleteStation(int stnId);//remove station from the station list
        void traverseForward(Stations& stations);//traverse line in the forward direction
        void traverseBackward(Stations& stations);
        List<LineStationData> getSubLine();
        //int compareFunction1(LineStationData dataOne, LineStationData dataTwo);
        void setLineNb(int lineNb){
            this->lineNb = lineNb;
        }
        int getLineNb(){
            return lineNb;
        }
        void setNumStations(int nbStn){
            nbStations = nbStn;
        }
        int getNumStations(){
            return nbStations;
        }
        List<LineStationData>*& getStationsList(){
            return stationsList;
        }
        void setStatus(bool changed){
            this->changed = changed;
        }
        bool getStatus()
        {
            return changed;
        }
    private:
        int lineNb;//Identification number for a line.
        int nbStations; //Number of stations on a line
        bool changed;
        List<LineStationData>* stationsList;// = new List<LineStationData>(compare); //Line of stations
};
#endif // LINE_H

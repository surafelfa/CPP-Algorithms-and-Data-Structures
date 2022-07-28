#ifndef NETWORK_H
#define NETWORK_H
#include "Line.h"


const int BLANK_LINE=-1;
class Network
{
    public:
        Network();
        virtual ~Network();
        int lineIndex(int lineNb);
        int buildNetwork(string networkFileName);
        int updateNetFile(string netFileName);
        bool addLine(int lineNb);
        bool deleteLine(int lineNb);
        void editLine(int lineNb, int position);
        int findLine(int lineNb);
        bool save(fstream& fst, char* path);
        //The function determine the number of lines passing through a station
        int nbLinesPerStation(int stnId);
        /*The function returns the first line, the second line and so
        on passing through a station controlled by the order value*/
        void LineThroughStation(int stnId, int which, Line& l);
        /*The function returns whether or not there is a direct line
        between two stations using a given line number/id*/
        int directLine( int stn1Id, int stn2Id);
        bool directtLine(int lineId, int stn1Id, int stn2Id);
        void displayLinesForward(Stations& stations);//displays all lines in forward direction
        void displayLinesBackward(Stations& stations);
        //The function returns the distance between two stations in terms of actual distance
        float distance(int line,int station1,int station2);
        //finds the shortest path from some station to another
        List<LineStationData> shortestPath();
        //The function returns sub part of a line controlled by start station and destination station
        Line* getSubLine();
        bool getStatus(){
            return changed;
        }
        void setStatus(bool changed){
            this->changed = changed;
        }
        Line*& getLines(){
            return lines;
        }
        void setLines(Line* lines){
            this->lines = lines;
        }
        int getNbLines(){
            return nbLines;
        }
        void getNbLines(int nbLines){
            this->nbLines = nbLines;
        }
        /*Line& getSingleLine(int index){
            return lines[index];
        }*/
        void shortestPath(int station1,int station2);
    private:
        int nbLines;  //no of lines.
        int tempNbLines;
        int avail;
        bool changed; //flag to control save status of network
        Line* lines; //dynamic array to hold lines in network
};
#endif // NETWORK_H

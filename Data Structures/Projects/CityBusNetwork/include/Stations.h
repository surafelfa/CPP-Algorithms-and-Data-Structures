#ifndef STATION_H
#define STATION_H
#include <bits/stdc++.h>

using namespace std;

struct StationIdentifier{
	int stnId;        //A number for identification of a station
	string name;  // Name for a station
};
const StationIdentifier BLANK_STATION={-1,""};

class Stations
{
    public:
        Stations();
        virtual ~Stations();
        int buildStations(string stnFileName);//load the station file into memory
        StationIdentifier prompt();
        int findStation(int sntId);
        void editStationName(string name,int position);
        void editStationNumber(int stnId,int position);
        bool addStation(int stnId, string name); //Add station to the end of the station list
        int updateStnFile(string stnFileName);
        bool deleteStation(int stnId);//remove station from the station list
        void displayStations();

        string convertToString(char* name, int size);
        //maps station id to station name or vice verse.
        string mapStation(int stNo);
        int mapStation(string stName);
        bool save(fstream& fst, char *path);
        void writeStation(fstream& fstr, StationIdentifier stn)
        {
            fstr<<stn.stnId<<'\t'<<stn.name<<'\n';
        }
        void setStatus(bool changed){
            this->changed = changed;
        }
        bool getStatus()
        {
            return changed;
        }
        void setStationsList(StationIdentifier* stationList){
            this->stationList = stationList;
        }
        StationIdentifier* getStationList(){
            return stationList;
        }
    private:
        int nbStations;//no of stations in the network.
        int tempNbStations;
        int avail;//no of slot available to add new slot
        //int lastId;
        bool changed;
        StationIdentifier* stationList; //dynamic array to hold the stations in the network
};

#endif // STATION_H

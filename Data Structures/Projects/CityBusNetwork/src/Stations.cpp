#include "Stations.h"

Stations::Stations()
{
    nbStations = -1;
    avail = -1;
    changed=false;
}

Stations::~Stations()
{
    delete stationList;
}
int Stations::buildStations(string stnFileName)
{
	long nbStns;
	ifstream stnf;
	stnf.open(stnFileName, ios::in);
	if(stnf)
    {
		stnf.seekg(0, ios::beg);
		stnf >> nbStns;
        stationList = new (nothrow) StationIdentifier[nbStns+10];
		if(!stationList)
            return 0; //not enough memory
        nbStations = tempNbStations = nbStns;
		avail=10; //10 more space to add new stations
		for(long i=0; i < nbStns; i++)
		{
			stnf >>stationList[i].stnId;
			stnf >>stationList[i].name;
		}
		return 2; //success
	}else
    {
		ofstream ofs(stnFileName);
		if(!ofs)
            return 1;//unable to open file
		ofs << 0 << "\n";
		stnf.close();
		return Stations::buildStations(stnFileName);
	}
}
StationIdentifier Stations::prompt()
{
    StationIdentifier newStation;
    cout<<"Enter Station's Id: ";
    cin>>newStation.stnId;
    cout<<"Enter Station's name: ";
    cin>>newStation.name;
    return newStation;
}
bool Stations::addStation(int stnId, string name)
{
    //StationIdentification newStation;
    StationIdentifier *temp;
    if(avail==0) {
        temp = new (nothrow) StationIdentifier[nbStations+10];
        if(temp){
            for(long i=0;i < nbStations;i++)
                temp[i]=stationList[i];
            delete stationList;
            stationList=temp;
            avail=10;
        }else
            return 0;//fails
    }
    stationList[nbStations].stnId = stnId;// = prompt();
    stationList[nbStations].name = name;
    //std::copy(name, name+20, stationList[nbStations].name);//stationList[nbStations].name = name;
    nbStations++;
    tempNbStations++;
    avail--;
    //changed = true;
    return 1;
}
int Stations::findStation(int stnId)
{
    int position = -1;
    bool found = false;
    for(int i=0; !found && i < nbStations; i++)
    {
        if(stationList[i].stnId == stnId)
        {
            position = i;
            found = true;
        }
    }
    return position;
}
void Stations::editStationName(string name, int position)
{
    stationList[position].name = name;
};
void Stations::editStationNumber(int stnId,int position)
{
    stationList[position].stnId = stnId;
};
bool Stations::deleteStation(int stnId)
{
    int position;
    position = findStation(stnId);
    if(position != -1){
        stationList[position] = BLANK_STATION;
        tempNbStations--;
        changed = true;
        return true;
    }
    return false;

};
void Stations::displayStations(){
    system("cls");
    cout<<"Number of Stations: "<<nbStations<<endl;
    cout<<left<<setw(5)<< "Id" <<'\t'<<setw(40)<<"Station Name"<<endl;
    for(int i=0; i < nbStations; i++)
        if(stationList[i].stnId != -1)
            cout<<setw(5)<<stationList[i].stnId<<'\t'<<setw(40)<<stationList[i].name<<endl;
    cout<<endl;
}
string Stations::convertToString(char* name, int size)
{
    string s = "";
    for (int i = 0; i < size; i++)
        s += name[i];
    return s;
}
string Stations::mapStation(int stNo)
{
    int position = findStation(stNo);
    if(position != -1)
        return stationList[position].name;//convertToString(stationList[position].name, 20);
    return "\0";
}

int Stations::mapStation(string stName)
{
    for(int i= 0; i < nbStations; i++)
        if(stName == stationList[i].name)
            return stationList[i].stnId;
    return -1;
}
bool Stations::save(fstream& fst, char* path){
    fstream ofs("temp.txt", ios::out);
    fst.seekg(0, ios::beg);
    if(ofs){
         ofs<<tempNbStations<<'\n';
         for(long i=0; i < nbStations; i++)
            if(stationList[i].stnId != -1)
                writeStation(ofs,stationList[i]);
         fst.close();
         remove(path);
         ofs.close();
         rename("temp.txt",path);
         fst.open(path);
         changed = true;
         return 1;
     }
     return 0;
}
//The function updates the stations file
int Stations::updateStnFile(string stnFileName){
	 //StationIdentifier* newStationList= this->stationList;
	 int nbStns= this->nbStations;
	 ofstream stnf;
	 stnf.open(stnFileName, ios::out);
	 if(!stnf){
		stnf.clear();
		return 0;  //file not opened successfully.update failed
	 }else{
		stnf << nbStns<< endl;
		for(int i=0; i < nbStns; i++) {
            //writeStation(stnf,stationList[i]);
			stnf << this->stationList[i].stnId<<"\t"<<this->stationList[i].name<<"\n";
		}
        stnf.close();
	 	return 1; // update success

	 }
}

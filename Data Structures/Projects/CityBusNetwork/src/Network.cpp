#include "Network.h"

Network::Network()
{
    avail = nbLines = -1;
    changed = false;
}

Network::~Network()
{
    delete lines;
}
//The function returns the array index of a line given the line number/id
int Network::lineIndex(int lineNb)
{
    for(int i = 0; i < nbLines; i++)
        if(lines[i].getLineNb() == lineNb)
            return i;
    return -1;//not found
}
int Network::buildNetwork(string netFileName) //build network from file
{
    int nbLns, lineNb, nbStations;
    LineStationData p;
	ifstream netf;
	netf.open(netFileName, ios::in);
	if(netf){
		netf >> nbLns;
		this->lines = new (nothrow) Line[nbLns + 10];
		if(!this->lines){
            netf.close();
            return 0;
        }//no memory
		this->nbLines = tempNbLines = nbLns;
	 	Node<LineStationData>* prev = NULL;  // Initially, the linked list is empty
	 	for(int i=0; i < nbLns; i++){
			netf >> lineNb;

			this->lines[i].setLineNb(lineNb);
			netf >> nbStations;
			this->lines[i].setNumStations(nbStations);
			for(int j=1; j <= nbStations; j++){
		     		netf >> p.stnId;
		     		netf >> p.distance;
		     		this->lines[i].getStationsList()->insertBack(p/*this.lines[i].stationsList.getBack()*/);
			}
		}
		avail = 10;
		netf.close();
        return 2;
	}else{
	    ofstream ofs(netFileName);
		if(!ofs)
            return 1;//unable to open file
		ofs << 0 << "\n";
        netf.clear();
		return Network::buildNetwork(netFileName);
	}
}
bool Network::addLine(int lineNb)
{
    Line *temp;
    if(avail==0){
        temp = new (nothrow) Line[nbLines+10];
        if(temp){
            for(long i=0; i < nbLines; i++)
                temp[i] = lines[i];
            delete lines;
            lines=temp;
            avail=10;
        }else
            return 0;//fails
    }
    lines[nbLines++].setLineNb(lineNb);// = lineNb;
    avail--;
    changed = true;
    tempNbLines++;
    return 1;
}
//The function updates the network file
int Network::updateNetFile(string netFileName){
	 Node<LineStationData> *p;
	 Line* lns= this->lines;
	 int nbLns= this->nbLines;
	 ofstream ntf;
	 ntf.open(netFileName,ios::out);
	 if(!ntf){
		ntf.clear();
		return 0;  //file not opened successfully
	 }else{
		ntf << nbLns << endl;
		for(int i = 0; i < nbLns; i++) {
			ntf << lns[i].getLineNb()<< "\t"<<lns[i].getNumStations()<< "\t";
			p = lns[i].getStationsList()->getFront();//front;
			while(p!= NULL) {
				ntf << p->data.stnId << " " << p->data.distance << " ";
				p=p->next;
			}
			ntf << "\n";
		}
		 ntf.close();
	 	return 1;
	 }
}
int Network::findLine(int lineNb)
{
    int position = -1;
    bool found = false;
    for(int i=0; !found && i < nbLines; i++)
    {
        if(lines[i].getLineNb() == lineNb)
        {
            position = i;
            found = true;
        }
    }
    return position;
}
bool Network::deleteLine(int lineNb)
{
    int position;
    position = findLine(lineNb);
    if(position != -1){
        lines[position].setLineNb(BLANK_LINE);
        tempNbLines--;
        changed = true;
        return true;
    }
    return false;

};
void Network::editLine(int lineNb, int position)
{
    lines[position].setLineNb(lineNb);
}
bool Network::save(fstream& fst, char* path){
    Node<LineStationData> *p;
    Line* lns= this->lines;
    fstream ofs("temp.txt", ios::out);
    fst.seekg(0, ios::beg);
    if(ofs){
        ofs<<tempNbLines<<'\n';
        for(int i = 0; i < nbLines; i++) {
            if(lns[i].getLineNb() != -1){
                ofs << lns[i].getLineNb()<< "\t"<<lns[i].getNumStations()<< "\t";
                p = lns[i].getStationsList()->getFront();//front;
                while(p!= NULL) {
                    //cout<<"p->data.stnId: "<<p->data.stnId <<"p->data.distance: "<<p->data.distance<<endl;
                    ofs << p->data.stnId << " " << p->data.distance << " ";
                    p=p->next;
                }
                ofs << "\n";
            }
        }
        fst.close();
        remove(path);
        ofs.close();
        rename("temp.txt",path);
        fst.open(path);
        changed = false;
        return 1;
     }
     return 0;
}
//The function determine the number of lines passing through a station
int Network::nbLinesPerStation(int stnId)
{
    int count = 0;
    LineStationData station;
    station.stnId = stnId;
    for(int i = 0; i < nbLines; i++){
        if(lines[i].getStationsList()->findById(station) != NULL){
            count++;
        }
    }
    return count;
};
/*The function returns the first line, the second line and so
on passing through a station controlled by the order value*/
void Network::LineThroughStation(int stnId, int which,Line& l)
{
    Line line[nbLinesPerStation(stnId)+1];
    LineStationData station;
    station.stnId = stnId;
    int j = 0;
    for(int i = 0; i < nbLines; i++){
        if(lines[i].getStationsList()->findById(station) != NULL){
            line[j++] = lines[i];//getSingleLine(i);//lines[i];
        }
    }//cout<<"line[which]: "<<line[which].getLineNb()<<endl;
    //return
    l = line[which];
}
/*The function returns whether or not there is a direct line
between two stations using a given line number/id*/
int Network::directLine( int stn1Id, int stn2Id)
{
    LineStationData station1, station2;
    station1.stnId = stn1Id;
    station2.stnId = stn2Id;
    for (int i = 0;  i < this->nbLines; i++){
            if((lines[i].getStationsList()->findById(station1) != NULL) && (lines[i].getStationsList()->findById(station2) != NULL))
                return i;
       }

    return -1;
};
bool Network::directtLine(int lineId, int stn1Id, int stn2Id)
{
    LineStationData station1, station2;
    station1.stnId = stn1Id;
    station2.stnId = stn2Id;
    bool found = false;
    for (int i = 0; !found && i < this->nbLines; i++){
       if(lines[i].getLineNb() == lineId){
            found = true;
            if((lines[i].getStationsList()->findById(station1) != NULL) && (lines[i].getStationsList()->findById(station2) != NULL))
                return true;
       }
    }
    return false;
};
//The function returns the distance between two stations in terms of actual distance
float Network::distance(int line,int sstation1,int sstation2)
{
     LineStationData station1, station2;
    station1.stnId = sstation1;
    station2.stnId = sstation2;
    float dif= lines[line].getStationsList()->findById(station2)->data.distance - lines[line].getStationsList()->findById(station1)->data.distance;

    if(dif<0) dif=-dif;
    return dif;
};
//finds the shortest path from some station to another
List<LineStationData> Network::shortestPath()
{
    ///#################-->> not used
};
Line* getSubLine()
{
    ///#################-->> not used
};
//Displays all line information traversing lines in the forward direction
void Network::displayLinesForward(Stations& stations) {
    Line* lns=this->lines;
	cout << "All Network Information...\n"<< endl;
	cout <<"Number of lines: " << this->nbLines<< endl;
	cout << "All line information" << endl;
	for(int i=0; i < this->nbLines; i++)
		lns[i].traverseForward(stations);
}
void Network::displayLinesBackward(Stations& stations)
{
    Line* lns=this->lines;
	cout <<"All Network Information...\n"<< endl;
	cout <<"Number of lines: " << this->nbLines<< endl;
	cout <<"All line information" << endl;
	for(int i=0; i< this->nbLines; i++)
		lns[i].traverseBackward(stations);
};


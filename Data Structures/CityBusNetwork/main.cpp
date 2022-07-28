#include <bits/stdc++.h>
#include "Line.h"
#include "Network.h"
/**
Name: Surafel Fantu ID: VN2703
      Elias Taye     ID:WB1973
*/
using namespace std;
bool build(Stations& stations, Network& network){
    if(stations.buildStations("station.txt") !=2  || network.buildNetwork("network.txt") !=2){
		cout <<"Unable to build network. Possible reason is your disk may be malfunctioning or the system may not have enough memory.";
		system("pause");
		return false;
	}
	return true;
}
int main()
{
    Stations stations;
	Network network;
	Line line;
	if(!build(stations, network))
        return 0;
	int choice,id;
    do{
        cout<<"1. Network Information\n";
        cout<<"2. Edit Network\n";
        if(network.getStatus()){
            cout<<"3. Network Changed. Save Changes\n";
            cout<<"4. Undo All Changes\n";
        }
        cout<<"5. Exit\n";
        cout<<"Choice: ";
        cin>>choice;
        system("cls");
        switch(choice){
        case 1:{
            do{
                cout<<"1. All Network Information\n";
                cout<<"2. Line Information\n";
                cout<<"3. Station Information\n";
                cout<<"4. Shortest Path Information\n";
                if(network.getStatus()){
                    cout<<"5. Network Changed. Save Changes\n";
                    cout<<"6. Undo All Changes\n";
                }
                cout<<"7. Back To Main Switch Board\n";
                cout<<"8. Exit\n";
                cout<<"Choice: ";
                cin>>choice;
                system("cls");
                if(choice == 1){
                    cout<<"1. Displaying All Network Information in Forward Direction\n";
                    cout<<"#. Displaying All Network Information in Backward Direction\n";
                    cout<<"Choice: ";
                    cin>>id;
                    system("cls");
                    (id == 1)?network.displayLinesForward(stations):network.displayLinesBackward(stations);
                }
                else if(choice == 2){
                    //line info
                    system("cls");
                    cout<<" Displaying Line Information."<<endl;
                    cout<<"Line Id: ";
                    cin>>id;
                    int linePosition = network.findLine(id);
                    system("cls");
                    if(linePosition != -1){
                        cout<<"Displaying line number/Id, number of stations, and each station's Id and name in the chosen line's.\n";
                        network.getLines()[linePosition].traverseForward(stations);
                    }
                    else{
                        cout<<"Line is not found!!!\n";
                    }
                }
                else if(choice == 3){
                    system("cls");
                    cout<<" Displaying Stations Information.\n";
                    stations.displayStations();
                }
                else if(choice == 4){
                    //shortest path info
                    system("cls");
                    int station1,station2;
                    cout<<"Please enter the start station Id: ";
                    cin>>station1;
                    cout<<"Please enter the destination station Id: ";
                    cin>>station2;
                    //network.shortestPath(startStation,stopStation);
                    //first  check if the stations even exist
                    //checking for shortest path
                    int line=network.directLine(station1 ,station2);
                    if(line!=-1){
                    //do something
                    cout<<"A direct route exists from station "<<stations.mapStation(station1)<<" to station "<<stations.mapStation(station2)
                    <<"\nwith a travel distance of " <<network.distance(line,station1,station2)<<" K.M";
                    }
                     //check for two lines
                    else if(line == -1){
                        int nbLines = network.nbLinesPerStation(station1);
                        bool found=false;
                        for(int i=0;i < nbLines&&!found;i++){
                            Line l;network.LineThroughStation(station1,i,l);

                            //for each stationm here
                            List<LineStationData>* si=l.getStationsList();
                            Node<LineStationData> * lsd=si->getFront();
                            while(lsd!=NULL){

                                if(network.directtLine(l.getLineNb(),lsd->data.stnId,station2)){
                                        float dist=network.distance(network.directLine(station1,lsd->data.stnId),station1,lsd->data.stnId)+network.distance(network.directLine(lsd->data.stnId,station2),lsd->data.stnId,station2);
                                    cout<<"THERE IS A TWO WAY Line first travel from station "<<stations.mapStation(station1)<<" to station "<<stations.mapStation(lsd->data.stnId)
                                    <<" and then from there take another bus to station "<<stations.mapStation(station2)<<" the total distance is "<<dist<<" K.M";
                                    found=true;
                                    break;
                                }
                                lsd=lsd->next;
                            cout<<"I AM HERE";
                            }
                        }
                        if(!found){
                        cout<<"no route to station";
                    }

                     }

                    cout<<endl<<endl;
                    //check for a route in a single line
                }
                else if(choice == 5 && network.getStatus()){
                    //net changed. save changes
                    fstream ofnetwork("network.txt",ios::in);
                    network.save(ofnetwork,"network.txt");
                    ofnetwork.close();
                    fstream ofstation("station.txt", ios::in);
                    stations.save(ofstation,"station.txt");
                    ofstation.close();
                    build(stations, network);
                    choice = 0;
                    network.setStatus(false);
                }
                else if(choice == 6 && network.getStatus()){
                    //undo all changes
                    build(stations, network);
                    network.setStatus(false);
                }
                else if(choice == 7){
                    //back to main switch board
                    choice = -1;
                }
                else if(choice == 8){
                    //exit
                    choice = 5;
                }
                else{
                    system("cls");
                    cout<<"wrong choice!!!\n";
                }
            }while(choice != -1 && choice != 5);
            system("cls");
        }
            break;
        case 2:{
            do{
                cout<<"1. Introduce A New Station\n";
                cout<<"2. Change Station Name\n";
                cout<<"3. Change Station Number\n";
                cout<<"4. Insert A New Station On A Line\n";
                cout<<"5. Delete Station From Line\n";
                cout<<"6. Delete Station From Network\n";
                cout<<"7. Introduce A New Line\n";
                cout<<"8. Change Line Number\n";
                cout<<"9. Delete A Line\n";
                if(network.getStatus()){
                    cout<<"10. Network Changed. Save Changes\n";
                    cout<<"11. Undo All Changes\n";
                }
                cout<<"12. Back To Main Switch Board\n";
                cout<<"13. Exit\n";
                cout<<"Choice: ";
                cin>>choice;
                system("cls");
                if(choice == 1){
                    //Introduce A New Station
                    bool added = false;
                    do{
                        system("cls");
                        StationIdentifier newStation;
                        cout<<"Introducing a new station..."<<endl;
                        cout<<"Station Id: ";
                        cin>>newStation.stnId;
                            if(stations.findStation(newStation.stnId) == -1){
                                cout<<"Station Name: ";
                                cin>>newStation.name;
                                added = stations.addStation(newStation.stnId, newStation.name);
                            }
                            else{
                                cout<<"Choose another Id...\n";
                                system("pause");
                            }
                    }while(!added);
                }
                else if(choice == 2){
                    //Change Station Name
                    system("cls");
                    cout<<"Station Id whose name should be changed: ";
                    cin>>id;
                    int position = stations.findStation(id);
                    if(position != -1){
                        string newName;
                        cout<<"You are changing "<<stations.mapStation(id)<<" into: ";
                        cin>>newName;
                        stations.editStationName(newName, position);
                        network.setStatus(true);
                    }else{
                        cout<<"Station is not found!!!\n";
                    }
                }
                else if(choice == 3){
                    //Change Station Number
                    system("cls");
                    cout<<"Station Id whose Id should be changed: ";
                    cin>>id;
                    int position = stations.findStation(id);
                    if(position != -1){
                        int newId,check;
                        do{
                            system("cls");
                            cout<<"You are changing "<<stations.mapStation(id)<<"'s Id into: ";
                            cin>>newId;
                            if(stations.findStation(newId) == -1)
                                check = -1;
                            else{
                                cout<<"Choose another Id...\n";
                                system("pause");
                            }
                        }while(check != -1);
                        stations.editStationNumber(newId, position);
                        int numberOfLines = network.getNbLines();
                        LineStationData lsd;
                        lsd.stnId = id;;
                        Node<LineStationData>* temp;
                        for(int i = 0; i < numberOfLines; i++){
                            temp = network.getLines()[i].getStationsList()->findById(lsd);
                            if(temp != NULL){
                                temp->data.stnId = newId;
                                network.setStatus(true);
                            }
                        }
                    }else{
                        cout<<"Station is not found!!!\n";
                    }
                }
                else if(choice == 4){
                    //Insert A New Station On A Line
                    system("cls");
                    cout<<"Adding a new station to line: ";
                    cin>>id;
                    int linePosition = network.findLine(id);
                    if(linePosition != -1){
                        cout<<"Station Id: ";
                        cin>>id;
                        int stationPosition = stations.findStation(id);
                        LineStationData stn;
                        stn.stnId=id;
                        if(network.getLines()[linePosition].getStationsList()->findById(stn) == NULL){
                            if(stationPosition != -1){
                                LineStationData newStation;
                                newStation.stnId = id;
                                cout<<"Distance from the beginning: ";
                                cin>>newStation.distance;
                                //network.getLines()[linePosition]
                                if(network.getLines()[linePosition].addStation(newStation))
                                    network.setStatus(true);
                                else{
                                    cout<<"Failed!!!\n";
                                }

                            }else{
                                cout<<"Station is not found!!!\n";
                            }
                        }else{
                            cout<<"Station was added before. Failed to add again!!!\n";
                        }
                    }
                    else{
                        cout<<"Line is not found!!!\n";
                    }
                }
                else if(choice == 5){
                    //Delete Station From Line
                    system("cls");
                    cout<<"Deleting station from line: ";
                    cin>>id;
                    int linePosition = network.findLine(id);
                    if(linePosition != -1){
                        cout<<"Station Id: ";
                        cin>>id;
                        if(network.getLines()[linePosition].deleteStation(id))
                            network.setStatus(true);
                        else{
                            cout<<"Failed!!!\n";
                        }
                    }
                    else{
                        cout<<"Line is not found!!!\n";
                    }
                    choice = -2;
                }
                else if(choice == 6){
                    //Delete Station From Network
                    system("cls");
                    cout<<"Deleting station from the network."<<endl;
                    cout<<"Station Id: ";
                    cin>>id;
                    int numberofLines = network.getNbLines();
                    for(int i = 0; i < numberofLines; i++){
                        if(network.getLines()[i].deleteStation(id))
                            network.setStatus(true);
                        else{
                            cout<<"Failed!!!";
                        }
                    }
                }
                else if(choice == 7){
                    //Introduce A New Line
                    bool added = false;
                    do{
                        system("cls");
                        cout<<"Introducing a new line..."<<endl;
                        cout<<"Line Id: ";
                        cin>>id;
                            if(network.findLine(id) == -1){
                                added = network.addLine(id);
                                network.setStatus(added);
                            }
                            else{
                                cout<<"Choose another Id...\n";
                                system("pause");
                            }
                    }while(!added);
                }
                else if(choice == 8){
                    //Change Line Number
                    system("cls");
                    cout<<"Line Id whose Id should be changed: ";
                    cin>>id;
                    int position = network.findLine(id);
                    if(position != -1){
                        int newId,check;
                        do{
                            system("cls");
                            cout<<"You are changing line id found at position "<<position<<" into: ";
                            cin>>newId;
                            if(network.findLine(newId) == -1)
                                check = -1;
                            else{
                                cout<<"Choose another Id...\n";
                                system("pause");
                            }
                        }while(check != -1);
                        network.editLine(newId, position);
                        network.setStatus(true);
                    }else{
                        cout<<"Line is not found!!!\n";
                    }
                }
                else if(choice == 9){
                    //Delete A line
                    system("cls");
                    cout<<"Deleting a line from the network..."<<endl;
                    cout<<"Line Id: ";
                    cin>>id;
                    int position = network.findLine(id);
                    if(position != -1){
                        network.deleteLine(id);
                        network.setStatus(true);
                    }
                    else{
                        cout<<"Line is not found!!!\n";
                    }
                }
                else if(choice == 10 && network.getStatus()){
                    //Network Changed. Save Changes
                    fstream ofnetwork("network.txt",ios::in);
                    network.save(ofnetwork,"network.txt");
                    ofnetwork.close();
                    fstream ofstation("station.txt", ios::in);
                    stations.save(ofstation,"station.txt");
                    ofstation.close();
                    build(stations, network);
                    network.setStatus(false);
                }
                else if(choice == 11 && network.getStatus()){
                    //Undo All Changes
                    build(stations, network);
                    network.setStatus(false);
                }
                else if(choice == 12){
                    //Back To Main Switch Board
                    choice = -1;
                }
                else if(choice == 13){
                    choice = 5;
                    //Exit
                }
                else{
                    system("cls");
                    cout<<"Wrong choice!!!\n";
                }
            }while(choice != 5 && choice != -1);
            system("cls");
        }
            break;
        case 3:{
            //Network Changed. Save Changes
            if(network.getStatus()){
                fstream ofnetwork("network.txt",ios::in);
                network.save(ofnetwork,"network.txt");
                ofnetwork.close();
                fstream ofstation("station.txt", ios::in);
                stations.save(ofstation,"station.txt");
                ofstation.close();
                build(stations, network);
                network.setStatus(false);
            }
        }
            break;
        case 4:{
            //Undo All Changes
            if(network.getStatus()){
                build(stations, network);
                network.setStatus(false);
            }
        }
            break;
        case 5:
            //exit
            break;
        default:
            cout<<"Wrong choice!!!\n";
            break;
        }
    }while(choice != 5);
    fstream ofnetwork("network.txt",ios::in);
    network.save(ofnetwork,"network.txt");
    ofnetwork.close();
    fstream ofstation("station.txt", ios::in);
    stations.save(ofstation,"station.txt");
    ofstation.close();
    cout<<"***********Farewell!!!***********\n";
    system("pause");
	return 0;

}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 21, 2021, 12:42 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
using namespace std;


class ISmartAppliance{
public:
    virtual void turnOn()=0;
    virtual void turnOff()=0;
};


class SmartDevice: public ISmartAppliance{
private:
    string name;
public:
    SmartDevice(string aName){
        name = aName;
    }
    void turnOn(){
        cout<<endl<<"Turning On Device "<< name;
    }
    void turnOff(){
        cout<<endl<<"Turning Off Device "<< name;
    }
};

class ICommand{

public:
    virtual void execute()=0;
};

class TurnOnCommand:public ICommand{
private:
    ISmartAppliance* device;
public:
    TurnOnCommand(ISmartAppliance* aDevice){
        device=aDevice;
    }
    void execute() {
        device->turnOn();
    }
};


class TurnOffCommand: public ICommand{
private:
    ISmartAppliance* device;
public:
    TurnOffCommand(ISmartAppliance* aDevice){
        device=aDevice;
    }
    void execute() {
        device->turnOff();
    }
};



class RemoteControl{
private:
    map<int,ICommand*> slots;
public:
    void setCommand(int aSlotId, ICommand* aCommand){
        slots[aSlotId] = aCommand;
    }
    void initiateAction(int aSlotId){        
        if(slots.find(aSlotId)!= slots.end()){
            slots[aSlotId]->execute();
        }
        else{
            cout<<endl<<"There is no command associated with this slot..";
        }
   }
};

/*
 * 
 */
int main(int argc, char** argv) {

    //Create the devices
    SmartDevice* smartLight = new SmartDevice("SmartLight");
    SmartDevice* smartTV = new SmartDevice("SmartTV");
    SmartDevice* roomHeater = new SmartDevice("Room Heater");
    SmartDevice* ac = new SmartDevice("AC");
    SmartDevice* soundBar = new SmartDevice("Sound bar");
    
    
    
    //Lets create the RemoteControl
    RemoteControl *rmtCtrl = new RemoteControl();
   
    //Create the Commands and set the slots on the remote control to this commands
 
    //On And Off command for the Smart Light
    ICommand *trnOnLightCmd = new TurnOnCommand(smartLight);
    ICommand *trnOffLightCmd = new TurnOffCommand(smartLight);
    //1 - Smart Light Turn on
    //2 - Smart Light Turn off
    rmtCtrl->setCommand(1, trnOnLightCmd);
    rmtCtrl->setCommand(2, trnOffLightCmd);
    

    //On And Off command for the Smart Light
    ICommand *trnOnSmartTVCmd = new TurnOnCommand(smartTV);
    ICommand *trnOffSmartTVCmd = new TurnOffCommand(smartTV);
    //3-Smart TV Turn on
    //4- Smart Tv Turn off
    rmtCtrl->setCommand(3, trnOnSmartTVCmd);
    rmtCtrl->setCommand(4, trnOffSmartTVCmd);    
    
    
    //On And Off command for the roomHeater
    ICommand *trnOnroomHeaterCmd = new TurnOnCommand(roomHeater);
    ICommand *trnOffroomHeaterCmd = new TurnOffCommand(roomHeater);
    //5-Room Heater Turn on
    //6-Room Heater Turn off
    rmtCtrl->setCommand(5, trnOnroomHeaterCmd);
    rmtCtrl->setCommand(6, trnOffroomHeaterCmd);    
    
    //On And Off command for the AC
    ICommand *trnOnacCmd = new TurnOnCommand(ac);
    ICommand *trnOffacCmd = new TurnOffCommand(ac);
    //7-AC Turn on
    //8-AC Turn off
    rmtCtrl->setCommand(7, trnOnacCmd);
    rmtCtrl->setCommand(8, trnOffacCmd);    
    
        //On And Off command for the SmartSoundBar
    ICommand *trnOnSmartSoundBarCmd = new TurnOnCommand(soundBar);
    ICommand *trnOffSmartSoundBarCmd = new TurnOffCommand(soundBar);
    //9-Soundbar Turn on
    //10- Soundbar Turn off
    rmtCtrl->setCommand(9, trnOnSmartSoundBarCmd);
    rmtCtrl->setCommand(10, trnOffSmartSoundBarCmd);   
    
    int choice =1;
    while(1){
        cout<<endl<<"!!!! Remote control Menu !!!!";
        
        cout<<endl<<"1 - Smart Light Turn on";
        cout<<endl<<"2 - Smart Light Turn off";
        
        cout<<endl<<"3-Smart TV Turn on";
        cout<<endl<<"4-Smart TV Turn off";
        
        cout<<endl<<"5-Room Heater Turn on";
        cout<<endl<<"6-Room Heater Turn off";
        
        cout<<endl<<"7-AC Turn on";
        cout<<endl<<"8-AC Turn off";
        
        cout<<endl<<"9-Soundbar Turn on";
        cout<<endl<<"9-Soundbar Turn off";
        
        cout<<endl<<"0-to Exit";
        
        cout<<endl<<" Your choice :: ";
        cin>> choice;
        if(choice ==0){
            break;
        }
        rmtCtrl->initiateAction(choice);
    
    }
    //cleanup
    
    delete trnOnSmartSoundBarCmd;
    delete trnOffSmartSoundBarCmd;
    
    delete trnOnacCmd;
    delete trnOffacCmd;
    
    delete trnOnroomHeaterCmd;
    delete trnOffroomHeaterCmd;
    
    
    delete trnOnSmartTVCmd;
    delete trnOffSmartTVCmd;
    
    delete trnOnLightCmd;
    delete trnOffLightCmd;
    
    delete smartLight;
    delete smartTV;
    delete roomHeater;
    delete ac;
    delete soundBar;
    
    delete rmtCtrl;
    return 0;
}


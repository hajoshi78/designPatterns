/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 16, 2021, 10:40 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//the implementation
class IAppliance{
public:
    virtual void run()=0;
};

//the abstraction
class Switch{
protected:
    IAppliance *appliance;
public:
    virtual void turnOn()=0;
};



//concrete abstraction
class RemoteControl : public Switch{
public :
    RemoteControl(IAppliance *i){
        appliance = i;
    }

    virtual void turnOn(){
        appliance->run();
    }
};

//concrete implementation
class TV : public IAppliance{
private:
    string name;

public:
    TV(string aName){
        name = aName;
    }

    virtual void run(){
        cout<<endl<<name << " is running";
    }
};

//concrete implementation
class VaccumCleaner : public IAppliance{
    private:
        string name;

public:
    VaccumCleaner(string aName){
        name = aName;
    }

    virtual void run()
    {
        cout<<endl<<name << " is running";
    }
};

//convert implementation object to abstraction object
Switch* GetSwitch(IAppliance *a){
    return new RemoteControl(a);
}
int main(){
    IAppliance *tv = new TV("Bedroom TV");  //implementation object
    IAppliance *vacuum = new VaccumCleaner
    ("My Vacuum Cleaner");  //implementation object

    Switch *s1 = GetSwitch(tv);  //convert to abstraction
    Switch *s2 = GetSwitch(vacuum);  //convert to abstraction

    //*** client code works only with the abstraction objects,
    //not the implementation objects ***
    s1->turnOn();
    s2->turnOn();
   
    delete s1;
    delete s2;
    delete tv;
    delete vacuum;
    return 0;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 21, 2021, 12:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

enum eventType{
    valueChanged=0
};

//This class encapsulates the Event Object.
//The idea is to make the event Object Generic Enough 
//to use it in any of the event 
class Event{
private:
    void* _eventData;
    int _eventType;
public:
    Event(int aEventType, void* aEventObj){
        _eventType = aEventType;
        _eventData = aEventObj;
    }
    void* getEventData(){
        return (void*) _eventData;
    }
    int  eventType(){
        return _eventType;
    }
};

//Interface exposed by the subject...  Observers will implement this interface
// Whenever there is a change in the subject all Observer's onChange method is invoked
class INotify{
public:
    virtual void onChange(Event *aEventObj)=0;
};



//This is the subject class. 
//Subject is the place where data model is present
//Whenever there is change in the data model,  observers need to be notified
//Subject keeps a list of the Observers.
//Observers register with the subject using the register method
class Subject{
private:
    vector<INotify*> observers;
    int data;
    
    void notifyAllObservers(){
        Event *evt = new Event( eventType::valueChanged,&data);
        for(auto x: observers){
           x->onChange(evt);
        }
    }
public:
    void registerObserver(INotify* aObserver){
        if(aObserver){
            observers.push_back(aObserver);
        }
    }
    void unRegisterObserver(INotify* aObserver){
        int count=0;
        for(auto x: observers){
            if( x== aObserver){
                observers.erase(observers.begin()+count);
            }
            count++;
        }
    }
    void setData(int aData){
        data = aData;

    }
};

class Observer: public INotify{
private:
    int id;
public:
    Observer(int aId){
        id  = aId;
    }
    void onChange(Event* aEventObj){
        cout<<endl<<"Received Event ...Observer id "<< id<< " Event Type: "<< aEventObj->eventType() << " EventData :" <<*((int*)aEventObj->getEventData());
    } 
};
/*
 * 
 */
int main(int argc, char** argv) {
    Subject* subj = new Subject();
    
    Observer* ob1 = new Observer(1);
    subj->registerObserver(ob1);
    
    Observer* ob2 = new Observer(2);
    subj->registerObserver(ob2);
       
    subj->setData(100);
   
    
    delete ob2;
    delete ob1;
    delete subj;
    
    
    return 0;
}


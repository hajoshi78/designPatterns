/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 26, 2021, 8:43 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

class HouseTemplate{
public:
    virtual void layFoundation(){
        cout<<endl<<"Laying foundation  with 6 feet depth";
    }
    virtual void erectPillars()=0;
    virtual void buildWalls()=0;
    virtual void  doRoofing()=0;
    virtual void addDoorsAndWindows()=0;
    virtual void doElectricalWork()=0;
    virtual void doPlumbingWork()=0;
    virtual void doPainting()=0;
    //template Method
    void buildHouse(){
        layFoundation();
        erectPillars();
        buildWalls();
        doRoofing();
        addDoorsAndWindows();
        doElectricalWork();
        doPlumbingWork();
        doPainting();
    }
};

class WoodenHouse: public HouseTemplate{
public:
    void erectPillars(){
        cout <<endl<<"building pillars with wood coating";
    }
    void  buildWalls(){
        cout <<endl<<"building walls  with wooden sheets";
    }
    void  doRoofing(){
        cout <<endl<<"Adding Wooden Frames for Room and Putting Wooden Roofs";
    }
    void addDoorsAndWindows(){
        cout <<endl<<"Adding Alumunium frame Sliding windows and wooden Doors";
    }
    void doElectricalWork(){
        cout <<endl<<"Doing electric work with Anchor Roma Fittings and K2 Cable Wiring";
    }
    void doPlumbingWork(){
        cout <<endl<<"Doing Plumbing work with Jaguar Fittings ";
    }
    void doPainting(){
        cout <<endl<<"Doing painting with Asian Paints color";
    }
};

class BrickAndConcreteHouse: public HouseTemplate{
public:
    
    void layFoundation(){
        cout<<endl<<"Laying foundation  with 10 feet depth";
    }
    void erectPillars(){
        cout <<endl<<"building pillars with wood coating";
    }
    void  buildWalls(){
        cout <<endl<<"building walls  with Brick and Cement and plastering";
    }
    void  doRoofing(){
        cout <<endl<<"Adding Beams and then putting Concrete Roof";
    }
    void addDoorsAndWindows(){
        cout <<endl<<"Adding Teak Wood frame and Glass shutters and wooden Doors";
    }
    void doElectricalWork(){
        cout <<endl<<"Doing electric work with Havells Fittings and K2 Cable Wiring";
    }
    void doPlumbingWork(){
        cout <<endl<<"Doing Plumbing work with Rocca Fittings ";
    }
    void doPainting(){
        cout <<endl<<"Plastering with Wall care Putty and Doing painting with Nerolac Paints color";
    }
};



/*
 * 
 */
int main(int argc, char** argv) {

    HouseTemplate *houseType = new WoodenHouse();
		
    //using template method
    houseType->buildHouse();
    cout<<endl<<"!!!!!!!!!!!!!!!************!!!!!!!!!!!!!";

    HouseTemplate* houseType2 = new BrickAndConcreteHouse();
    houseType2->buildHouse();
   
    return 0;
}


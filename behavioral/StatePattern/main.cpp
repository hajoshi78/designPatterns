/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 25, 2021, 7:59 PM
 */

#include <cstdlib>

using namespace std;


class KidState {
public:
    void play()=0;
    void eat()=0;
};


class FirstYearKid:public KidState{
public:
    void play(){
        cout<<endl<<"Play in cradle";
    }
	
    void eat(){
        cout<<endl<<"Drink Milk";
    }
};


class SecondYearKid:public KidState{
public:
    void play(){
        cout<<endl<<"Play with Toys";
    }
	
    void eat(){
        cout<<endl<<"Eat Potatoes and Drink Milk";
    }
};


class ThirdYearKid:public KidState{
public:
    void play(){
        cout<<endl<<"Run and Roll";
    }
	
    void eat(){
        cout<<endl<<"Eat Choclates";
    }
};



class FourthYearKid:public KidState{
public:
    void play(){
        cout<<endl<<"Play Cricket";
    }
	
    void eat(){
        cout<<endl<<"Eat Cakes";
    }
};

class Kid {
private:
        int age;
	KidState kidState;
public:
    Kid(int age){
	this.setAge(age);
    }
	
    void play(){
        kidState.play();
    }
	
    void eat(){
	kidState.eat();
    }
	
    void setAge(int age){
	this.age = age;
        if(age == 1){
                kidState = new FirstYearKid();
        }else if(age ==2){
                kidState = new SecondYearKid();
        }else if(age ==3){
                kidState = new ThirdYearKid();
        }else if(age == 4){
                kidState = new FourthYearKid();
        }else{
                kidState = new FirstYearKid();
        }
    }
};

/*
 * 
 */
int main(int argc, char** argv) {

    Kid *kid = new Kid(2);
    kid->eat();
    kid->play();
    kid->setAge(4);
    kid->eat();
    kid->play();
    return 0;
}



/*
 Client-> Context -----has ---->    <<interface>> State
 *                                      |
 *   <Implements>>                      |
 *                       ------------------------------------
 *                       |                                  |
 *                     ConcreteState1                  ConcreteState2
 *
 * 
 * 
 * 
 * Encapsulates the changing Behavior
 * Any changes to the behaviors based on state will only change the state objects
 * Easy for extensions as we can create any number of state Objects
 * 
 */

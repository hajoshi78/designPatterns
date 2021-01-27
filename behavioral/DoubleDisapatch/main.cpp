/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 26, 2021, 8:50 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
class Cat;
class Dog;
class Animal{
public:
    virtual void makeSound()=0;
    virtual void makeSound(Cat* aCat)=0;
    virtual void makeSound(Dog* aDog)=0;
};

class Dog: public Animal{
public:
    void makeSound(){
        cout<<endl<<" Dog is barking ....";
    }
    void makeSound(Cat* cat){
        cout<<endl<<" Dog is interacting with cat ";
    }
    void makeSound(Dog* dog){
        cout<<endl<<" Dog is interacting with dog ";
    }
};

class Cat: public Animal{
public:
    void makeSound(){
        cout<<endl<<" Cat says meoowwww....";
    }
    void makeSound(Cat* cat){
        cout<<endl<<" Cat is interacting with cat ";
    }
    void makeSound(Dog* dog){
        cout<<endl<<" Cat is interacting with dog ";
    }
};


/*
 * 
 */
int main(int argc, char** argv) {
    Animal* dog= new Dog();
    dog->makeSound();
    
    Animal *cat = new Cat();
    cat->makeSound();
    
    
    dog->makeSound(cat);
    dog->makeSound(dog);
    
    cat->makeSound(dog);
    cat->makeSound(cat);
    
    delete dog;
    delete cat;
    return 0;
}


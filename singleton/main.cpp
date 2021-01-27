/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 16, 2021, 1:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


#include <string>

/*class Logger{
public:
   static Logger* Instance();
   bool openLogFile(std::string logFile);
   void writeToLogFile();
   bool closeLogFile();

private:
   Logger(){};  // Private so that it can  not be called
   Logger(Logger const&){};             // copy constructor is private
   Logger& operator=(Logger const&){};  // assignment operator is private
   static Logger* m_pInstance;
};*/

#include <iostream>
#include <mutex>

using namespace std;

class Singleton {
public:
   // This is how clients can access the single instance
   static Singleton* getInstance();

   void setValue(int val) {value_ = val;}
   int  getValue()           {return(value_);}

protected:
   int value_;

private:
   static Singleton* singletonInstance;   // The one, single instance
   Singleton() : value_(0) {} // private constructor
   Singleton(const Singleton&);
   Singleton& operator=(const Singleton&);
};

// Define the static Singleton pointer
Singleton* Singleton::singletonInstance = NULL;

Singleton* Singleton::getInstance() {
   mutex mtx;
   lock_guard<mutex> lk(mtx, adopt_lock);
   if (singletonInstance == NULL) {
      singletonInstance = new Singleton();
   }
   return(singletonInstance);
}

int main() {

   Singleton* p1 = Singleton::getInstance();
   p1->setValue(10);
   Singleton* p2 = Singleton::getInstance();
   cout << "Value = " << p2->getValue() << '\n';
   
}
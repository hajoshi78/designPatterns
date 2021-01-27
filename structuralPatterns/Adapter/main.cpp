/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 16, 2021, 1:51 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
class Target {
public:
  Target() { std::cout << "Target" << std::endl; }
  virtual ~Target() {};
  virtual void request() = 0;
};

class Adaptee {
public:
  Adaptee() { std::cout << "Adaptee" << std::endl; }
  ~Adaptee() {}

  void specificRequest() { std::cout << "This is specific request" << std::endl; }
};

class Adapter : public Target, private Adaptee {
public:
  Adapter() { std::cout << "Adapter" << std::endl; }
  ~Adapter() {}

  void request() {
    specificRequest();
    std::cout << "This is request" << std::endl;
  }
};

int main() {
  Target *t = new Adapter();
  t->request();
}
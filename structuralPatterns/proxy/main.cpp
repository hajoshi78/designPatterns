/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 16, 2021, 11:36 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

class Subject {
public:
  virtual ~Subject() {}
  virtual void request() = 0;
};

class RealSubject : public Subject {
public:
  void request() {
    std::cout << "RealSubject Request" << std::endl;
  }
};

class Proxy : public Subject
{
public:
  Proxy()
  {
    subject = new RealSubject();
  }

  ~Proxy()
  {
    delete subject;
  }

  void request()
  {
    subject->request();
  }

private:
  RealSubject *subject;
};


int main()
{
  Subject *service = new Proxy();
  service->request();

  delete service;
  return 0;
}
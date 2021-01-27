/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 17, 2021, 12:36 AM
 */

#include <iostream>
#include <string>

class Component {
public:
  virtual ~Component() {}
  virtual void operation() = 0;
};

class ConcreteComponent : public Component {
public:
  ~ConcreteComponent() {}

  void operation() {
    std::cout << "Concrete Component operation" << std::endl;
  }
};

class Decorator : public Component {
public:
  ~Decorator() {}

  Decorator(Component *c) : component_(c) {}

  virtual void operation() {
    component_->operation();
  }
private:
  Component *component_;
};

class ConcreteDecoratorA : public Decorator {
public:
  ConcreteDecoratorA(Component *c) : Decorator(c) {}

  void operation() {
    Decorator::operation();
    std::cout << "AddedBehavior for ConcreteDecoratorA" << std::endl;
  }
};

class ConcreteDecoratorB : public Decorator {
public:
  ConcreteDecoratorB(Component *c) : Decorator(c) {}

  void operation() {
      Decorator::operation();
      std::cout << "AddedBehavior for ConcreteDecoratorB" << std::endl;
  }
};

int main() {
  Component *cc = new ConcreteComponent();
  ConcreteDecoratorA *cda = new ConcreteDecoratorA(cc);
  ConcreteDecoratorB *cdb = new ConcreteDecoratorB(cda);

  cdb->operation();

}
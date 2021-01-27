/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 17, 2021, 12:32 AM
 */

#include <vector>
#include <iostream> 
#include <algorithm> 
#include <functional> 
using namespace std;
 
class Graphic {
public:
  virtual void draw() const = 0;
  virtual void remove(Graphic *g) {}
  virtual void add(Graphic *g) {}
  virtual void getChild(int) {}
  virtual ~Graphic() {}
};
 
class Line : public Graphic {
public:
  void draw() const {
    cout << "Line draw()\n";
  }
};

class Rectangle : public Graphic {
public:
  void draw() const {
    cout << "Rectangle draw() \n";
  }
};

class Text : public Graphic {
public:
  void draw() const {
    cout << "Text draw() \n";
  }
};

// Composite
class Picture : public Graphic {
public:
  void draw() const {
    // for each element in gList, call the draw member function
      for(auto x:gList){
          Graphic* item = x;
          item->draw();
      }
  }
 
  void add(Graphic *aGraphic) {
    gList.push_back(aGraphic);
  }
 
private:
  vector<Graphic*> gList;
};
 
int main()
{
  Line line;
  line.draw();
  Rectangle rect;
  rect.draw();
  Text text;
  text.draw();

  Picture pic;
  pic.add(&line);
  pic.add(&rect);
  pic.add(&text);
  pic.add(&rect);
  pic.draw();

  return 0;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 15, 2021, 2:18 PM
 */

#include <cstdlib>
#include <iostream>
#define __CONCRETE_CREATOR_CLASS
using namespace std;
#ifdef __ABSTRACT_CREATOR_CLASS
    # 1: Factory Method - Abstract Creator Class
    class Button {
    public:
            virtual void paint() = 0;
    };

    class OSXButton: public Button {
    public:
            void paint() {
                    std::cout << "OSX button \n";
            }
    };

    class WindowsButton: public Button  {
    public:
            void paint() {
                    std::cout << "Windows button \n";
            }
    };

    class GUIFactory {
    public:
            virtual Button *createButton(char *) = 0;
    };

    class Factory: public GUIFactory {
    public:
            Button *createButton(char *type) {
                    if(strcmp(type,"Windows") == 0) {
                            return new WindowsButton;
                    }
                    else if(strcmp(type,"OSX") == 0) {
                            return new OSXButton;
                    }
            }
    };

    int main()
    {
            GUIFactory* guiFactory;
            Button *btn;

            guiFactory = new Factory;

            btn = guiFactory->createButton("OSX");
            btn -> paint();
            btn = guiFactory->createButton("Windows");
            btn -> paint();

            return 0;
    }
#endif
#ifdef __CONCRETE_CREATOR_CLASS
#include <iostream>

class Button {
public:
	virtual void paint() = 0;
};
 
class OSXButton: public Button {
public:
	void paint() {
		std::cout << "OSX button \n";
	}
};
 
class WindowsButton: public Button  {
public:
	void paint() {
		std::cout << "Windows button \n";
	}
};
 
class iPhoneButton: public Button {
public:
	void paint() {
		std::cout << "iPhone button \n";
	}
};

class GUIFactory {
public:
	virtual Button *createButton(char *type) {
		if(strcmp(type,"Windows") == 0) {
			return new WindowsButton;
		}
		else if(strcmp(type,"OSX") == 0) {
			return new OSXButton;
		}
		return NULL;
	}
};

class ConcreteFactory: public GUIFactory {
		Button *createButton(char *type) {
		if(strcmp(type,"Windows") == 0) {
			return new WindowsButton;
		}
		else if(strcmp(type,"OSX") == 0) {
			return new OSXButton;
		}
		else if(strcmp(type,"iPhone") == 0) {
			return new iPhoneButton;
		}
	}
};

int main()
{
	GUIFactory* guiFactory;
	Button *btn;

	guiFactory = new ConcreteFactory();

	btn = guiFactory->createButton("OSX");
	btn -> paint();
	btn = guiFactory->createButton("Windows");
	btn -> paint();
	btn = guiFactory->createButton("iPhone");
	btn -> paint();

	return 0;
}
#endif
/*
 Factory Method lets a class defer instantiation to subclasses. To name the method more descriptively, it can be named as Factory and Product Method or Virtual Constructor. The Factory Method is closely related to Abstract Factory and Prototype patterns.

In Factory Method, client knows about abstract base class but not concrete subclass. 
 * Client wants to create an object from abstract class. But the subclass decides which class to instantiate. 
 * This allows us to defer the creation to the subclass. Again, the client doesn't know which subclass or concrete class is used to create the object. The creation is deferred to run-time.

Client knows about abstract base class but not concrete subclass.
Run-time creation of objects.
Subclasses create objects.
 * 
 * 
 * 
 * 
 * 
 In general, we can apply this pattern to the cases:

When the client doesn't know the actual class from which subclass to create the object.
When the client wants to delegate the decision of choosing the concrete class to create the object to one of the subclasses.
When the client wants the subclass to specify the concrete class name from which to create an object.
 * 
 * 
 * 
If we want to create an OSX style button, we can write a code like this:

Button *btn = new OSXButton;
But if we're going to make it work across any platform, we should write a code something similar to this:
Button *btn = guiFactory->createButton();
Because guiFactory is an instance of Factory class, the createButton() returns a new instance of OSX style button after selecting appropriate button to create. The Factory itself is a subclass of GUIFactory which is an abstract class where general interface for widgets.
So, the product objects here, are widgets.
The instance variable guiFactory is initialized as:
GUIFactory *guiFactory = new Factory;  
 * 
 * 
 * 
 */
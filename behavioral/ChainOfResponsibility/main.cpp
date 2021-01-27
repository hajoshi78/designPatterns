/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 26, 2021, 12:35 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;


class Currency {
private:
    int amount;
public:
    Currency(int amt){
        this->amount=amt;
    }
	
    int getAmount(){
	return this->amount;
    }
};


class DispenseHandler {
public:
    virtual void setNextHandler(DispenseHandler* nextChain)=0;
	
    virtual void dispense(Currency* cur)=0;
};


class FiftyRupeeDispenser:public DispenseHandler {
private:
    DispenseHandler* nextHandler;
public:	
    void setNextHandler(DispenseHandler* nextChain) {
		this->nextHandler=nextChain;
	}
    void dispense(Currency* cur) {
        if(cur->getAmount() >= 50){
                int num = cur->getAmount()/50;
                int remainder = cur->getAmount() % 50;
                cout<<endl<<"Dispensing "<<num<< " 50 Rs  note";
                if(remainder !=0) this->nextHandler->dispense(new Currency(remainder));
        }else{
                this->nextHandler->dispense(cur);
        }
    }
};

class TwentyRupeeDispenser:public DispenseHandler {
private:
    DispenseHandler* nextHandler;
public:	
    void setNextHandler(DispenseHandler* nextChain) {
		this->nextHandler=nextChain;
	}
    void dispense(Currency* cur) {
        if(cur->getAmount() >= 20){
                int num = cur->getAmount()/20;
                int remainder = cur->getAmount() % 20;
                cout<<endl<<"Dispensing "<<num<< " 20 Rs  note";
                if(remainder !=0) this->nextHandler->dispense(new Currency(remainder));
        }else{
                this->nextHandler->dispense(cur);
        }
    }
};

class TenRupeeDispenser:public DispenseHandler {
private:
    DispenseHandler* nextHandler;
public:	
    void setNextHandler(DispenseHandler* nextChain) {
        this->nextHandler=nextChain;
    }
    void dispense(Currency* cur) {
        if(cur->getAmount() >= 10){
                int num = cur->getAmount()/10;
                int remainder = cur->getAmount() % 10;
                cout<<endl<<"Dispensing "<<num<< " 10 Rs  note";
                if(remainder !=0) this->nextHandler->dispense(new Currency(remainder));
        }else{
                this->nextHandler->dispense(cur);
        }
    }
};

class ATMDispenser{
private:
    DispenseHandler* baseHandler;
    DispenseHandler* getBaseHandler(){
        return baseHandler;
    }
public:
    ATMDispenser(){
        baseHandler = new FiftyRupeeDispenser();
        DispenseHandler* subHandler1 = new TwentyRupeeDispenser();
        DispenseHandler* subHandler2 = new TenRupeeDispenser();
        
        baseHandler->setNextHandler(subHandler1);
        subHandler1->setNextHandler(subHandler2);
    }
   
    void dispenseMoney(Currency * cur){
        getBaseHandler()->dispense(cur);
    }
};
/*
 * 
 */
int main(int argc, char** argv) {
    ATMDispenser * atm = new ATMDispenser();
    while(true){
        int amount =0;
        cout<<endl<<"Enter the amount to be dispensed ::";
        cin>>amount;
        if(amount == -1){
            break;
        }
        if(amount%10!=0){
            cout<<endl<<"Please enter amount in multiple of 10";
            continue;
        }
        else{
            atm->dispenseMoney(new Currency(amount));
        }
    }
    return 0;
}


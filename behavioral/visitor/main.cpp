/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 25, 2021, 11:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class CreditCard;
class OfferVisitor{
public:
    virtual void visitBronzeCC(CreditCard* cc)=0;
    virtual void visitSilverCC(CreditCard* cc)=0;
    virtual void visitGoldCC(CreditCard* cc)=0;
};

class CreditCard{

public:
    virtual string getName()=0;
    virtual void accept(OfferVisitor* oVisitor)=0;
};

class BronzeCC: public CreditCard{
private:
    string name;
public: 
    BronzeCC(){
        name = "Bronze";
    }
    void accept(OfferVisitor* oVisitor){
        oVisitor->visitBronzeCC(this);
    }
    string getName(){
        return name;
    }
};


class SilverCC: public CreditCard{
private:
    string name;
public: 
    SilverCC(){
        name = "Silver";
    }
    void accept(OfferVisitor* oVisitor){
        oVisitor->visitSilverCC(this);
    }
    string getName(){
        return name;
    }
};

class GoldCC: public CreditCard{
private:
    string name;
public: 
    GoldCC(){
        name = "Gold";
    }
    void accept(OfferVisitor* oVisitor){
        oVisitor->visitGoldCC(this);
    }
    string getName(){
        return name;
    }
};

class FuelOffer:public OfferVisitor{
public:
    void visitBronzeCC(CreditCard* cc){
        cout<<endl<<"Offering a discount of 1% on Fuel offer on Bronze CC";
    }
    void visitSilverCC(CreditCard* cc){
        cout<<endl<<"Offering a discount of 2% on Fuel Offer on Silver CC";
    }
    void visitGoldCC(CreditCard* cc){
        cout<<endl<<"Offering a discount of 3% on Fuel Offer on Gold CC";
    }
};


class HotelOffer:public OfferVisitor{
public:
    void visitBronzeCC(CreditCard* cc){
        cout<<endl<<"Offering a discount of 5% on HOtel offer on " << cc->getName();
    }
    void visitSilverCC(CreditCard* cc){
        cout<<endl<<"Offering a discount of 10% on Hotel Offer on "<< cc->getName();
    }
    void visitGoldCC(CreditCard* cc){
        cout<<endl<<"Offering a discount of 15% on Hotel Offer on " <<cc->getName();
    }
};
/*
 * 
 */
int main(int argc, char** argv) {

    OfferVisitor* hotelOffer = new HotelOffer();
    CreditCard* sc = new SilverCC();
    sc->accept(hotelOffer);
    
    CreditCard* gc = new GoldCC();
    gc->accept(hotelOffer);
    
    OfferVisitor* fuelOffer = new FuelOffer();
    gc->accept(fuelOffer);
    return 0;
}


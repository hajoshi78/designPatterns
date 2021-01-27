/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 26, 2021, 1:18 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum ChannelTypeEnum {
    ENGLISH=0, 
    HINDI, 
    FRENCH, 
    ALL
};


class Channel {
private:
    double frequency;
    ChannelTypeEnum TYPE;
	
public:
    Channel(double freq, ChannelTypeEnum type){
	this->frequency=freq;
	this->TYPE=type;
    }
    double getFrequency() {
            return frequency;
    }
    ChannelTypeEnum getTYPE() {
        return TYPE;
    }	
    void showChannelInfo(){
        cout<<endl<< "Frequency="<<this->frequency<<", Type="<<this->TYPE;
    }
	
};

class ChannelIterator {
public :
    virtual bool hasNext()=0;
    virtual Channel* next()=0;
};
class ChannelCollection {
public:    
    virtual void addChannel(Channel *c)=0;
    virtual void removeChannel(Channel* c)=0;
    virtual ChannelIterator* iterator(ChannelTypeEnum type)=0;	
};


class ChannelIteratorImpl: public ChannelIterator {

private:
    ChannelTypeEnum type;
    vector<Channel*> *channels;
    int position;

public:
    ChannelIteratorImpl(ChannelTypeEnum ty,vector<Channel*> *channelsList) {
            this->type = ty;
            this->channels = channelsList;
            position =0;
    }

    bool hasNext() {
        while (position < channels->size()) {
            Channel *c = (*channels)[position];
            if (c->getTYPE()==type || type==ChannelTypeEnum::ALL) {
                return true;
            } else
                position++;
        }
        return false;
    }
    Channel* next() {
        Channel* c = (*channels)[position];
        position++;
        return c;
    }
};
class ChannelCollectionImpl: public  ChannelCollection {
private:
    vector<Channel*> *channelsList;

public:
    ChannelCollectionImpl() {
        channelsList = new vector<Channel*>();
    }

    void addChannel(Channel* c) {
        channelsList->push_back(c);
    }

    void removeChannel(Channel* c) {
        int count =0;
        for( auto x: *channelsList){
            if(x==c){
                channelsList->erase(channelsList->begin()+ count);
            }
            count++;
        }
    }

    ChannelIterator* iterator(ChannelTypeEnum type) {
        return new ChannelIteratorImpl(type, channelsList);
    }
};
/*
 * 
 */

ChannelCollection* populateChannels() {
    ChannelCollection *channels = new ChannelCollectionImpl();
    channels->addChannel(new Channel(98.5, ChannelTypeEnum::ENGLISH));
    channels->addChannel(new Channel(99.5, ChannelTypeEnum::HINDI));
    channels->addChannel(new Channel(100.5, ChannelTypeEnum::FRENCH));
    channels->addChannel(new Channel(101.5, ChannelTypeEnum::ENGLISH));
    channels->addChannel(new Channel(102.5, ChannelTypeEnum::HINDI));
    channels->addChannel(new Channel(103.5, ChannelTypeEnum::FRENCH));
    channels->addChannel(new Channel(104.5, ChannelTypeEnum::ENGLISH));
    channels->addChannel(new Channel(105.5, ChannelTypeEnum::HINDI));
    channels->addChannel(new Channel(106.5, ChannelTypeEnum::FRENCH));
    return channels;
}



int main(int argc, char** argv) {
    ChannelCollection* channels = populateChannels();
    ChannelIterator* baseIterator = channels->iterator(ChannelTypeEnum::ALL);
    while (baseIterator->hasNext()) {
        Channel* c = baseIterator->next();
        c->showChannelInfo();
    }
    cout<<endl<<"******";
    // Channel Type Iterator
    ChannelIterator* englishIterator = channels->iterator(ChannelTypeEnum::ENGLISH);
    while (englishIterator->hasNext()) {
        Channel *c = englishIterator->next();
        c->showChannelInfo();
    }
    
    //Lazy you...
    //Delete all the pointers here.. or at least use smart /auto pointers
}


//
// Created by thomas on 28/04/19.
//

#include <iostream>
#include "includes/VM.hpp"
#include "includes/AbstractFactory.hpp"
#include "includes/Globals.hpp"

using namespace std;

// init and synchronise the DataStore
void VM_1::init() {
    ds = (DS_1 *) (af->createDS());
    cout<<"VM_1 : init"<<endl;
}// end init

void VM_2::init() {
    ds = (DS_2 *) (af->createDS());
    cout<<"VM_2 : init"<<endl;
}// end init


/*
 * VM_1 OPERATIONS
 */

//create
void VM_1::create(int p) {
    ds->setTempPrice(p);
#ifdef DEBUG_MODE
    cout<<"VM_1 : create"<<endl;
#endif
    mda->create();
}// end create

//coin
void VM_1::coin(int v) {
    ds->setTempValue(v);
#ifdef DEBUG_MODE
    cout<<"VM_1 : coin"<<endl;
#endif
    if(ds->getPrice() <= ds->getCoins()+v){
        mda->coin(1);
    }else{
        mda->coin(0);
    }
}// end coin

//card
void VM_1::card(float x) {
#ifdef DEBUG_MODE
    cout<<"VM_1 : card"<<endl;
#endif
    if(ds->getPrice() <= x){
        mda->card();
    }else{
        cout<<"Transaction Cancelled : Not Enough Money"<<endl;
    }
}// end card

//sugar
void VM_1::sugar() {
#ifdef DEBUG_MODE
    cout<<"VM_1 : sugar"<<endl;
#endif
    mda->additive(SUGAR_ID);
}// end sugar

//tea
void VM_1::tea() {
#ifdef DEBUG_MODE
    cout<<"VM_1 : tea"<<endl;
#endif
    mda->dispose_drink(TEAD_ID);
}// end tea

//chocolate
void VM_1::chocolate() {
#ifdef DEBUG_MODE
    cout<<"VM_1 : chocolate"<<endl;
#endif
    mda->dispose_drink(CHOCOLATE_ID);
}// end chocolate

//insert_cups
void VM_1::insert_cups(int n_n) {
#ifdef DEBUG_MODE
    cout<<"VM_1 : insert_cups"<<endl;
#endif
    mda->insert_cups(n_n);
}// end insert_cups

//set_price
void VM_1::set_price(int p) {
#ifdef DEBUG_MODE
    cout<<"VM_1 : set_price"<<endl;
#endif
    ds->setTempPrice(p);
    mda->set_price();
}// end set_price

//cancel
void VM_1::cancel() {
#ifdef DEBUG_MODE
    cout<<"VM_1 : cancel"<<endl;
#endif
    mda->cancel();
}// end cancel

/*
 * VM_2 OPERATIONS
 */

//create
void VM_2::CREATE(float p) {
    ds->setTempPrice(p);
#ifdef DEBUG_MODE
    cout<<"VM_2 : CREATE"<<endl;
#endif
    mda->create();
}// end create

//coin
void VM_2::COIN(float v) {
    ds->setTempValue(v);
#ifdef DEBUG_MODE
    cout<<"VM_2 : COIN"<<endl;
#endif
    if(ds->getPrice() <= ds->getCoins()+v){
        mda->coin(1);
    }else{
        mda->coin(0);
    }
}// end coin

//sugar
void VM_2::SUGAR() {
#ifdef DEBUG_MODE
    cout<<"VM_2 : SUGAR"<<endl;
#endif
    mda->additive(SUGAR_ID);
}// end sugar

//cream
void VM_2::CREAM() {
#ifdef DEBUG_MODE
    cout<<"VM_2 : tea"<<endl;
#endif
    mda->additive(CREAM_ID);
}// end cream

//coffee
void VM_2::COFFEE() {
#ifdef DEBUG_MODE
    cout<<"VM_2 : COFFEE"<<endl;
#endif
    mda->dispose_drink(COFFEE_ID);
}// end coffee

//insert_cups
void VM_2::InsertCups(int n) {
#ifdef DEBUG_MODE
    cout<<"VM_2 : InsertCups"<<endl;
#endif
    mda->insert_cups(n);
}// end insert_cups

//set_price
void VM_2::SetPrice(float p) {
#ifdef DEBUG_MODE
    cout<<"VM_2 : SetPrice"<<endl;
#endif
    ds->setTempPrice(p);
    mda->set_price();
}// end set_price

//cancel
void VM_2::CANCEL() {
#ifdef DEBUG_MODE
    cout<<"VM_2 : cancel"<<endl;
#endif
    mda->cancel();
}// end cancel
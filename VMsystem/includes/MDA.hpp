#include <utility>

//
// Created by thomas on 28/04/19.
//

#ifndef VMSYSTEM_MDA_HPP
#define VMSYSTEM_MDA_HPP

#include <vector>
#include "Strategy.hpp"
#include "Globals.hpp"

using namespace std;

class MDA;

// all states
typedef enum {
    START = 0,
    NO_CUPS,
    IDLE,
    COIN_INSERTED
} states_e;

// DtaStore for MDA pattern
class StatesData {
private:
    int k = 0;
    list<int> a;

public:
    StatesData(list<int> l) : a(l) {};

    ~StatesData() = default;;

    // temp price
    void setK(int n) {
        k = n;
    }

    int getK() {
        return k;
    }

    void setA(list<int> n_a) {
        a = std::move(n_a);
    }

    list<int> getA() {
        return a;
    }


};

class State {
protected:
    MDA *context;
    OP *op;
    StatesData *sd;
    //int id;
public:
    State(MDA *ctxt,
          OP *o, StatesData *s) : context(ctxt), op(o), sd(s) {};

    virtual ~State() = default;;

    virtual void create() {
#ifdef DEBUG_MODE
        cout << "IMPOSSIBLE ACTION IN THIS STATE" << endl;
#endif
    };

    virtual void insert_cups(int n) {
#ifdef DEBUG_MODE
        cout << "IMPOSSIBLE ACTION IN THIS STATE" << endl;
#endif
    };

    virtual void coin(int n) {
#ifdef DEBUG_MODE
        cout << "IMPOSSIBLE ACTION IN THIS STATE" << endl;
#endif
    };

    virtual void card() {
#ifdef DEBUG_MODE
        cout << "IMPOSSIBLE ACTION IN THIS STATE" << endl;
#endif
    };

    virtual void cancel() {
#ifdef DEBUG_MODE
        cout << "IMPOSSIBLE ACTION IN THIS STATE" << endl;
#endif
    };

    virtual void set_price() {
#ifdef DEBUG_MODE
        cout << "IMPOSSIBLE ACTION IN THIS STATE" << endl;
#endif
    };

    virtual void dispose_drink(int id) {
#ifdef DEBUG_MODE
        cout << "IMPOSSIBLE ACTION IN THIS STATE" << endl;
#endif
    };

    virtual void additive(int id) {
#ifdef DEBUG_MODE
        cout << "IMPOSSIBLE ACTION IN THIS STATE" << endl;
#endif
    };

};


// Start
class StateStart : public State {
public:
    StateStart(MDA *ctxt,
               OP *o, StatesData *s) : State(ctxt, o, s) {};

    ~StateStart() override = default;;

    void create() override;
};//end Start


// No cups
class StateNoCups : public State {
public:
    StateNoCups(MDA *ctxt,
                OP *o, StatesData *s) : State(ctxt, o, s) {};

    ~StateNoCups() override = default;;

    void coin(int n) override;

    void insert_cups(int n) override;
};//end Nocups


// Idle
class StateIdle : public State {
public:
    StateIdle(MDA *ctxt,
              OP *o, StatesData *s) : State(ctxt, o, s) {};

    ~StateIdle() override = default;;

    void coin(int f) override;

    void insert_cups(int n) override;

    void set_price() override;

    void card() override;

};//end Idle


// Coin Inserted
class StateCoinInserted : public State {
public:
    StateCoinInserted(MDA *ctxt,
                      OP *o, StatesData *s) : State(ctxt, o, s) {};

    ~StateCoinInserted() override = default;;

    void coin(int f) override;

    void cancel() override;

    void dispose_drink(int id) override;

    void additive(int id) override;
};//end coin inserted


class MDA {
private:
    vector<State *> states; /* a list of all states */
    State *current; /* current state of the EFSM */
    int attempts; /* number of incorrect PIN attempts */
public:
    explicit MDA(OP *op);

    virtual ~MDA();

    void changeState(states_e stateID);

    void create();

    void insert_cups(int n);

    void coin(int f);

    void card();

    void cancel();

    void set_price();

    void dispose_drink(int id);

    void additive(int id);

};


#endif //VMSYSTEM_MDA_HPP

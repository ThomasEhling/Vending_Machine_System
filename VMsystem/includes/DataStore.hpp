//
// Created by thomas on 27/04/19.
//

#ifndef VMSYSTEM_DATASTORE_HPP
#define VMSYSTEM_DATASTORE_HPP

using namespace std;

// Class to store the data
class DataStore {
public:
    DataStore() = default;;

    virtual ~DataStore() = default;;
};// end DataaStore

// DataStore for VM1
class DS_1 : public DataStore {
private:
    // vaariables for VM_1
    int temp_p{}, temp_v{}, price{}, cf{};

public:
    DS_1() = default;;

    ~DS_1() override = default;;

    // temp price
    void setTempPrice(int p) {
        temp_p = p;
    }

    int getTempPrice() {
        return temp_p;
    }

    // value
    void setTempValue(int v) {
        temp_v = v;
    }

    int getTempValue() {
        return temp_v;
    }

    // price
    void setPrice(int p) {
        price = p;
    }

    int getPrice() {
        return price;
    }

    // coins
    void setCoins(int c) {
        cf = c;
    }

    int getCoins() {
        return cf;
    }
};// end DS_1

// DataStore for VM2
class DS_2 : public DataStore {
private:
    // vaariables for VM_2
    float temp_p{}, price{}, cf{}, temp_v{};

public:
    DS_2() = default;;

    ~DS_2() override {};

    // temp price
    void setTempPrice(float p) {
        temp_p = p;
    }

    float getTempPrice() {
        return temp_p;
    }

    // value
    void setTempValue(float v) {
        temp_v = v;
    }

    float getTempValue() {
        return temp_v;
    }

    // price
    void setPrice(float p) {
        price = p;
    }

    float getPrice() {
        return price;
    }

    // coins
    void setCoins(float c) {
        cf = c;
    }

    float getCoins() {
        return cf;
    }
};// end DS_2

#endif //VMSYSTEM_DATASTORE_HPP

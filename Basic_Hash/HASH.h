#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <iostream>
#include <iterator>
#include <map>

#define MAXIMUM 17 /// This number you could change

using namespace std;

template<class T>
class Hash {
    private:
        map<int, T*> buckets[MAXIMUM];
    public:
        Hash();

        bool isEmpty();
        bool exist(int findMe);

        void insertData(int KEY, T* insertMe);
        void findData(int findMe);
        void deleteData(int eraseMe);

        int HASHING(int data);

        void toString();
    };
template<class T>
Hash<T>::Hash() {}

template<class T>
bool Hash<T>::isEmpty() {
    int aux(0);
    for(int i = 0; i < MAXIMUM; i++) {
        if(buckets[i].empty()) {
            aux++;
            }
        }
    if(aux == MAXIMUM) {
        return true;
        }
    return false;
    }

template<class T>
void Hash<T>::insertData(int KEY, T* insertMe) {
    int aux = KEY;

    int numHashed = HASHING(KEY);

    buckets[numHashed].insert({aux, insertMe});
    }

template<class T>
bool Hash<T>::exist(int findMe) {
    for(int i = 0; i < MAXIMUM; i++) {
        if(buckets[i].count(findMe) > 0) {
            return true;
            }
        }
    return false;
    }

template<class T>
void Hash<T>::findData(int findMe) {
    for(int i = 0; i < MAXIMUM; i++) {
        if(buckets[i].count(findMe) > 0) {
            cout << "The thing was find in the bucket [" << i << "]" << endl;
            cout << "Key: " << buckets[i].begin()->first << endl;
            cout << "Name: " << *buckets[i].begin()->second << endl;
            return;
            }
        }
    }

template<class T>
void Hash<T>::deleteData(int eraseMe) {
    for(int i = 0; i < MAXIMUM; i++) {
        if(buckets[i].count(eraseMe) > 0) {
            buckets[i].erase(eraseMe);
            cout << "Deleted successfully" << endl;
            return;
            }
        }
    cout << "Doesn't exist" << endl;
    }

template<class T>
int Hash<T>::HASHING(int data) {
    int dataHashed = data % MAXIMUM;
    return dataHashed;
    }

template<class T>
void Hash<T>::toString() {
    for(int i = 0; i < MAXIMUM; i++) {
        if(buckets[i].empty()) {
            cout << "Bucket [" << i << "]  is empty" << endl;
            }
        else {
            cout << "Bucket [" << i << "]" << endl;
            for (auto it = buckets[i].begin(); it != buckets[i].end(); ++it) {
                cout << it->first << " => " << *it->second << endl;
                }
            }
        }
    }

#endif // HASH_H_INCLUDED

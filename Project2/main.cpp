///////////////////////////////////
///////////////////////////////////
// Description of File : Project 2 for CS 33211 - Operating Systems
// Author: Christabel Akhigbe
// Updated on: 11/23/2022
// 
// Considering a system with five processes 
// P0 through P4 and three resources of type A, B, C. 
// Resource type A has 10 instances, 
// B has 5 instances and 
// type C has 7 instances.
// 
// Implement the Banker’s algorithm to answer the following question：
// Is the system in a safe state? 
// If Yes, then what is the safe sequence?
///////////////////////////////////
///////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int P = 5;
const int M = 3;
int safe[P];

// function prototypes
void compNeed(int need[P][M], int max[P][M], int allocated[P][M]);
bool isSafe(int[], int[], int maxm[][M], int allot[][M]);

int main() {
    int max[P][M]; //global variables called here
    int allocated[P][M];
    int avail[M];
    int process[] = { 0,1,2,3,4 };
    
    //input file
    ifstream in("avail.txt");
    if (!in) {
        cout << "File not opened, 'avail.txt'";
        exit(1);
    }

    while (in) {
        for (int i = 0; i < M; i++) {
            in >> avail[i];
        }
    }
    in.close();

    //input file
    in.open("max.txt");
    if (!in) {
        cout << "File not opened, 'max.txt'.";
        exit(1);
    }

    while (in) {
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < M; j++) {
                in >> max[i][j];
            }
        }
    }
    in.close();

    //input file
    in.open("allocated.txt");
    if (!in) {
        cout << "File not opened, 'allocated.txt'.";
        exit(1);
    }

    while (in) {
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < M; j++) {
                in >> allocated[i][j];
            }
        }
    }
    in.close();
    
    isSafe(process, avail, max, allocated);

    //end
}

void compNeed(int need[P][M], int max[P][M], int allocated[P][M]) { //n, m, a
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < M; j++) {
            need[i][j] = max[i][j] - allocated[i][j]; //n = m - a
        }
    }
}

bool isSafe(int processes[], int avail[], int maxm[][M], int allot[][M]) {
    int need[P][M];
    compNeed(need, maxm, allot);
    bool finish[P] = { 0 };
    //available resources
    int work[M];
    for (int i = 0; i < M; i++) {
        work[i] = avail[i];
    }
    int count = 0;
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (finish[p] == 0) { //is finished
                int j;
                for (j = 0; j < M; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }
                
                if (j == M) { // all P need done
                    for (int k = 0; k < M; k++) {
                        work[k] += allot[p][k];
                    }
                    safe[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        
        if (found == false) {
            cout << "Not Safe State";
            return false;
        }
    }

    cout << "Safe state." << endl << "Safe sequence is: ";
    for (int i = 0; i < P; i++) {
        cout << safe[i] << " ";
    }
    cout << "\n";
    return true;
}
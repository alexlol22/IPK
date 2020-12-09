#include <vector>
#include <iostream>
#include "cmath"

using namespace std;

namespace vecstuff{
    class BasicVectorOps{
        public:
        vector<double> emptyBoi={};
        vector<double> smolBoi={1};
        vector<double> reverseBoi={3, 8, 7, 5, 9, 2};
        vector<double> fractionBoi={0.3, 0.8, -5.7, 0};
        /*
        Hi Ivan! Ich fände es sehr sinnvoll, wichtige Schlagworte (z.B. initializer lists) bereits
        in den Übungensblättern oder im tutorium zu benennen. 
        Dann können Leute viel einfacher danach googlen/fragen dazu stellen und wissen direkt,
        wie das Konstrukt heißt.
        */
        
        void printContents();
        void printContentsSingle(vector<double> &vec);
        pair<double, double> findMinMax(vector<double> vec);
        vector<double> * reversed(const vector<double>& vec);
        void reverseInPlace(vector<double>& vec);
        void roundInPlace(vector<double>& vec);
    };
}
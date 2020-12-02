#include "iostream"

int opcount=0;
float test= -3255.322f;

int collatz(int number){
    while (number != -17 && number != -5 && number != -1 && number != 0 && number != 1){
        if (number % 2 == 0){
            number /= 2;
        }else{
            number *= 3;
            number++;
        }
        std::cout << number << std::endl;
        opcount++;
    }
    return number;
}

int main(){
    int startingNo;
    std::cout << "Enter number to start with: ";
    std::cin >> startingNo;
    startingNo = collatz(startingNo);
    std::cout << "Operations until " << startingNo << " was reached: " << opcount << "\n";
}

/* Antworten auf Fragen
Da Zahlen nur vom Betrag her kleiner werden mit Zahl/2, 
das Ergebnis dieser Division aber nicht null sein kann, kann eine 0 nur erreicht werden, indem man damit anfängt.
Das Muster 4,2,1,4,2,1... oder -1,-2,-1... entsteht durch Zweierpotenzen. D.h., dass jede Zweierpotenz unweigerlich wieder auf 1/-1 kommen wird.
*/
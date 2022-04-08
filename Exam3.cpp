#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class PayRaise 
{

public:

    PayRaise();
    ~PayRaise();
    PayRaise(string, float, float);
    void printData();
    void calcBonus(float);

private:

    string employeeName;
    float currentPay;
    float raisePercentage;
    float raiseAmount;
    float newPay;

};

PayRaise::PayRaise() 
{

    employeeName = "";
    currentPay = 0.0;
    raisePercentage = 0.0;
    raiseAmount = 0.0;
    newPay = 0.0;

}

PayRaise::~PayRaise()
{

    cout << "the name of " << employeeName << " is destroyed" << endl;

}

PayRaise::PayRaise(string name, float pay, float percentage)
{

    employeeName = name;
    currentPay = pay;
    raisePercentage = percentage;
    raiseAmount = (currentPay * raisePercentage) / 100;
    newPay = currentPay + raiseAmount;

}

void PayRaise::printData() 
{

    cout << "the person's name is " << employeeName << endl;
    cout << "the old pay amount is $" << fixed << setprecision(2) << currentPay << endl;
    cout << "the raise percentage is " << fixed << setprecision(2) << raisePercentage << endl;
    cout << "the raise amount is $" << fixed << setprecision(2) << raiseAmount << endl;
    cout << "the new pay is $" << fixed << setprecision(2) << newPay << endl;
    cout << endl;

}

void PayRaise::calcBonus(float bonus) 
{

    currentPay = currentPay + bonus;
    raiseAmount = (currentPay * raisePercentage) / 100;
    newPay = currentPay + raiseAmount;

}

int main() 
{

    PayRaise p("Corby Bryan", 50000, 10);
    p.printData();

    float bonus;
    cout << "how much is the bonus? ";
    cin >> bonus;
    cout << endl;

    p.calcBonus(bonus);
    cout << "after the bonus" << endl << endl;
    p.printData();

    return 0;

}

#include<iostream>
using namespace std;

class clsCalculator
{
    private:
        int _Result = 0;
        string _LastOperation = "Clear";
        int _LastOperand = 0;
        int _PreviousResult;

        bool _isZero(int Number)
        {
            if (Number == 0)
                return true;
            else
                return false;
        }

    public:
        void Add(int Number)
        {
            _PreviousResult = _Result;
            _Result += Number;
            _LastOperation = "Adding";
            _LastOperand = Number;
        }

        void Substruct(int Number)
        {
            _PreviousResult = _Result;
            _Result -= Number;
            _LastOperation = "Substructing";
            _LastOperand = Number;
        }

        void Divide(int Number)
        {
            _LastOperand = Number;

            if (_isZero(Number))
            {
                // just for demo puposes
                Number = 1;
            }

            _PreviousResult = _Result;
            _Result /= Number;
            _LastOperation = "Dividing";
        }

        void Multiply(int Number)
        {
            _PreviousResult = _Result;
            _Result *= Number;
            _LastOperation = "Multiplying";
            _LastOperand = Number;
        }

        void Clear()
        {
            _PreviousResult = _Result;
            _Result = 0;
            _LastOperation = "Clear";
            _LastOperand = 0;
        }

        void CancelLastOperation()
        {
            _Result = _PreviousResult;
            _LastOperation = "Cancelling Last Operation";
            _LastOperand = 0;
        }

        void PrintResult()
        {
            //printf("Result After %s %d is: %d \n", _LastOperation, _LastOperand, _Result);
            cout << "Result After " << _LastOperation << " " << _LastOperand;
            cout << " is: " << _Result << endl;
        }

        int GetFinalResults()
        {
            return _Result;
        }
};

int main()
{
    clsCalculator Calculator1;

    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Divide(0);
    Calculator1.PrintResult();

    Calculator1.Multiply(9);
    Calculator1.PrintResult();

    Calculator1.Substruct(100);
    Calculator1.PrintResult();

    Calculator1.Clear();
    Calculator1.PrintResult();

    return 0;
}
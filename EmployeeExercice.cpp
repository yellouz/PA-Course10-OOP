#include<iostream>
using namespace std;

class clsEmployee
{
private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Title; // enum is better
    string _Email;
    string _Phone;
    int _Salary;
    string _Department; // should also be enum

public:
    clsEmployee(int ID, string FirstName, string LastName, string Title, string Email, string Phone, int Salary, string Depatment)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Title = Title;
        _Email = Email;
        _Phone = Phone;
        _Salary = Salary;
        _Department = Depatment;
    }

    // property get (ID is readonly)
    int ID()
    {
        return _ID;
    }

    string FirstName()
    {
        return _FirstName;
    }
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string LastName()
    {
        return _LastName;
    }
    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    string Title()
    {
        return _Title;
    }
    void setTitle(string Title)
    {
        _Title = Title;
    }

    string Email()
    {
        return _Email;
    }
    void Email(string Email)
    {
        _Email = Email;
    }

    string Phone()
    {
        return _Phone;
    }
    void setPhone(string Phone)
    {
        _Phone = Phone;
    }

    int Salary()
    {
        return _Salary;
    }
    void setSalary(int Salary)
    {
        _Salary = Salary;
    }

    string Department()
    {
        return _Department;
    }
    void setDepartment(string Department)
    {
        _Department = Department;
    }

    void SendEmail(string Subject, string Body)
    {
        cout << "\nThe following message sent successfuly to email : " << _Email << endl;
        cout << "Subject : " << Subject << endl;
        cout << "Body : " << Body << endl;
    }

    void SendSMS(string Message)
    {
        cout << "\nThe following message sent successfuly to phone : " << _Phone << endl;
        cout << Message << endl;
    }

    void Print()
    {
        cout << "\nInfo : " << endl;
        cout << "____________________________\n";
        cout << "ID        : " << _ID << endl;
        cout << "FirstName : " << _FirstName << endl;
        cout << "LastName  : " << _LastName << endl;
        cout << "Full Name : " << FullName() << endl;
        cout << "Title     : " << _Title << endl;
        cout << "Email     : " << _Email << endl;
        cout << "Phone     : " << _Phone << endl;
        cout << "Salary    : " << _Salary << endl;
        cout << "Department: " << _Department << endl;
        cout << "____________________________\n";
    }
};

int main()
{
    clsEmployee Employee1(10,"Youssef","Ellouz","Engineer","my@gmail.com","0612121212",5000,"Development");
    Employee1.Print();
    Employee1.SendEmail("Check", "Hello");
    Employee1.SendSMS("How are you!");
    
    return 0;
}
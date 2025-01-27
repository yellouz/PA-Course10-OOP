#include<iostream>
using namespace std;

class clsPerson
{
private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    int getID() // ID is readonly
    {
        return _ID;
    }

    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    string getFirstName()
    {
        return _FirstName;
    }

    void setLastName(string LastName)
    {
        _LastName = LastName;
    }
    string getLastName()
    {
        return _LastName;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void setEmail(string Email)
    {
        _Email = Email;
    }
    string getEmail()
    {
        return _Email;
    }

    void setPhone(string Phone)
    {
        _Phone = Phone;
    }
    string getPhone()
    {
        return _Phone;
    }

    void Print()
    {
        cout << "\nInfo : " << endl;
        cout << "____________________________\n";
        cout << "ID        : " << _ID << endl;
        cout << "FirstName : " << _FirstName << endl;
        cout << "LastName  : " << _LastName << endl;
        cout << "Full Name : " << FullName() << endl;
        cout << "Email     : " << _Email << endl;
        cout << "Phone     : " << _Phone << endl;
        cout << "____________________________\n";
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
};

class clsEmployee : public clsPerson
{
private:
    string _Title;
    int _Salary;
    string _Department;

public:
    clsEmployee(int ID, string FirstName, string LastName, string Title, string Email, string Phone, int Salary, string Depatment)
    : clsPerson(ID, FirstName, LastName, Email, Phone)
    {
        _Title = Title;
        _Salary = Salary;
        _Department = Depatment;
    }

    string Title()
    {
        return _Title;
    }
    void setTitle(string Title)
    {
        _Title = Title;
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

    void Print()
    {
        cout << "\nInfo : " << endl;
        cout << "____________________________\n";
        cout << "ID        : " << getID() << endl;
        cout << "FirstName : " << getFirstName() << endl;
        cout << "LastName  : " << getLastName() << endl;
        cout << "Full Name : " << FullName() << endl;
        cout << "Title     : " << _Title << endl;
        cout << "Email     : " << getEmail() << endl;
        cout << "Phone     : " << getPhone() << endl;
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
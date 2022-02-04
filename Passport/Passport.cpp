#include <iostream>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <vector>

using namespace std;

class Passport
{
private:

    string patronymic;

protected:

    string name;
    string surname;
    string series;
    int number;
    string issued;

public:

    Passport()
    {
        series = "KK";
        number = 333222;
        issued = "12/12/2021";
        name = "Sara";
        patronymic = " Moiseevna";
        surname = " Fisher";        
    }

    void PrintPassport()
    {
        cout << "Name: " << name
            << "\nSurname: " << surname
            << "\nPatronymic: " << patronymic
            << "\nPassport: " << series << " " << number
            << "\nIssued: " << issued;
    }
};

class Visa 
{
protected:
    string country;
    string type_of_entry;
    string date;
    string day;

public:
    void SetСountry(string country)
    {
        this->country = country;
    }

    string GetСountry()
    {
        return country;
    }  

    void SetDate(string date)
    {
        this->date = date;
    }

    string GetDate()
    {
        return date;
    }    

    void SetTypeOfEntry(string type_of_entry)
    {
        this->type_of_entry = type_of_entry;
    }

    string GetTypeOfEntry()
    {
        return type_of_entry;
    }
    
    void SetDay(string day)
    {
        this->day = day;
    }

    string GetDay()
    {
        return day;
    }

    void Clear()
    {       
        country = '\0';
        type_of_entry = '\0';
        date = '\0';
        day = '\0';
    }

    void PrintVisa()
    {
        cout << "\n\nVisa: " << GetСountry()
            << "\nDate: " << GetDate() << "\nfor "
            << GetDay() << " days" << "\nType of entry: "
            << GetTypeOfEntry() <<"\n";
    }
};

class ForeignPassport : virtual public Passport
{
protected:

    string type = "P";
    string country_code = "UA";
    int no = 111222;
    string nationality = "UKRAINE";
    string date_of_issue = "11.11.2021";
    string date_of_expiry = "11.11.2031";
    vector <Visa> visas;   

public:

    void AddVisas(Visa& visa)
    {            
        visas.push_back(visa);                 
    }   
    
    void Print()
    {
        PrintPassport();
        cout << "\n\nForeign passport: " << type << " " << country_code << " " << no
            << "\nDate of issue: " << date_of_issue
            << "\nDate of expiry: " << date_of_expiry
            << "\nNationality: " << nationality;  
       for (int i = 0; i < visas.size(); i++)
        {
            visas[i].PrintVisa();
        }
    }     
};


int main()
{
    Visa v;
    ForeignPassport f;

    v.SetСountry("Madagaskar ");
    v.SetTypeOfEntry("sea liner ");
    v.SetDate("01/01/2021 ");
    v.SetDay("120 ");   
    
    f.AddVisas(v);    
    f.Print();
}

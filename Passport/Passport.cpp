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
        AddCountry(country);
    }

    string GetСountry()
    {
        return country;
    }  

    void AddCountry(string country_)
    {
        for (int i = 0; country_[i] != '\0'; i++)
        {
            country.push_back(country_[i]);
        }
    }

    void SetDate(string date)
    {
        AddDate(date);
    }

    string GetDate()
    {
        return date;
    }

    void AddDate(string date_)
    {
        for (int i = 0; date_[i] != '\0'; i++)
        {
            date.push_back(date_[i]);
        }
    }

    void SetTypeOfEntry(string type_of_entry)
    {
        AddTypeOfEntry(type_of_entry);
    }

    string GetTypeOfEntry()
    {
        return type_of_entry;
    }

    void AddTypeOfEntry(string type_of_entry_)
    {
        for (int i = 0; type_of_entry_[i] != '\0'; i++)
        {
            type_of_entry.push_back(type_of_entry_[i]);
        }
    }
    void SetDay(string day_)
    {
        AddDay(day_);
    }

    string GetDay()
    {
        return day;
    }

    void AddDay(string day_)
    {
        for (int i = 0; day_[i] != '\0'; i++)
        {
            day.push_back(day_[i]);
        }
    }
   /* void AddAll()
    {
        AddCountry(country);
        AddDay(day);
        AddTypeOfEntry(type_of_entry);
        AddDate(date);
    }*/

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

class ForeignPassport : virtual public Passport, virtual public Visa
{
protected:

    string type = "P";
    string country_code = "UA";
    int no = 111222;
    string nationality = "UKRAINE";
    string date_of_issue = "11.11.2021";
    string date_of_expiry = "11.11.2031";
    vector <Visa*> visas;   

public:

    void AddVisas(Visa* visas)
    {        
        visas->GetСountry();
        visas->GetDate();
        visas->GetDay();
        visas->GetTypeOfEntry();           
    }   
    
    void Print()
    {
        PrintPassport();
        cout << "\n\nForeign passport: " << type << " " << country_code << " " << no
            << "\nDate of issue: " << date_of_issue
            << "\nDate of expiry: " << date_of_expiry
            << "\nNationality: " << nationality;  
        //PrintVisa();
    }     
};


int main()
{
    Visa v;
    ForeignPassport f;

    f.Print();
    v.AddCountry("Madagaskar ");
    v.AddTypeOfEntry("sea liner ");
    v.AddDate("01/01/2021 ");
    v.AddDay("120 ");
    //f.AddVisas(&v);
    v.PrintVisa();
    v.Clear();
    v.AddCountry("Mosambic ");
    v.AddTypeOfEntry("liner ");
    v.AddDate("01/01/2022 ");
    v.AddDay("90 "); 
    v.PrintVisa();
    //f.AddVisas(&v);    
    //v.PrintVisa();
}

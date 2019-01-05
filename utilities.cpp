//
//  utilities.cpp
//  Reco
//
//  Created by Lawrence Luo on 1/3/19.
//  Copyright © 2019 Lawrence Luo. All rights reserved.
//

#include "utilities.hpp"
#include <fstream>

const string DatabasePath = "/Users/LawrenceLuo/Documents/reco-project/Database.csv";



//GetSOI returns an SOI with info loaded if it already exists, and returns a new SOI with first and last name if doesn't already exist
SOI GetSOI(string firstName, string lastName) //this needs to be changed. Right now it's a while loop, but that's O(n). we should use a hashtable to automatic line # lookup.
{
    SOI soi = SOI(firstName, lastName);
    
    bool found = false;
    string line;
    
    string n1, n2, n3, n4;
    int num1, num2, num3, num4;
    streampos linepos;
    
    //int count = 0; //this is a counter for the line number
    
    //Open the database file
    fstream fs;
    fs.open (DatabasePath);
    if (!fs)
    {
        cerr << "ERROR: Unable to open file Database.csv\n";
        exit(1);   // call system to stop
    }
    
    //find the person in the database
    while (getline(fs, line))
    {
        if (line.find(firstName + "," + lastName + ",") != string::npos)
        {
            //cout << "Displaying SOI Information:\n" << line << endl;
            found = true;
            break;
        }
        linepos = fs.tellg(); //store the stream position
        //count++; //this gets the line number
    }
    
    //return line number if found, or return -1 if not found
    if (found)
    {
        //populate the SOI fields
        fs.seekg(linepos);
        getline(fs,line, ','); //dummy, firstname
        getline(fs,line, ','); //dummy, lastName
        getline(fs,n1, ',');
        getline(fs,n2, ',');
        getline(fs,n3, ',');
        getline(fs,n4, '\n');
        
        num1 = stoi(n1);
        num2 = stoi(n2);
        num3 = stoi(n3);
        num4 = stoi(n4);
        
        soi.num1 = num1;
        soi.num2 = num2;
        soi.num3 = num3;
        soi.num4 = num4;
        
        fs.close();
        return soi;
    }
    else
    {
        fs.close();
        return soi;
    }
}

bool exists(string firstName, string lastName)
{
    bool found = false;
    string line;

    //Open the database file
    fstream fs;
    fs.open (DatabasePath);
    if (!fs)
    {
        cerr << "ERROR: Unable to open file Database.csv\n";
        exit(1);   // call system to stop
    }
    
    //find the person in the database
    while (getline(fs, line) && !found)
    {
        if (line.find(firstName + "," + lastName + ",") != string::npos)
        {
            found = true;
        }
    }
    
    if (found) return true;
    else return false;
    
}

void updateDatabase(SOI soi)
{
    //this is used for when a tracker is closed or when the user prompts an SOI update
    
    /////structural dummy
    cout << "(dummy utilities) Updating SOI information for " << soi.firstName << " " << soi.lastName << "\n";
    
    
    bool found = false;
    string line;

    streampos linepos;
    
    //int count = 0; //this is a counter for the line number
    
    //Open the database file
    fstream fs;
    fs.open (DatabasePath);
    if (!fs)
    {
        cerr << "ERROR: Unable to open file Database.csv\n";
        exit(1);   // call system to stop
    }
    
    //find the person in the database
    while (getline(fs, line))
    {
        if (line.find(soi.firstName + "," + soi.lastName + ",") != string::npos)
        {
            //cout << "Displaying SOI Information:\n" << line << endl;
            found = true;
            break;
        }
        linepos = fs.tellp(); //store the stream position
        //count++; //this gets the line number
    }
    
    //return line number if found, or return -1 if not found
    if (found)
    {
        //write to the correct line in csv
        fs.seekp(linepos);
        fs << soi.returnInfo();
        
        fs.close();

    }
    else
    {
        /////structural dummy
        cout << "(dummy utilities) storing SOI data for " << soi.firstName << " " << soi.lastName << " in database\n";
        
        //write the info on a new line
        //close the file stream and open it in append mode
        fs.close();
        fs.open(DatabasePath, ios::app);
        
        fs << soi.returnInfo();
        fs.close();
    }
}

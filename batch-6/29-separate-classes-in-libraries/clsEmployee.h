#pragma once

#include iostream
#include clsPerson.h

class clsEmployee  public clsPerson
{
	string _title;
	string _department;
	float _salary;

public

	clsEmployee(int ID, string firstName, string lastName, string email, string phone, string title, string department, float salary) 
		clsPerson(ID, firstName, lastName, email, phone)
	{
		_title = title;
		_department = department;
		_salary = salary;
	}

	Property Set
	void SetTitle(string Title)
	{
		_title = Title;
	}
	Property Get
	string Title()
	{
		return _title;
	}
	Property Set
	void SetDepartment(string Department)
	{
		_department = Department;
	}
	Property Get
	string Department()
	{
		return _department;
	}
	Property Set
	void SetSalary(float Salary)
	{
		_salary = Salary;
	}
	Property Get
	float Salary()
	{
		return _salary;
	}

	void PrintInfo()
	{
		cout  Employee Infon;
		cout  ______________________________  endl;
		cout  ID           ID()  endl;
		cout  First Name   FirstName()  endl;
		cout  Last Name    LastName()  endl;
		cout  Full Name    FullName()  endl;
		cout  Email        Email()  endl;
		cout  Phone        Phone()  endl;
		cout  Title        Title()  endl;
		cout  Department   Department()  endl;
		cout  Salary       Salary()  endl;
		cout  ______________________________  endl;
	}

};
/*
*	Lab Project
*		Topic : Contact Managment System
*	CSCL 1208 Lab : Object Oriented Programming Techniques
*	Date:        2 - June / 2021
*	Group Members : - Asher Fraz Anjum
*					- Ameer Yousaf Ali
*					- Muhammad Hamza
*
*	Project Requirement:-
*		1)	First Name          ==>>   	Person  	[ Char array[12] ]
*		2)	Last Name          	==>>    Surname 	[ Char array[10] ]
*		3)	Country Code        ==>> 	(+) 92 				[ string ]
*		4)	Phone Number        ==>>    0312-3456789        [ string ]
*		5)	Address          	==>>    House, Street - RWP	[ string ]
*		6)	Electronic-Mail     ==>>    CMS@project.com		[ string ]
*/
# include <iostream>
# include <conio.h>
# include <string.h>
# include <fstream>
using namespace std;

 //  File Handling
fstream file("Contacts.txt" , ios::in | ios::out | ios::app );

// Forward Declarations
class Address;
class Handle_File;

	  /* Classes */

class Contacts {
	private:
		char option ;
		string Keyword , data , usename1 , usename2 , usename3;
	protected:
		char fname[15] , lname[12] , P_number[16] , country_code[4];
	public:
		void addContact(){
			system("cls");
			cout<<"\n\n\t\t\t Contact Management System"<<endl;
			cout<<"\n Creating New Contact "<<endl;
		    cout<<"\n\tEnter First Name : ";				cin.ignore();	gets(fname);
		    cout<<"\n\tEnter Last Name : ";		    			gets(lname);
		    cout<<"\n\tEnter Country Code : ";		    			gets(country_code);
		    cout<<"\n\tEnter Phone Number : ";        	gets(P_number);
		}
						/*		Search Contact		*/
  		void searchContact(){
		bool found = false ;
			system("cls");
			ifstream file("Contacts.txt" , ios::in | ios::app );
			cout<<"\n\n\t\t\t Contact Management System"<<endl<<endl;
				cout<<"\n Searching Contact details in Phone-Book"<<endl;
				cout<<" Which option you want to search:"<<endl;
				cout<<"\n\t[1] First Name"<<endl
					<<"\n\t[2] Last Name "<<endl
					<<"\n\t[3] Phone Number "<<endl;
				cout<<"\n Enter Option: "; cin>>option;
				cout<<endl;
			switch(option){
				case '1' : {
							// Search with First Name
					cout<<"\t Enter First Name to Search: ";		cin.ignore();   getline(cin,Keyword);
					while( !file.eof() ){
						getline(file,data);
						if(Keyword == data){
								cout<<"\nFirst Name \t "<<data<<endl;
							getline(file,data);
								cout<<"Last Name \t "<<data<<endl;
							getline(file,data);
								cout<<"Country Code \t "<<data<<endl;
							getline(file,data);
								cout<<"Phone Number \t "<<data<<endl;
							getline(file,data);
								cout<<"Email \t\t "<<data<<endl;
							getline(file,data);
								cout<<"Address \t "<<data<<endl<<endl
									<<"\t Contact retrieved Successfully!"<<endl;
							found = true;
						}
					}
					if(found == false){
						cout<<" Contact not exist in PhoneBook!"<<endl;
					}
					break;
				}
				case '2' : {
							// Search with Last Name
					cout<<"\t Enter Last Name to Search: ";		cin.ignore();   getline(cin,Keyword);
					while( !file.eof() ){
						getline(file, usename1);
						getline(file,data);
						if(Keyword == data ){
								cout<<"\nFirst Name \t "<<usename1<<endl;
								cout<<"Last Name \t "<<data<<endl;
							getline(file,data);
								cout<<"Country Code \t "<<data<<endl;
							getline(file,data);
								cout<<"Phone Number \t "<<data<<endl;
							getline(file,data);
								cout<<"Email \t\t "<<data<<endl;
							getline(file,data);
								cout<<"Address \t "<<data<<endl<<endl
						        	<<"\t Contact retrieved Successfully!"<<endl;
							found = true;
						}
					}
					if(found == false){
						cout<<" Contact not exist in PhoneBook!"<<endl;
					}
					break;
				}
				case '3' : {
							// Search with Phone Number
					cout<<"\t Enter Phone Number to Search: ";		cin.ignore();   getline(cin,Keyword);
					while( !file.eof() ){
						getline(file, usename1);
						getline(file, usename2);
						getline(file, usename3);
						getline(file,data);
						if(Keyword == data ){
								cout<<"\nFirst Name \t "<<usename1<<endl;
								cout<<"Last Name \t "<<usename2<<endl;
								cout<<"Country Code \t "<<usename3<<endl;
								cout<<"Phone Number \t "<<data<<endl;
							getline(file,data);
								cout<<"Email \t\t "<<data<<endl;
							getline(file,data);
								cout<<"Address \t "<<data<<endl<<endl
						        	<<"\t Contact retrieved Successfully!"<<endl;
							found = true;
						}
					}
					if(found == false){
						cout<<" Contact not exist in PhoneBook!"<<endl;
					}
					break;
				}
				default : {			searchContact();			}
			}
		file.close();
	}
};


class Address : public Contacts {
	protected:
		string addr , Email;
	public:
			/*	Friend Class 	*/
		friend class Handle_File;
		void help();
		bool check_Email(string email);

		void AddContact(){
				addContact();
			Re_Mail:
			cout<<"\n\tEnter E-mail : ";    getline(cin, Email);
			if(!check_Email(Email) == true){		goto Re_Mail;  }
			cout<<"\n\tEnter Address : ";       getline(cin, addr);
		}
};

class Handle_File : public Contacts {
	public:
			/*			Writting Data to File			*/
		void Writing_file(){
			Address Adr;
			Adr.AddContact();
		ofstream file("Contacts.txt" , ios::out | ios::app );
		    if(file.is_open()){
		        file<<Adr.fname<<endl;
				file<<Adr.lname<<endl;
				file<<Adr.country_code<<endl;
		        file<<Adr.P_number<<endl;
				file<<Adr.Email<<endl;
				file<<Adr.addr<<endl<<endl;
		    	cout<<"\n\t\tContact Saved Successfully !"<<endl;
			}
		    else
		    {
		            cout<<"\n\tError Opening File !"<<endl;
		    }
			file.close();
		}
			/*			Grabbing Data From Contacts.txt file			*/
		void viewContact(){
		ifstream file("Contacts.txt" , ios::in | ios::app );
			system("cls");
			cout<<"\n\n\t\t\t Contact Management System"<<endl<<endl;
			cout<<"\n Viewing All Saved Contacts :";
			cout<<"\n==============================================================================="<<endl;
			while (!file.eof())
			{	string data;
				getline(file,data);
					cout<<"First Name \t "<<data<<endl;
				getline(file,data);
					cout<<"Last Name \t "<<data<<endl;
				getline(file,data);
					cout<<"Country Code \t "<<data<<endl;
				getline(file,data);
					cout<<"Phone Number \t "<<data<<endl;
				getline(file,data);
					cout<<"Email \t\t "<<data<<endl;
				getline(file,data);
					cout<<"Address \t "<<data<<endl;
				getline(file,data);
					cout<<data<<endl;
			}
			cout<<"\n==============================================================================="<<endl;
			file.close();
		}
};


	/*		Functions Declarations			*/
int main();
int header_menu(void);
void Program_Restart(void);
void self_exit(void);


	/* 		Main Block OR  Driver Code   	*/
int main(){
	//	Class Object
	Handle_File Handle;
	Address addr;
	string restart;
	char opt = header_menu();

	switch(opt){
		case '1':	{
            Handle.Writing_file();
            break;
        	}
        case '2': {
            addr.searchContact();
            break;
        	}
        case '3': {
        	Handle.viewContact();
			break;
		}
		case '4' : {
   			system("cls");
			file.close();
			cout<<"\n\n\t\t\t\t Contact Management System"<<endl<<endl;
			cout<<"\n\n\t\t\t\a\"Are You Sure You Want To Delete Contacts Book\""<<endl;
			cout<<"\n\n\n\t\t\t     [ y ] Yes\t   |  \tNo [ n ]  "<<endl<<"\t\t\t\t  ===================\n\t\t\t\t\t   ";
				cin>>restart;
			cout<<"\t\t\t\t  ==================="<<endl;
			if ( restart == "y" || restart == "Y" || restart == "yes" || restart == "Yes"   ){
				cout<<'\a'<<endl;
				system("del contacts.txt");
			}
			else if (restart == "n" || restart == "no" || restart == "N" || restart == "No"  ){
				main();
			}
			break;
		}
        case '5': {
            addr.help();
            break;
        	}
        case '6': {
            self_exit();
            break;
			}
		default:{
			cout << "\n\tPress Any Key To Continue...";
            system("pause");
            main();
		}
	}
	Program_Restart();
	return 0;
}

	/*		Functions Definations 		*/
int header_menu(void){
	system("title Lab Project - Contact Management System ");
	system("cls");
//	system("mode con cols=85 lines=25");
	system("color 0a");

	cout<<"\n\n\t\t\t Contacts Management System"<<endl;
	cout<<"\n\n\t [1] Create New Contact "<<endl;
	cout<<"\n\t [2] Search Contact "<<endl;
	cout<<"\n\t [3] View All Contacts "<<endl;
	cout<<"\n\t [4] Delete Contacts Book "<<endl;
	cout<<"\n\t [5] Documentation "<<endl;
	cout<<"\n\t [6] Quit "<<endl;
	char opt='0';
	cout<<"\n\n\t  \f  Enter Choice : ";
	cin>>opt;
	return opt;
}
void self_exit(void){
	system("cls");
	cout<<"\n\n\t\t\t Contact Management System"<<endl;
	cout<<"\n\n\t Exitting!... "<<endl;
	_exit(0);
}

void Program_Restart(void){
	string restart;
	Program_Restart:
	cout<<"\n\n\n   You want to restart this program  [ y ] Yes | No [ n ]  : ";
		cin>>restart;
	if ( restart == "y" || restart == "Y" || restart == "yes" || restart == "Yes"   ){
		main();
	}
	else if (restart == "n" || restart == "no" || restart == "N" || restart == "No"  ){
		file.close();
		self_exit();
	}
	else{
        cout << "\n\n\tInvalid Input !";
        cout << "\n\tPress Any Key To Continue...";
    	system("pause");
    	goto Program_Restart;
	}
}
	/*		Classes Functions		*/
bool Address :: check_Email(string email){
   	for(int i=0 ; i<=email.length() ; i++){
		if( email[i] == ' ' ){
			Email[i] = '\0';
			continue;
		}
		if(email[i] == '@' ){
			return true;
		}
	}
}

void Address :: help(){
	system("cls");
	cout<<"\n\n\t\t\t Help / Documentation"<<endl
		<<"\n\tProject No. 1"<<endl
		<<"\n\t\tTopic : Contact Management System"<<endl
		<<"\n\tCSCL 1208 Lab : Object Oriented Programming Techniques "<<endl
		<<"\n\tDescription   : This program help us to Add, Search & View  contacts in our Phone Book."<<endl
		<<"\n\tGroup Members : @asherfraz	\t- Asher Fraz Anjum"<<endl
		<<"			@ameeryousufalibhatti  \t- Ameer Yousaf Ali"<<endl
		<<"			@HamzahKhalid \t\t- Muhammad Hamza"<<endl<<endl
		<<"\tProject Requirement:-"<<endl
		<<"\t\t1)	First Name\t\t==>>   	Person  \t\t\t [ Char array[12] ] "<<endl
		<<"\t\t2)	Last Name\t\t==>>    Surname \t\t\t [ Char array[12] ] "<<endl
		<<"\t\t3)	Country Code\t\t==>> 	(+) 92 \t\t\t\t\t [ string ] "<<endl
		<<"\t\t4)	Phone Number\t\t==>>    0312-3456789 \t\t\t\t [ string ] "<<endl
		<<"\t\t5)	Address\t\t\t==>>    House 1 , Street 10 - Rawalpindi RWP \t [ string ]  "<<endl
		<<"\t\t6)	Electronic-Mail\t\t==>>    CMS@project.com \t\t\t [ string ]  "<<endl;
}

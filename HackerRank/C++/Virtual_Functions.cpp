#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int idStudent = 0, idProfessor = 0;
class Person{
public:
	string name,age;
	virtual void getdata(){
		cin>>name>>age;
	}
	virtual void putdata(){
		cout<<name<<" "<<age<<endl;
	}
};

class Professor : public Person{
public:
	void getdata(){
		cin>>name>>age>>publications;
		cur_id = ++idProfessor;
	}
	void putdata(){
		cout<<name<<" "<<age<<" "<<publications<<" "<<cur_id<<endl;
	}
private:
	int publications, cur_id;
};

class Student : public Person{
public:
	void getdata(){
		cin>>name>>age;
		sum = 0,cur_id = ++idStudent;
		for(int x=0; x<6 && cin>>marks[x]; x++)sum+=marks[x];
	}
	void putdata(){
		cout<<name<<" "<<age<<" "<<sum<<" "<<cur_id<<endl;
	}
private:
	int marks[6], cur_id,sum;
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

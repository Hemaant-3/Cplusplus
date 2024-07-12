#include <iostream>
using namespace std;
class Student
{
private:
    string gf;

public:
    int id;
    int age;
    string name;
    int nos;
    bool present;

    Student(){
        //default ctor.. which is also construct by compiler
        cout<<"Default ctor"<<endl;
    }
    Student(int id, int age, string name, int nos, bool present){
        this->id = id;
        this->age= age;
        this->name= name;
        this->nos = nos;
        this->present = present;
        cout<<"ctor without gf"<<endl;
    }
    Student(int _id, int _age, string _name, int _nos, bool _present, string _gf){
        id = _id;
        age = _age;
        name = _name;
        nos = _nos;
        present = _present;
        gf = _gf;
        cout<<"ctor with gf"<<endl;
    }
    void cheating()
    {
        cout << "Cheating" << endl;
    }
    void gaming()
    {
        cout << "Playing game" << endl;
    }
    void study()
    {
        cout << "Studying"<<endl;
    }

private:
    void chatting()
    {
        cout << "chatting" << endl;
    }
    };
 int main()
{
Student s1;
// cout<<sizeof(Student)<<endl;
cout<<s1.age<<endl;
Student s2(1,12,"Hemant",5,1);
cout<<s2.name<<endl;
Student s3(1,14,"Monu",5,1,"Jiya");
cout<<s3.name<<endl;
    return 0;
}
#include <iostream>
using namespace std;

class Employee {
  char* empName;
  const int empID;
  public:
    Employee(char* name, int id):empID(id)
    {
      empName = name;
    };
    
    void setName(char* name){
      empName = name;
    }
    void getData(){
      cout << "Name: " << empName << "\nID: " << empID << endl;
    }
};

int main (int argc, char *argv[]) {
  Employee e1("Rajiv", 1), e2("Raj", 2), e3("Rajiv", 3);

  e1.getData();
  e1.setName("SHIT");
  e1.getData();

  return 0;
}

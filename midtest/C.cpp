#include <iostream>
using namespace std;

class myobject {
public:
// 在此处补充你的代码
static int counter;
void print_avaliable(){
    printf("%d ",counter);
}
void work(){
    counter = counter - 4>0?counter - 4:counter;

	print_avaliable();
}
//end
};

class producer : public myobject {
public:
	virtual void work() {
		counter = counter + 5;
		print_avaliable();
	}
};

int myobject::counter = 0;

int main(){
	producer *pro = new producer();
	myobject *con = new myobject();
	pro->work(); pro->work(); cout << endl;
	con->work(); con->work(); con->work(); cout << endl;
	pro->work(); cout << endl;
	con->work(); con->work(); cout << endl;
}
#include <iostream>
#include <string>

using namespace std;

/*
다형성
 - 여러개의 자식클래스 객체를 하나의 부모클래스의 포인터로 컨트롤하는 것

 순수 가상 함수
 - 메소드의 기능을 정의하지 않은 가상 함수
 - 반드시 상속을 해야하는 클래스의 경우 기본클래스에서 가상함수의 내용을 정의할 필요가 없다
   이러한 경우에 순수 가상함수를 사용한다
 - 순수 가상 함수를 포함하는 클래스는 객체 생성이 불가능
 - 실체가 없기 때문에 추상클래스라고도 한다
*/
class Remote {
public:
	virtual void powerOff() = 0;
	virtual void powerOn() = 0;
	Remote() : on("ON"), off("OFF") {}
protected:
	string off;
	string on;
};
class Tv : public Remote {
public:
	virtual void powerOff() {
		cout << "전원 : " << off<<endl;
	}
	virtual void powerOn() {
		cout << "전원 : " <<on<< endl;
	}
};
class IPtv : public Remote {
public:
	virtual void powerOff() {
		cout << "IP TV 전원 : " <<off << endl;
	}
	virtual void powerOn() {
		cout << "IP TV 전원 : " << on<< endl;
	}
};
class Device {
public:
	void deviceOnOff() {
		if (remote != NULL) {
			int power;
			cout << "1. ON  2. OFF  > "; cin >> power;

			if (power == 1)
				remote->powerOn();
			else if (power == 2)
				remote->powerOff();
		}
		else {
			cout << "- 장치를 선택하세요 -" << endl;
		}
	}
	void devicePower() {
		bool run = true;
		while (run) {
			int select;
			cout << "1. TV  2.IPTV  3.on/off  > "; cin >> select;
			switch (select) {
			case 1:
				remote = tv;
				break;
			case 2:
				remote=iptv;
				break;
			case 3:
				deviceOnOff();
			case 0: 
				run = false;
				break;
			}
		}
	}
	~Device() {
		delete tv;
	}
	Device() {
		remote = NULL;
		tv = new Tv;
		iptv = new IPtv;
		devicePower();
	}
private:
	IPtv* iptv;
	Tv* tv;
	Remote* remote;
};
int main() {

	Device* device = new Device;
	delete device;

}
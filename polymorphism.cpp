#include <iostream>
#include <string>

using namespace std;

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

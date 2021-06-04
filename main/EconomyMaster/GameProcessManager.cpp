#include "GameProcessManager.h"

#include <conio.h>


using namespace std;

GameProcessManager::GameProcessManager(ProvinceManager *pManager) {
	//load process
	this->pManager = pManager;
	this->TControlor = new TimeControlor();
	//game process
	while (1) {
		cout << "��������Ӧ�ַ����в���\n";
		cout << "1 ��ʼ��Ϸ\n" << "2 ��ȡ��Ϸ��δ������\n" << "3 ����\n" << "4 ����" << endl;
		string input;
		cin >> input;
		if (input == "1") {
			break;
		}
		else if (input == "2") {
			cout << "�浵�ṹ��δ�����������ڴ�\n\n" << endl;
		}
		else if (input == "3") {
			cout;
		}
		else if (input == "4") {
			cout << "";
		}
		else {
			cout << "��������ȷ����ţ�" << endl;
		}
	}
	bool isn = true;
	while (isn) {
		string name;
		cout << "�����빫˾����\n";
		cin >> name;
		cout << "��ȷ�����Ĺ�˾���� \"" << name << " \" ��(���س�ȷ�ϣ�����������������)" << endl;
		int ch;
		while (1) {
			if (_kbhit()) {
				ch = _getch();
				if (ch == 13) {
					isn = false;
					break;
				}
				else {
					break;
				}
			}
		}
		this->Company_Name = name;
	}
	bool isChooseHead = true , sure = true;
	while (sure) {
		while (isChooseHead) {
			string name;
			while (1) {
				cout << "��ѡ�� \"" << Company_Name << " \" �ܲ���λ�ã�" << endl;
				cout << "��ѡ��ʡ�ݣ��Ѽ��ص�ʡ�ݣ�" << endl;
				this->pManager->infoPro();
				cout << "������ʡ������ȡ�ؼ���" << endl;
				cin >> name;
				if (pManager->isLoaded(name)) {
					this->Head = pManager->getProvinceByName(name);
					break;
				}
				else {
					cout << "ʡ����������������������\n\n" << endl;
				}
			}
			while (1) {
				cout << " \"" << Company_Name << " \" �ʺ����ܲ��ĳ��У�" << endl;
				Head.infoDetails();
				cout << "������ؼ��е�������ȷ���ܲ�λ�ã�����back����ʡ��ѡ��" << endl;
				cin >> name;
				if (name == "back") {
					cout << "������һ��\n" << endl;
					break;
				}
				if (Head.isInProvince(name)) {
					this->HeadQu = Head.getCityByName(name);
					isChooseHead = false;
					break;
				}
				else {
					cout << "������������������������" << endl;
				}
			}
		}
		cout << "��ȷ�����Ĺ�˾�ܲ��� \"" << Head.getName() << "  " << HeadQu.getName() << " \" �𣿣����س���ȷ�ϣ�" << endl;
		int ch;
		while (1) {
			if (_kbhit()) {
				ch = _getch();
				if (ch == 13) {
					sure = false;
					break;
				}
				else {
					break;
				}
			}
		}
	}
	if (&(this->Head)!=NULL&& &(this->HeadQu) != NULL) {
		cout << "�ܲ������ɹ������ڿ�ʼ��Ϸ��\n\n\n" << endl;
	}

	while (1) {
		perMessage(TControlor);
	}
}

void GameProcessManager::perMessage(TimeControlor *tc) {
	cout << tc->getDate().getYear() << "��" << tc->getDate().getMonth() << "��" << tc->getDate().getDay() << "��" << endl;
	cout << "��ǰ��" << money << endl;
	tc->dayPlus();
}

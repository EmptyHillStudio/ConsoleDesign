#include "GameProcessManager.h"

#include <conio.h>


using namespace std;

GameProcessManager::GameProcessManager(ProvinceManager *pManager) {
	//load process
	this->pManager = pManager;
	this->TControlor = new TimeControlor();
	//game process
	while (1) {
		cout << "请输入相应字符进行操作\n";
		cout << "1 开始游戏\n" << "2 读取游戏（未开发）\n" << "3 设置\n" << "4 关于" << endl;
		string input;
		cin >> input;
		if (input == "1") {
			break;
		}
		else if (input == "2") {
			cout << "存档结构还未开发，敬请期待\n\n" << endl;
		}
		else if (input == "3") {
			cout;
		}
		else if (input == "4") {
			cout << "";
		}
		else {
			cout << "请输入正确的序号！" << endl;
		}
	}
	bool isn = true;
	while (isn) {
		string name;
		cout << "请输入公司名：\n";
		cin >> name;
		cout << "您确定您的公司名叫 \"" << name << " \" 吗？(按回车确认，按其他键重新输入)" << endl;
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
				cout << "请选择 \"" << Company_Name << " \" 总部的位置：" << endl;
				cout << "先选择省份，已加载的省份：" << endl;
				this->pManager->infoPro();
				cout << "请输入省份名获取地级市" << endl;
				cin >> name;
				if (pManager->isLoaded(name)) {
					this->Head = pManager->getProvinceByName(name);
					break;
				}
				else {
					cout << "省份名输入有误，请重新输入\n\n" << endl;
				}
			}
			while (1) {
				cout << " \"" << Company_Name << " \" 适合做总部的城市：" << endl;
				Head.infoDetails();
				cout << "请输入地级市的名称来确定总部位置，输入back返回省份选择。" << endl;
				cin >> name;
				if (name == "back") {
					cout << "返回上一层\n" << endl;
					break;
				}
				if (Head.isInProvince(name)) {
					this->HeadQu = Head.getCityByName(name);
					isChooseHead = false;
					break;
				}
				else {
					cout << "城市名输入有误，请重新输入" << endl;
				}
			}
		}
		cout << "您确定您的公司总部在 \"" << Head.getName() << "  " << HeadQu.getName() << " \" 吗？（按回车键确认）" << endl;
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
		cout << "总部创建成功！现在开始游戏。\n\n\n" << endl;
	}

	while (1) {
		perMessage(TControlor);
	}
}

void GameProcessManager::perMessage(TimeControlor *tc) {
	cout << tc->getDate().getYear() << "年" << tc->getDate().getMonth() << "月" << tc->getDate().getDay() << "日" << endl;
	cout << "当前余额：" << money << endl;
	tc->dayPlus();
}

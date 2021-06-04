#include "CsvReader.h"
CsvReader::CsvReader(string path) {
	ifstream inFile(path, ios::in);
	if (!inFile) {
		cout << "Can't find the path:" << path << endl;
		cout << "Please check the files." << endl;
		return;
	}
	else {
		cout << "Open the file \"" << path << "\" successfully!" << endl;
	}
	string line;
	for (int k = 0; getline(inFile, line);k++) {//�ļ����ж�ȡ
		istringstream sin(line);
		int size = 0;
		vector<string> tes;
		for (string filed;getline(sin, filed, ',');size++) {//ÿ�д���
			tes.insert(tes.end(), filed);
			//cout << filed << ", ";   //ÿ�����
		}
		this->Reader.insert(Reader.end(), tes);
		//cout << "\n"; //���Դ���
	}

}
CsvReader::~CsvReader() {}

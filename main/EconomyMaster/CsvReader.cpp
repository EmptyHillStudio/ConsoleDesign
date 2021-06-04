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
	for (int k = 0; getline(inFile, line);k++) {//文件按行读取
		istringstream sin(line);
		int size = 0;
		vector<string> tes;
		for (string filed;getline(sin, filed, ',');size++) {//每行处理
			tes.insert(tes.end(), filed);
			//cout << filed << ", ";   //每行输出
		}
		this->Reader.insert(Reader.end(), tes);
		//cout << "\n"; //调试代码
	}

}
CsvReader::~CsvReader() {}

#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <set>
#include <vector>

using namespace std;
#pragma once

class CsvReader
	/*****
	CSV�ļ���ȡ�������ȡCSV���ŷָ����ļ���
	�Ȱ��ж�ȡ����ÿ�����ݷ��䵽һ���µĶ�̬�����У��ŵ��Ƕ�ȡÿ�е��������Žϸߵ�Ч�ʣ������нϸߵĲ���Ч�ʡ�
	*****/
{
private:
	set<vector<string>> Reader;
public:
	set<vector<string>> getReader() { return this->Reader; }

	CsvReader(string path);
	~CsvReader();
};


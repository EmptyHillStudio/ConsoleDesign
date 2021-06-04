#pragma once
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <list>
using namespace std;
/*ע�����������������������Ϊ50�غϣ�Ҳ����50�غ�Ϊһ����������ȡֵ�������
������������������ǰ50�غϣ���0��1�����ڵ㹲�������ڵ㣩���������������غ�������50�����ݵ�50�غϵĵ���µ����������֮��50�غϵ��°�������������
�Դ����ƣ���˻᲻����������������������������Ϸ���̣���ʹ�ø�������������ռ�ÿռ䲻�ϷŴ�
*/
class PerlinNoiseCreater
{
private:
	double RandomNumber(unsigned seed);//�����������
	double Interpolate(double x1, double x2, int x);//��ֵ����������������Ҳ�ֵ
	list<double> PerlinList;//�������Ӧ�����������
	int Octaves, Persistence;//��Ƶ�������
public:
	double temp(double sum, double frequency, double amplitude, double maxValue, int Data);
	PerlinNoiseCreater(double Oct, double Per);
	double getNoiseData(int Data,int random);//����Data��ֵ���ض�Ӧ�İ��������������ɵ����ݣ�����Data�������߶�Ϊ0.01��RandomΪ���ֵ����ֵ������ֵ����Է���ֵ����ǿ�����
	~PerlinNoiseCreater();
};


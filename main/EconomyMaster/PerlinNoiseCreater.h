#pragma once
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <list>
using namespace std;
/*注：柏林噪声随机点生成周期为50回合，也就是50回合为一个柏林噪声取值的随机点
柏林噪声函数会生成前50回合（第0、1个周期点共两个周期点）的噪声函数，当回合数大于50后会根据第50回合的点和新的随机点生成之后50回合的新柏林噪声函数。
以此类推，因此会不断生成新噪声函数，但是随着游戏进程，会使得该生成器的链表占用空间不断放大。
*/
class PerlinNoiseCreater
{
private:
	double RandomNumber(unsigned seed);//随机数生成器
	double Interpolate(double x1, double x2, int x);//插值函数，这里采用余弦插值
	list<double> PerlinList;//横坐标对应纵坐标的链表
	int Octaves, Persistence;//倍频与持续度
public:
	double temp(double sum, double frequency, double amplitude, double maxValue, int Data);
	PerlinNoiseCreater(double Oct, double Per);
	double getNoiseData(int Data,int random);//根据Data的值返回对应的柏林噪声函数生成的数据，建议Data连续，尺度为0.01，Random为随机值，该值的余弦值会乘以返回值，增强随机性
	~PerlinNoiseCreater();
};


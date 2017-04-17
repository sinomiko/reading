#include <iostream>
#include <iomanip>

using namespace std;

// 通过操纵子方式进行格式化输出
// 宽度控制
// 对齐控制
// 填充控制
// 精度控制
// 进制输出
int main(void)
{
	//system("chcp 936");
	int n = 64;
	double d = 123.45;
	double d2 = 0.0187;

	cout<<"=================宽度控制====================="<<endl;
	cout<<n<<'#'<<endl;
	cout<<setw(10)<<n<<'#'<<n<<endl;		// 宽度控制不会影响下一个输出

	cout<<"=================对齐控制====================="<<endl;
	cout<<setw(10)<<setiosflags(ios::left)<<n<<'#'<<endl;
	cout<<setw(10)<<n<<'#'<<endl;			// 对齐控制会影响下一个输出
	//cout<<setw(10)<<setiosflags(ios::right)<<n<<'#'<<endl;
	cout<<setw(10)<<resetiosflags(ios::left)<<n<<'#'<<endl;

	cout<<"=================填充控制====================="<<endl;
	cout<<setw(10)<<setfill('?')<<n<<'#'<<endl;
	cout<<setw(10)<<n<<'#'<<endl;			// 填充控制会影响下一个输出
	cout<<setw(10)<<setfill(' ')<<n<<'#'<<endl;

	cout<<"=================精度控制====================="<<endl;
	cout<<setprecision(4)<<d<<endl;
	cout<<setprecision(2)<<d2<<endl;

	cout<<setiosflags(ios::fixed);
	cout<<setprecision(4)<<d<<endl;
	cout<<setprecision(2)<<d2<<endl;

	cout<<"=================进制输出====================="<<endl;
	cout<<n<<endl;
	//cout<<resetiosflags(ios::dec);
	//cout<<setiosflags(ios::oct)<<n<<endl;
	////cout<<resetiosflags(ios::oct);
	//cout<<n<<endl;
	////cout<<setiosflags(ios::hex)<<n<<endl;
	//cout<<hex<<n<<endl;

	cout<<oct<<n<<endl;
	cout<<hex<<n<<endl;
	cout<<endl;

	cout<<setiosflags(ios::showbase);
	cout<<dec<<n<<endl;
	cout<<oct<<n<<endl;
	cout<<hex<<n<<endl;

	cout<<endl;
	cout<<setbase(10)<<n<<endl;
	cout<<setbase(8)<<n<<endl;
	cout<<setbase(16)<<n<<endl;




	return 0;
}
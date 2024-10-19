#include <iostream>
#include <format>
using namespace std;

int main()
{
  /* C++中使用cout函数打印八进制的方法:
  * cout << oct; // 此行代码可使后续输出均为八进制, 为避免误解为仅单行进行八进制输出, 应将其单独成行
  * cout.setf(ios::oct, ios::basefield);
  * cout.flags(ios::oct);
  * #include <iomanip> // <IO-manipulator>
  * cout << setbase(8);
  * 可使用no...来关闭cout设置
  */
  int a = 255;
  cout << dec; // 设置输出格式为十进制
  cout << a << endl;
  cout << oct; // 设置输出格式为八进制
  cout << a << endl;
  cout << hex; // 设置输出格式为十六进制(小写)
  cout << a << endl;
  cout << uppercase; // 设置输出格式为十六进制(大写)
  cout << a << endl;
  cout << showbase; // 设置输出时在数字前显示进制符号
  cout << a << endl;
  cout << nouppercase; // 取消前面设置的十六进制大写模式
  cout << a << endl;
  cout << dec;
  cout << endl;

  /* 利用format函数打印不同进制函数:
  * {}中为空时默认以十进制输出
  * 输出其他格式时需先在{}内加上:在用相应的符号和字母调整格式
  * 使用format函数打印不需要声明数据长度和有无符号
  * b, #b, #B为format函数新增的二进制格式
  */
  cout << format("{}", a) << endl;
  cout << format("{:o}", a) << endl;
  cout << format("{:x}", a) << endl;
  cout << format("{:X}", a) << endl;
  cout << format("{:#o}", a) << endl;
  cout << format("{:#x}", a) << endl;
  cout << format("{:#X}", a) << endl;
  cout << format("{:b}", a) << endl;
  cout << format("{:#b}", a) << endl;
  cout << format("{:#B}", a) << endl;
  cout << endl;

  /* C++中打印字符:
  */
  char c = 'a';
  cout << c << endl;
  cout << format("{}", c) << endl;
  cout << format("{:d} {:c}", c, 97) << endl; // 使用format函数时会根据{}规定的数据类型对应填入

  /* C++中布尔类型输出:
  */
  bool T = true;
  bool F = false;
  cout << T << " " << F << endl;
  cout << boolalpha; // 设置输出布尔类型的结果
  cout << T << " " << F << endl;
  cout << format("{:d} {:d}", T, F) << endl; // 特地声明以十进制输出
  cout << endl;

  /* C++中浮点数输出:
  */
  float f = 3.14159265358979323846;
  cout << f << endl;
  cout << f << endl;
  cout << scientific; // 设置输出格式为科学记数法(对应e)
  cout << f << endl;
  cout << defaultfloat; // 设置输出为常规模式(对应g)
  cout << f << endl;
  cout << hexfloat; // 设置为内存输出法(对应a)
  cout.precision(10); // 控制小数点后的固定位数, 一般和fixed结合使用
  cout << fixed; // 固定小数位数(对应f)
  cout << f << endl;
  cout << format("{:f}", f) << endl;
  cout << format("{:e}", f) << endl;
  cout << format("{:g}", f) << endl;
  cout << format("{:a}", f) << endl;
  cout << format("{}", f) << endl; // {}内为空时会尽可能多地输出有效数字
  cout << format("{:.8f}", f) << endl; // .8f:固定小数点后8位
  cout << format("{:.{}}", f, 10) << endl; // format占位符顺序是以左括号进行计数, 所以此处代表精读的值需要放在后面(和printf相反)
  cout << endl;

  /* C++中调整排版方法:
  * 通过调用width传入宽度的大小(仅生效一次)
  * left和right可分别控制左右对齐
  * format函数中使用>,<,^等形象表示对齐方向
  */
  cout.width(7);
  cout << a << "|" << endl;
  cout << left;
  cout.width(7);
  cout << a << "|" << endl;
  cout << format("{:>7}|", a) << endl;
  cout << format("{:<7}|", a) << endl;
  cout << format("{:^7}|", a) << endl; // 此处^的作用为居中对齐
  cout << endl;

  // format函数{}中的:前可指定输出哪个数据(从0开始标号)
  cout << format("{:4d}{0:4o}{0:4x}", 255) << endl; // 欲使用同一个数据多次打印时需在:前规定好该数据位置
  cout << format("{1}{0}", a, f) << endl; // format函数在指定时可以不按照顺序
  cout << endl;
}
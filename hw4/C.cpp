// C:惊呆！Point竟然能这样输入输出
// 查看提交统计提问
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 程序填空
#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
// 在此处补充你的代码
    friend istream & operator>>(istream & op, Point & p) {
        return op >> p.x >> p.y;
    }
    friend ostream & operator<<(ostream & op, Point & p) {
        return op << p.x << "," << p.y;
    }
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}
// 输入
// 多组数据，每组两个整数
// 输出
// 对每组数据，输出一行，就是输入的两个整数
// 样例输入
// 2 3
// 4 5
// 样例输出
// 2,3
// 4,5
// 来源
// Guo Wei
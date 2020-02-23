// C:编程填空：左边i位取反
// 查看提交统计提问
// 总时间限制: 1000ms 内存限制: 1024kB
// 描述
// 写出函数中缺失的部分，使得函数返回值为一个整数,该整数的左边i位是n的左边i位取反，其余位和n相同
// 请使用【一行代码】补全bitManipulation3函数使得程序能达到上述的功能

#include <iostream>
using namespace std;

void debug(int k){
    int a[32];
        printf("%d=",k);
    for (int i = 0; i < 32; i++)
    {
        a[31-i]=k%2;
        if(k%2<0)
        {
            a[31-i]+=2;
            k=k/2-1;
        }
        // printf("%d\n",k%2);
        else
        {
            k/=2;
        }
    }
    for (int i = 0; i < 32; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}

int bitManipulation3(int n, int i) {
debug(n);
debug(n<<i);
debug(n&(~(-1<<(32-i))));
debug(((~(n>>(32-i)))<<(32-i)));
debug((n&(~(-1<<(32-i))))|((~(n>>(32-i)))<<(32-i)));
// 在此处补充你的代码
return i==32?~n:(n&(~(-1<<(32-i))))|((~(n>>(32-i)))<<(32-i));

}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}
// 输入
// 第一行是整数 t，表示测试组数。
// 每组测试数据包含一行，是两个整数 n 和 i (1<=i<=32)。
// 输出
// 对每组输入数据，输出整型变量n中左边i位取反的结果。
// 样例输入
// 1
// 0 32
// 样例输出
// -1
// 提示
// 注意i从1开始
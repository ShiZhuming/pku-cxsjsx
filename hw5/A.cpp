// A:全面的MyString
// 查看提交统计提问
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 程序填空，输出指定结果

#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
// 在此处补充你的代码
private:
char * s;
public:
MyString() {
    s = NULL;
}
MyString(char * e) {
    if(e) {
        s = new char[strlen(e) + 1];
        strcpy(s,e);
    }
    else s = NULL;
}
MyString(const MyString & e) {
    if(e.s) {
        s = new char[strlen(e.s) + 1];
        strcpy(s,e.s);
    }
    else s = NULL;
}
~MyString() {
    if (s)
    {
        delete [] s;
    }
    
}
friend ostream & operator<<(ostream & op, const MyString & e) {
    if(e.s) {
        return op << e.s;
    }
    else {
        return op;
    }
}
MyString & operator=(const MyString & e) {
    if(e.s) {
        s = new char[strlen(e.s) + 1];
        strcpy(s,e.s);
    }
    else s = NULL;
    return *this;
}
MyString operator+(const MyString & e) {
    char * t = new char[strlen(s) + strlen(e.s) + 1];
    strcpy(t,s);
    strcat(t,e.s);
    MyString temp(t);
    delete [] t;
    return temp;
}
MyString & operator=(const char * e) {
    if(e) {
        s = new char[strlen(e) + 1];
        strcpy(s,e);
    }
    else s = NULL;
    return *this;
}
char & operator[](int p) {
    return s[p];
}
void operator+=(const char * e) {
    char * t = new char[strlen(s) + strlen(e) + 1];
    strcpy(t,s);
    strcat(t,e);
    delete [] s;
    s = t;
}
friend MyString operator+(const char * s, const MyString & e) {
    char * t = new char[strlen(s) + strlen(e.s) + 1];
    strcpy(t,s);
    strcat(t,e.s);
    MyString temp(t);
    delete [] t;
    return temp;
}
bool operator<(const MyString & e) {
    return strcmp(s,e.s) == -1;
}
bool operator==(const MyString & e) {
    return strcmp(s,e.s) == 0;
}
bool operator>(const MyString & e) {
    return strcmp(s,e.s) == 1;
}
MyString operator()(int b, int l) {
    char * t = new char[l + 1];
    for (int i = 0; i < l; i++)
    {
        t[i] = s[b + i];
    }
    t[l] = 0;
    MyString temp(t);
    delete [] t;
    return temp;
}

};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}
// 输入
// 无
// 输出
// 1. abcd-efgh-abcd-
// 2. abcd-
// 3.
// 4. abcd-efgh-
// 5. efgh-
// 6. c
// 7. abcd-
// 8. ijAl-
// 9. ijAl-mnop
// 10. qrst-abcd-
// 11. abcd-qrst-abcd- uvw xyz
// about
// big
// me
// take
// abcd
// qrst-abcd-
// 样例输入
// 无
// 样例输出
// 1. abcd-efgh-abcd-
// 2. abcd-
// 3. 
// 4. abcd-efgh-
// 5. efgh-
// 6. c
// 7. abcd-
// 8. ijAl-
// 9. ijAl-mnop
// 10. qrst-abcd-
// 11. abcd-qrst-abcd- uvw xyz
// about
// big
// me
// take
// abcd
// qrst-abcd-
// 来源
// Guo Wei
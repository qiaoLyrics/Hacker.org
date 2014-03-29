题目：下面程序编译不通过，请你加一条语句（在任意地方，任意语句），使其编译通过。
int main()
{
    char k[] = "da";

    i * j = k;
	return 0;
}







答案之一 :
出题思路：是看antlr讲二义性文法时想到的。'*'的含义要看i的type才能决定，如果i是个typename，则'*'表示指针；
          如果i是数字，则'*'表示乘法
int main()
{
    char k[] = "da";
    typedef char i;

    i * j = k;
	return 0;
}

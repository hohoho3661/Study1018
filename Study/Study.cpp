// Study.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

using std::cout;
using std::cin;
using std::endl;
// C++ 11 이후 버전에서 추가된 내용들
// Modern C++ (Template Meta Prog...등 기타 등등)
// VS2012 (비주얼스튜디오2012) 에서 추가

// 함수객체(Functor)
// 함수와 클래스의 성질을 같이가짐.


// ex)
// 1~20배열
// 짝수만 출력하기 원한다.

bool Func1(int n)
{
	return (n % 2) ? true : false;
}


class AAA
{
public:
	bool operator()(int n) // 연산자 재정의
	{
		return (n % 2) ? true : false;
	}
};


int main()
{
	// 데이터 넣기
	list<int> vNum;
	for (int i = 0; i < 20; i++)
	{
		vNum.push_back(i + 1);
	}

	cout << "데이터 넣기" << endl;
	for (auto a : vNum)
	{
		cout << a << " ";
	}
	cout << endl;

	cout << "==============================================" << endl;
	cout << "== 짝수 ======================================" << endl;
	cout << "==============================================" << endl;



	// 범위 지정 알고리즘 함수를 사용하기 위해 필요한 것이 함수객체
	//std::for_each(vNum.begin(), vNum.end(), Func1);
	//
	//for (auto a : vNum)
	//{
	//	cout << a << " , ";
	//}
	//cout << endl;
	
	/*
	AAA Obj;

	while ((it = std::find_if(it, vNum.end(), Obj)) != vNum.end())
	{
		vNum.erase(it++);
	}



	cout << endl;
	cout << endl;
	cout << "짝수" << endl;
	for (auto a : vNum)
	{
		cout << a << " , ";
	}
	cout << endl;

	*/
	//////////////////////////////////////////////////////////////////////////////////////
	
	// 함수 객체는 std::function에 담을 수 있다.
	//std::function<bool(int)> Func2 = Obj;
	//bool result = Func2(4);
	
	//
	// 람다 표현식 ( 이름이 없는 함수 )
	// [캡쳐 = 전역 변수](파라미터 = 매게변수){바디 = 식}

	list<int>::iterator it = vNum.begin();

	while ((it = std::find_if(it, vNum.end(), [](auto n)->bool { return (n % 2) ? false : true; })) != vNum.end())
	{
		vNum.erase(it++);
	}
	for (auto a : vNum)
	{
		cout << a << " , ";
	}
	cout << endl;

	//
	cout << endl;
	cout << "캡쳐 사용법 " << endl;
	int a = 10;
	int b = 20;

	// std::begin(), std::end()
	std::for_each(std::begin(vNum), std::end(vNum), [a, b](auto n)
	{
		if (n >= a && n <= b)
			std::cout << n << " ";
	});
	cout << endl;

	int arNum[10] = { 1,2,3,4,5,6,7,8,9,10 };
	std::for_each(std::begin(arNum), std::end(arNum), [](auto n)
	{
		if (n >= 5)
			std::cout << n << " ";
	});
	cout << endl;


	for(;;){}
    return 0;
}
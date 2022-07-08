/*
1. 테이블 정의하기

D[i] = 2 x i 크기의 직사각형을 채우는 방법의 수

==================================
2. 점화식 : D[n] = D[n-1] + D[n-2]

주어진 2 x n 타일에서 왼쪽 가장 위를 채우는 경우를 생각하며 점화식을 유도해보자.

가장 왼쪽위를 채울때 1x2 타일을 덮는 경우, 2x1 타일을 덮는 경우 2가지로 나뉘게 될 것이다.

case1) 2x1 타일을 덮는 경우의 수 = D[n-1]

=> 2x1 타일을 채운다면, 크기가 2 x n 인 전체 타일은 2 x (n-1) 로 변할것이다.
즉, 2 x (n-1) 타일을 채우게 되는 경우의 수가 되므로 D[n-1] 이 된다!


case2) 1x2 타일을 덮는 경우의 수 = D[n-2]

=> 1x2 타일을 가장 왼쪽 위에 채우게 되면, 
채워진 가장 왼쪽 위의 타일의 바로 아래(= 가장 왼쪽 아래) 에는 반드시 1x2 타일이 들어가야 한다.
즉, 자동적으로 2x2 칸을 차지해 버리게 되어서, 2 x (n-2) 를 채우는 경우의 수를 생각하면 된다. ( = D[n-2])



=> 두 가지 case 를 모두 합하면 D[n] = D[n-1] + D[n-2] 가 된다.

==================================

3. 초기값 설정하기

D[1] = 1
D[2] = 2
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int d[10005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	// 초기값 설정
	d[1] = 1;
	d[2] = 2;

	// 점화식 : D[i] = D[i-1] + D[i-2]  => 이때 문제의 조건에 따라, 10007 로 나눈 나머지를 구해야함
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}

	cout << d[n];
}
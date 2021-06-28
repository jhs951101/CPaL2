#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#define RAND_SIZE			1000

using namespace std;


void AlphabetSandGlass()
{

	int n;  // n: 모래시계의 최대 길이를 저장하는 변수

	do{

		cout << "Input the maximum length (1-30): ";
		cin >> n;  // n의 값을 입력받음

		if(n>=1 && n<=30){  // n의 값이 1~30 사이일 경우에만 모래시계 출력

			if(n%2 == 0) n = n-1;

			int i,j;  // i: 삼각형의 행, j: 삼각형의 열

			n = n/2 +1;  // 역정삼각형을 출력하기 위해 사용

			for(i=n; i>=1; i--){

				for(j=n-i; j>=1; j--)
					cout << " ";

				int a = 97;
				char c;
				for(j=i; j>=1; j--){
					c = a;
					cout << c;
					a++;
				}
				a--;
				for(j=1; j<=i; j++){
					c = a;
					cout << c;
					a--;
				}

				cout << "\n";
			}                 // 역-정삼각형을 출력하는 부분

			for(i=2; i<=n; i++){

				for(j=1; j<=n-i; j++)
					cout << " ";

				int a = 97;
				char c;
				for(j=i; j>=1; j--){
					c = a;
					cout << c;
					a++;
				}
				a--;
				for(j=1; j<=i; j++){
					c = a;
					cout << c;
					a--;
				}

				cout << "\n";
			}                 // 정삼각형을 출력하는 부분

			cout << endl;
		}

	}while(n>=1 && n<=30);  // n의 값이 1~30 사이가 아닐 경우 루프를 빠져나옴

}

void PrintRandNumber(int randomNumber[], const int size)
{

   srand((unsigned)time(NULL));
   
   for (int i=0; i<size; i++){

      randomNumber[i] = rand() % 20 +1;  // randomNumber[]: 난수 1000개를 저장하는 배열(단, 1~20 사이)
      cout << randomNumber[i] << " ";  // 난수를 출력
   }
   cout << endl;

}

void PrintHistogram(const int randomNumber[], const int size)
{

   srand((unsigned)time(NULL));

   int count[20] = { 0 };  // count[20]: 숫자의 갯수를 저장하는 배열

   cout << "Number" << setw(15) << "Frequency" << endl;  // 선 출력문

   for(int i=1; i<=20; i++){

	   for(int a=0; a<size; a++){

		   if(randomNumber[a] == i) count[i-1]++;  // 배열(randomNumber) 안에 저장된 값들을 조사해서 갯수를 찾아냄
	   }
   }

   for(int i=0; i<20; i++){

	   if(i < 9) cout << i+1 << setw(12);
		else cout << i+1 << setw(11);  // 출력 형태를 표처럼 하기위해 사용

	   for(int a=1; a<=count[i]; a++)
		   cout << "*";    // count에 저장된 값에 따라 *의 갯수를 출력

	   cout << "(" << count[i] << ")";  // 해당 숫자가 몇 개인지 직접 출력

	   cout << endl;
   }
  
}

void FindingSameNumbers()
{

	char c;  // c: 게임 진행 여부를 저장하기 위한 변수(y/n)

	do{

		cout << "Do you want to play /finding the same number/ game? (y/n) ";
		cin >> c;  // 게임 진행 여부를 입력받음

		if(c == 'y'){  // 게임 진행 여부가 'y'일 경우 프로그램 실행

			int w, h;

			do{

			cout << "Input the width: ";
			cin >> w;  // w: width의 값을 저장하기 위한 변수

			cout << "Input the height: ";
			cin >> h;  // h: height의 값을 저장하기 위한 변수
			  // width와 height을 입력받음

			if( !(w>=1 && w<=10) || !(h>=1 && h<=10) || ((w*h)%2 == 1) )
				cout << "Input the width and height again!" << endl << endl;
			      // 입력받은 값이 조건과 안맞을 경우 재입력 창을 띄움

			}while( !(w>=1 && w<=10) || !(h>=1 && h<=10) || ((w*h)%2 == 1) );
			  // 입력받은 값이 조건과 안맞을 경우 재입력을 요구함

			cout << endl;

			int num[100];  // num[100]: 화면에 출력할 숫자들을 모두 저장하는 배열(임시 배열)
			int n = 1;  // n: 화면에 출력할 숫자
			int n_add = 0;  // n_add: 변수의 값이 2일 경우 n의 값을 +1함, 전구 변수

			for(int k=0; k<=w*h-1; k++){

				num[k] = n;
				n_add++;
				if(n_add == 2){
					n++;
					n_add = 0;
				}
			}  // 출력할 숫자들을 배열에 모두 저장

			for(int x=1; x<=w; x++){  // x: 행을 제어, y: 열을 제어

				for(int y=0; y<=h-1; y++){

					int z;  // z: 임의의 값을 저장하는 변수

					do{
						z = rand() % (w*h);  // 배열의 값을 무작위로 출력하기 위해 z에 임의의 값을 저장함

					}while(num[z] == 0);  // 중복 추출을 방지를 위해 사용 (밑의 'ㄱ' 참고)

					cout << setw(5) << num[z];  // 배열에 저장된 임의의 값을 출력
					num[z] = 0;  /* (ㄱ) 한 번 추출된 값이 다시 추출되지 않도록 하기 위해
					               해당 배열의 값을 추출했을 경우 그 배열의 값을 0으로 함 */
				}

				cout << endl;
			}  // 배열에 저장된 숫자들을 출력하는 부분

			cout << endl;

		}

	}while(c == 'y');  // 게임 진행 여부가 'n'일 경우 루프를 빠져나옴

}


int main()
{
	int randomNumber[RAND_SIZE];
	int size = RAND_SIZE;

	AlphabetSandGlass();
	PrintRandNumber(randomNumber, size);
	PrintHistogram(randomNumber, size);
	FindingSameNumbers();

	return 0;
}
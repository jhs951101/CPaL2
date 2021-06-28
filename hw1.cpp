#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#define RAND_SIZE			1000

using namespace std;


void AlphabetSandGlass()
{

	int n;  // n: �𷡽ð��� �ִ� ���̸� �����ϴ� ����

	do{

		cout << "Input the maximum length (1-30): ";
		cin >> n;  // n�� ���� �Է¹���

		if(n>=1 && n<=30){  // n�� ���� 1~30 ������ ��쿡�� �𷡽ð� ���

			if(n%2 == 0) n = n-1;

			int i,j;  // i: �ﰢ���� ��, j: �ﰢ���� ��

			n = n/2 +1;  // �����ﰢ���� ����ϱ� ���� ���

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
			}                 // ��-���ﰢ���� ����ϴ� �κ�

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
			}                 // ���ﰢ���� ����ϴ� �κ�

			cout << endl;
		}

	}while(n>=1 && n<=30);  // n�� ���� 1~30 ���̰� �ƴ� ��� ������ ��������

}

void PrintRandNumber(int randomNumber[], const int size)
{

   srand((unsigned)time(NULL));
   
   for (int i=0; i<size; i++){

      randomNumber[i] = rand() % 20 +1;  // randomNumber[]: ���� 1000���� �����ϴ� �迭(��, 1~20 ����)
      cout << randomNumber[i] << " ";  // ������ ���
   }
   cout << endl;

}

void PrintHistogram(const int randomNumber[], const int size)
{

   srand((unsigned)time(NULL));

   int count[20] = { 0 };  // count[20]: ������ ������ �����ϴ� �迭

   cout << "Number" << setw(15) << "Frequency" << endl;  // �� ��¹�

   for(int i=1; i<=20; i++){

	   for(int a=0; a<size; a++){

		   if(randomNumber[a] == i) count[i-1]++;  // �迭(randomNumber) �ȿ� ����� ������ �����ؼ� ������ ã�Ƴ�
	   }
   }

   for(int i=0; i<20; i++){

	   if(i < 9) cout << i+1 << setw(12);
		else cout << i+1 << setw(11);  // ��� ���¸� ǥó�� �ϱ����� ���

	   for(int a=1; a<=count[i]; a++)
		   cout << "*";    // count�� ����� ���� ���� *�� ������ ���

	   cout << "(" << count[i] << ")";  // �ش� ���ڰ� �� ������ ���� ���

	   cout << endl;
   }
  
}

void FindingSameNumbers()
{

	char c;  // c: ���� ���� ���θ� �����ϱ� ���� ����(y/n)

	do{

		cout << "Do you want to play /finding the same number/ game? (y/n) ";
		cin >> c;  // ���� ���� ���θ� �Է¹���

		if(c == 'y'){  // ���� ���� ���ΰ� 'y'�� ��� ���α׷� ����

			int w, h;

			do{

			cout << "Input the width: ";
			cin >> w;  // w: width�� ���� �����ϱ� ���� ����

			cout << "Input the height: ";
			cin >> h;  // h: height�� ���� �����ϱ� ���� ����
			  // width�� height�� �Է¹���

			if( !(w>=1 && w<=10) || !(h>=1 && h<=10) || ((w*h)%2 == 1) )
				cout << "Input the width and height again!" << endl << endl;
			      // �Է¹��� ���� ���ǰ� �ȸ��� ��� ���Է� â�� ���

			}while( !(w>=1 && w<=10) || !(h>=1 && h<=10) || ((w*h)%2 == 1) );
			  // �Է¹��� ���� ���ǰ� �ȸ��� ��� ���Է��� �䱸��

			cout << endl;

			int num[100];  // num[100]: ȭ�鿡 ����� ���ڵ��� ��� �����ϴ� �迭(�ӽ� �迭)
			int n = 1;  // n: ȭ�鿡 ����� ����
			int n_add = 0;  // n_add: ������ ���� 2�� ��� n�� ���� +1��, ���� ����

			for(int k=0; k<=w*h-1; k++){

				num[k] = n;
				n_add++;
				if(n_add == 2){
					n++;
					n_add = 0;
				}
			}  // ����� ���ڵ��� �迭�� ��� ����

			for(int x=1; x<=w; x++){  // x: ���� ����, y: ���� ����

				for(int y=0; y<=h-1; y++){

					int z;  // z: ������ ���� �����ϴ� ����

					do{
						z = rand() % (w*h);  // �迭�� ���� �������� ����ϱ� ���� z�� ������ ���� ������

					}while(num[z] == 0);  // �ߺ� ������ ������ ���� ��� (���� '��' ����)

					cout << setw(5) << num[z];  // �迭�� ����� ������ ���� ���
					num[z] = 0;  /* (��) �� �� ����� ���� �ٽ� ������� �ʵ��� �ϱ� ����
					               �ش� �迭�� ���� �������� ��� �� �迭�� ���� 0���� �� */
				}

				cout << endl;
			}  // �迭�� ����� ���ڵ��� ����ϴ� �κ�

			cout << endl;

		}

	}while(c == 'y');  // ���� ���� ���ΰ� 'n'�� ��� ������ ��������

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
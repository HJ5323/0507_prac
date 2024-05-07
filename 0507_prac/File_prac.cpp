// 실습 0. 거꾸로 읽기
// 1. hello.txt 파일에 입력된 내용을 마지막 줄부터 거꾸로 output.txt에 쓰기
// 2. hint : vector 사용

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inputFile("hello.txt"); // 입력 파일을 읽기 모드로 열기
	ofstream outputFile("output.txt"); // 출력 파일을 쓰기 모드로 열기

	if (inputFile.fail()) cout << "파일 없음" << endl;
	if (outputFile.fail()) cout << "파일 없음" << endl;

	vector<string> lines; 

	string line;
	while (getline(inputFile, line)) // 엔터를 기준으로 읽어 lines 벡터에 저장
	{ 
		lines.push_back(line);
	}

	for (int i = 0; i < lines.size(); i++) // lines 벡터 출력
	{
		cout << lines[i] << endl;
	}

	for (int i = lines.size() - 1; i >= 0; i--) // lines 벡터를 역순으로 읽어 output.txt에 저장
	{ 
		outputFile << lines[i] << endl;
	}

	cout << "\n거꾸로 읽기 성공" << endl;

	inputFile.close();
	outputFile.close();

	return 0;

}

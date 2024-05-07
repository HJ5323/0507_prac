// �ǽ� 0. �Ųٷ� �б�
// 1. hello.txt ���Ͽ� �Էµ� ������ ������ �ٺ��� �Ųٷ� output.txt�� ����
// 2. hint : vector ���

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inputFile("hello.txt"); // �Է� ������ �б� ���� ����
	ofstream outputFile("output.txt"); // ��� ������ ���� ���� ����

	if (inputFile.fail()) cout << "���� ����" << endl;
	if (outputFile.fail()) cout << "���� ����" << endl;

	vector<string> lines; 

	string line;
	while (getline(inputFile, line)) // ���͸� �������� �о� lines ���Ϳ� ����
	{ 
		lines.push_back(line);
	}

	for (int i = 0; i < lines.size(); i++) // lines ���� ���
	{
		cout << lines[i] << endl;
	}

	for (int i = lines.size() - 1; i >= 0; i--) // lines ���͸� �������� �о� output.txt�� ����
	{ 
		outputFile << lines[i] << endl;
	}

	cout << "\n�Ųٷ� �б� ����" << endl;

	inputFile.close();
	outputFile.close();

	return 0;

}

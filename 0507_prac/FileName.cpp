// �ǽ� 1. ȸ�� ��� �ۼ��ϱ�
//1. ����ڿ��� 3���� ȸ���� ���� �̸� ��й�ȣ �Է� �ޱ�
//2. ����ڷκ��� �Էµ� ������ member.txt�� ��� (���� ������)
//3. member.txt�� ����� ȸ����� ��� (���� �б���)

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    ofstream memberFile("member.txt");

    if (memberFile.fail()) cout << "���� ����" << endl;

    vector<string> members;

    string member;

    cout << "3���� ȸ���� ���� �̸�, ��й�ȣ�� ���������� �Է��ϼ���.\n";

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << "��° ȸ�� : ";
        getline(cin, member);
        members.push_back(member);

    }

    for (int i = 0; i < members.size(); i++)
    {
        memberFile << members[i] << endl;
    }

    memberFile.close();

    cout << "\n--------ȸ�� ��� ���� �б�--------" << endl;

    for (int i = 0; i < members.size(); i++) 
    {
        cout << members[i] << endl;
    }

    return 0;
}
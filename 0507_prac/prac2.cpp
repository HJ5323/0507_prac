// �ǽ� 2. ȸ�� ��θ� ������ �α��� ���
//1. ����ڿ��� "�̸��� �Է��ϼ���." ��� �޼����� ����� �� �̸� �Է� �ޱ�
//2. ����ڿ��� "��й�ȣ�� �Է��ϼ���." ��� �޼����� ����� �� ��й�ȣ �Է� �ޱ�
//3. member.txt���� ���پ� "�̸�"�� "���"�� �˻��Ͽ� �α��� ������ "�α��� ����" ���� �� "�α��� ����" ���
//4. ���⼭ member.txt�� �� �ǽ����� ���� ȸ�� ���

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void login(const string& username, const string& password) 
{
    ifstream file("member.txt");  // member.txt ���Ͽ��� ȸ�� ��� �б�


    if (file.fail())
    {
        cout << "������ �� �� �����ϴ�." << endl;
        return;
    }

    string line;
    bool logInOK = false;

    while (getline(file, line))  // ���Ͽ��� �� �پ� �о�ͼ� �̸��� ��й�ȣ ��
    {
        stringstream ss(line);
        string name, pw;

        if (ss >> name >> pw) // �������� �̸��� ��й�ȣ �Ľ�
        {
            if (name == username && pw == password) 
            {
                cout << "�α��� ����!" << endl;
                logInOK = true;
                break;
            }
        }
    }

    if (!logInOK)
    {
        cout << "�α��� ����!" << endl;
    }

    file.close();
}

int main() 
{
    string username, password;

    // ����ڷκ��� �̸� �Է� �ޱ�
    cout << "�̸��� �Է��ϼ���: ";
    getline(cin, username);

    // ����ڷκ��� ��й�ȣ �Է� �ޱ�
    cout << "��й�ȣ�� �Է��ϼ���: ";
    getline(cin, password);

    // �α��� �õ�
    login(username, password);

    return 0;
}
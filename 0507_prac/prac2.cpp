// �ǽ� 2. ȸ�� ��θ� ������ �α��� ���
//1. ����ڿ��� "�̸��� �Է��ϼ���." ��� �޼����� ����� �� �̸� �Է� �ޱ�
//2. ����ڿ��� "��й�ȣ�� �Է��ϼ���." ��� �޼����� ����� �� ��й�ȣ �Է� �ޱ�
//3. member.txt���� ���پ� "�̸�"�� "���"�� �˻��Ͽ� �α��� ������ "�α��� ����" ���� �� "�α��� ����" ���
//4. ���⼭ member.txt�� �� �ǽ����� ���� ȸ�� ���

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// ȸ�� �α��� �Լ�
bool login(string username, string password) 
{
    ifstream file("member.txt"); // member.txt ���� ����

    if (file.fail())
    {
        cout << "������ �� �� �����ϴ�." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) 
    {
        size_t pos = line.find(' '); // �̸��� ��й�ȣ�� �������� ���еǾ� ����
        if (pos != string::npos) 
        {
            string name = line.substr(0, pos); // ���� ��������
            string pw = line.substr(pos + 1); // ���� ����

            if (name == username && pw == password) 
            {
                file.close();
                return true; // �α��� ����
            }
        }
    }

    file.close();

    return false; // �α��� ����
}

int main() 
{
    string username, password;

    cout << "�̸��� �Է��ϼ���: ";
    cin >> username;

    cout << "��й�ȣ�� �Է��ϼ���: ";
    cin >> password;

    if (login(username, password)) 
    {
        cout << "�α��� ����!" << endl;
    } 

    else 
    {
        cout << "�α��� ����!" << endl;
    }

    return 0;
}
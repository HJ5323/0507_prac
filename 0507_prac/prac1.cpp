// �ǽ� 1. ȸ�� ��� �ۼ��ϱ�
//1. ����ڿ��� 3���� ȸ���� ���� �̸� ��й�ȣ �Է� �ޱ�
//2. ����ڷκ��� �Էµ� ������ member.txt�� ��� (���� ������)
//3. member.txt�� ����� ȸ����� ��� (���� �б���)
//4. "������̸� ��й�ȣ" ��İ��� �ٸ��� ���� 1���� �Ǵ� 3�� �̻� �Է��� ��� ���� �޽��� + �ٽ� �Է� �����ϵ���
//5. ��й�ȣ�� 6�ڸ� �̻� ~18�ڸ� �̸����� ������
//6. ���������� �Է� �޾��� ��쿡�� ���Ͽ� ����!

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream memberFile("member.txt");

    if (memberFile.fail()) 
    {
         cout << "���� ����" << endl;
         return 0;
    }
 
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


//// ȸ�� ������ ���Ͽ� �����ϴ� �Լ�
//void saveMembersToFile(const vector<pair<string, string>>& members) 
//{
//    ofstream file("member.txt"); // ���� ���� ���� ����
//
//    if (file.is_open()) 
//    {
//        for (const auto& member : members) 
//        {
//            file << member.first << " " << member.second << endl;
//        }
//
//        file.close();
//    }
//
//    else 
//    {
//        cout << "������ �� �� �����ϴ�." << endl;
//    }
//}
//
//// ���Ͽ��� ȸ�� ������ �о���� �Լ�
//void readMembersFromFile() 
//{
//    ifstream file("member.txt"); // ���� �б� ���� ����
//
//    if (file.is_open()) 
//    {
//        cout << "ȸ�� ����Ʈ:" << endl;
//        string line;
//
//        while (getline(file, line)) 
//        {
//            cout << line << endl;
//        }
//
//        file.close();
//    }
//
//    else 
//    {
//        cout << "������ �� �� �����ϴ�." << endl;
//    }
//}
//
//int main()
//{
//    ofstream memberFile("member.txt");
//
//    if (memberFile.fail()) cout << "���� ����" << endl;
//
//    vector<pair<string, string>> members;
//
//    string member;
//
//    cout << "3���� ȸ���� ���� �̸�, ��й�ȣ�� ���������� �Է��ϼ���.\n" << endl;
//
//    for (int i = 0; i < 3; i++)
//    {
//        cout << i + 1 << "��° ȸ�� : ";
//        getline(cin, member);
//
//        size_t space = member.find(' ');
//        string password = member.substr(space + 1);
//
//        if (space != string::npos && member.find(' ', space + 1) != string::npos)
//        {
//            cout << "����: �̸� ��й�ȣ�� �ٽ� �Է����ּ���." << endl;
//            i--; // ���� ȸ�� ���� �ٽ� �Է¹ޱ�
//            continue;
//        }
//
//        if (password.length() < 6 || password.length() >= 18)
//        {
//            cout << "����: ��й�ȣ�� 6�ڸ� �̻�, 18�ڸ� �̸��̾�� �մϴ�. �ٽ� �Է����ּ���." << endl;
//            i--; // ���� ȸ�� ���� �ٽ� �Է¹ޱ�
//            continue;
//        }
//
//        // ��� ������ �����ϴ� ��� ȸ�� ���� ����
//        members.push_back(make_pair(member, password));
//    }
//
//    // ȸ�� ������ ���Ͽ� ����
//    saveMembersToFile(members);
//
//    cout << "\n--------ȸ�� ��� ���� �б�--------" << endl;
//    // ȸ�� ����Ʈ�� ���Ͽ��� �о�ͼ� ���
//    readMembersFromFile();
//
//    return 0;
//}
// 실습 1. 회원 명부 작성하기
//1. 사용자에게 3명의 회원에 대한 이름 비밀번호 입력 받기
//2. 사용자로부터 입력된 정보를 member.txt에 기록 (파일 쓰기모드)
//3. member.txt에 저장된 회원명부 출력 (파일 읽기모드)

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    ofstream memberFile("member.txt");

    if (memberFile.fail()) cout << "파일 없음" << endl;

    vector<string> members;

    string member;

    cout << "3명의 회원에 대한 이름, 비밀번호를 순차적으로 입력하세요.\n";

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << "번째 회원 : ";
        getline(cin, member);
        members.push_back(member);

    }

    for (int i = 0; i < members.size(); i++)
    {
        memberFile << members[i] << endl;
    }

    memberFile.close();

    cout << "\n--------회원 명부 파일 읽기--------" << endl;

    for (int i = 0; i < members.size(); i++) 
    {
        cout << members[i] << endl;
    }

    return 0;
}
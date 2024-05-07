// 실습 1. 회원 명부 작성하기
//1. 사용자에게 3명의 회원에 대한 이름 비밀번호 입력 받기
//2. 사용자로부터 입력된 정보를 member.txt에 기록 (파일 쓰기모드)
//3. member.txt에 저장된 회원명부 출력 (파일 읽기모드)
//4. "사용자이름 비밀번호" 양식과는 다르게 값을 1개만 또는 3개 이상 입력할 경우 오류 메시지 + 다시 입력 가능하도록
//5. 비밀번호는 6자리 이상 ~18자리 미만으로 적도록
//6. 정상적으로 입력 받았을 경우에만 파일에 쓰기!

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
         cout << "파일 없음" << endl;
         return 0;
    }
 
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


//// 회원 정보를 파일에 저장하는 함수
//void saveMembersToFile(const vector<pair<string, string>>& members) 
//{
//    ofstream file("member.txt"); // 파일 쓰기 모드로 열기
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
//        cout << "파일을 열 수 없습니다." << endl;
//    }
//}
//
//// 파일에서 회원 정보를 읽어오는 함수
//void readMembersFromFile() 
//{
//    ifstream file("member.txt"); // 파일 읽기 모드로 열기
//
//    if (file.is_open()) 
//    {
//        cout << "회원 리스트:" << endl;
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
//        cout << "파일을 열 수 없습니다." << endl;
//    }
//}
//
//int main()
//{
//    ofstream memberFile("member.txt");
//
//    if (memberFile.fail()) cout << "파일 없음" << endl;
//
//    vector<pair<string, string>> members;
//
//    string member;
//
//    cout << "3명의 회원에 대한 이름, 비밀번호를 순차적으로 입력하세요.\n" << endl;
//
//    for (int i = 0; i < 3; i++)
//    {
//        cout << i + 1 << "번째 회원 : ";
//        getline(cin, member);
//
//        size_t space = member.find(' ');
//        string password = member.substr(space + 1);
//
//        if (space != string::npos && member.find(' ', space + 1) != string::npos)
//        {
//            cout << "오류: 이름 비밀번호를 다시 입력해주세요." << endl;
//            i--; // 이전 회원 정보 다시 입력받기
//            continue;
//        }
//
//        if (password.length() < 6 || password.length() >= 18)
//        {
//            cout << "오류: 비밀번호는 6자리 이상, 18자리 미만이어야 합니다. 다시 입력해주세요." << endl;
//            i--; // 이전 회원 정보 다시 입력받기
//            continue;
//        }
//
//        // 모든 조건을 만족하는 경우 회원 정보 저장
//        members.push_back(make_pair(member, password));
//    }
//
//    // 회원 정보를 파일에 저장
//    saveMembersToFile(members);
//
//    cout << "\n--------회원 명부 파일 읽기--------" << endl;
//    // 회원 리스트를 파일에서 읽어와서 출력
//    readMembersFromFile();
//
//    return 0;
//}
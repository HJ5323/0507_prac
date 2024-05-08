// 실습 2. 회원 명부를 응용한 로그인 기능
//1. 사용자에게 "이름을 입력하세요." 라는 메세지를 출력한 뒤 이름 입력 받기
//2. 사용자에게 "비밀번호를 입력하세요." 라는 메세지를 출력한 뒤 비밀번호 입력 받기
//3. member.txt에서 한줄씩 "이름"과 "비번"을 검사하여 로그인 성공시 "로그인 성공" 실패 시 "로그인 실패" 출력
//4. 여기서 member.txt는 앞 실습에서 만든 회원 명부

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void login(const string& username, const string& password) 
{
    ifstream file("member.txt");  // member.txt 파일에서 회원 명부 읽기


    if (file.fail())
    {
        cout << "파일을 열 수 없습니다." << endl;
        return;
    }

    string line;
    bool logInOK = false;

    while (getline(file, line))  // 파일에서 한 줄씩 읽어와서 이름과 비밀번호 비교
    {
        stringstream ss(line);
        string name, pw;

        if (ss >> name >> pw) // 공백으로 이름과 비밀번호 분리
        {
            if (name == username && pw == password) 
            {
                cout << "로그인 성공!" << endl;
                logInOK = true;
                break;
            }
        }
    }

    if (!logInOK)
    {
        cout << "로그인 실패!" << endl;
    }

    file.close();
}

int main() 
{
    string username, password;

    // 사용자로부터 이름 입력 받기
    cout << "이름을 입력하세요: ";
    getline(cin, username);

    // 사용자로부터 비밀번호 입력 받기
    cout << "비밀번호를 입력하세요: ";
    getline(cin, password);

    // 로그인 시도
    login(username, password);

    return 0;
}

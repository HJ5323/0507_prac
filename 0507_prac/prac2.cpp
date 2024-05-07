// 실습 2. 회원 명부를 응용한 로그인 기능
//1. 사용자에게 "이름을 입력하세요." 라는 메세지를 출력한 뒤 이름 입력 받기
//2. 사용자에게 "비밀번호를 입력하세요." 라는 메세지를 출력한 뒤 비밀번호 입력 받기
//3. member.txt에서 한줄씩 "이름"과 "비번"을 검사하여 로그인 성공시 "로그임 성공" 실패 시 "로그인 실패" 출력
//4. 여기서 member.txt는 앞 실습에서 만든 회원 명부

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// 회원 로그인 함수
bool login(string username, string password) 
{
    ifstream file("member.txt"); // member.txt 파일 열기

    if (file.fail())
    {
        cout << "파일을 열 수 없습니다." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) 
    {
        size_t pos = line.find(' '); // 이름과 비밀번호는 공백으로 구분되어 있음
        if (pos != string::npos) 
        {
            string name = line.substr(0, pos); // 공백 이전까지
            string pw = line.substr(pos + 1); // 공백 이후

            if (name == username && pw == password) 
            {
                file.close();
                return true; // 로그인 성공
            }
        }
    }

    file.close();

    return false; // 로그인 실패
}

int main() 
{
    string username, password;

    cout << "이름을 입력하세요: ";
    cin >> username;

    cout << "비밀번호를 입력하세요: ";
    cin >> password;

    if (login(username, password)) 
    {
        cout << "로그인 성공!" << endl;
    } 

    else 
    {
        cout << "로그인 실패!" << endl;
    }

    return 0;
}
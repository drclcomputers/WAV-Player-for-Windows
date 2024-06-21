#pragma comment(lib, "winmm.lib")


#include<iostream>
#include<windows.h>
#include<mmsystem.h>
#include<thread>
#include<string>

using namespace std;

bool ok = 0;

wstring read() {
    const int bufferSize = 256;
    wchar_t buffer[bufferSize];
    std::wcout << L"Enter path to wav file: ";
    std::wcin.getline(buffer, bufferSize);
    wstring path(buffer);
	return path;
}

void action() {
    cout << "Press enter to stop... ";
    cin.get();
    ok = 0;
    PlaySound(NULL, 0, 0);
}

void play(wstring tr) {
    cout << "Playing...\n\n";
    PlaySound(tr.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}



int main() {
    wstring t = read();

    thread t1(play, t);
    thread t2(action);
    t1.join();
    t2.join();
    

	return 0;
}
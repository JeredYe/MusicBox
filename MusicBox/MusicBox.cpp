// MusicBox.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
//#define max(a,b) (a>b?a:b)
#define Shot 60000/BPM
#define SECTIONNUM 2
int Num = 0;
int BPM = 150;
enum Scale
{
    Rest = 0, C8 = 108, B7 = 107, A7s = 106, A7 = 105, G7s = 104, G7 = 103, F7s = 102, F7 = 101, E7 = 100,
    D7s = 99, D7 = 98, C7s = 97, C7 = 96, B6 = 95, A6s = 94, A6 = 93, G6s = 92, G6 = 91, F6s = 90, F6 = 89,
    E6 = 88, D6s = 87, D6 = 86, C6s = 85, C6 = 84, B5 = 83, A5s = 82, A5 = 81, G5s = 80, G5 = 79, F5s = 78,
    F5 = 77, E5 = 76, D5s = 75, D5 = 74, C5s = 73, C5 = 72, B4 = 71, A4s = 70, A4 = 69, G4s = 68, G4 = 67,
    F4s = 66, F4 = 65, E4 = 64, D4s = 63, D4 = 62, C4s = 61, C4 = 60, B3 = 59, A3s = 58, A3 = 57, G3s = 56,
    G3 = 55, F3s = 54, F3 = 53, E3 = 52, D3s = 51, D3 = 50, C3s = 49, C3 = 48, B2 = 47, A2s = 46, A2 = 45,
    G2s = 44, G2 = 43, F2s = 42, F2 = 41, E2 = 40, D2s = 39, D2 = 38, C2s = 37, C2 = 36, B1 = 35, A1s = 34,
    A1 = 33, G1s = 32, G1 = 31, F1s = 30, F1 = 29, E1 = 28, D1s = 27, D1 = 26, C1s = 25, C1 = 24, B0 = 23,
    A0s = 22, A0 = 21
};
inline int GetNote(int scale)
{
    return 0x00400090 + scale * 0x100;
}
void PlayNote(HMIDIOUT handle, int Note)
{
    midiOutShortMsg(handle, Note);
    cout << "Note "<<++Num<<" " << (Note- 0x00400090)/ 0x100 << endl;
}
class Section
{
public:
    int Notes[32768] = { 0 },Delay[32768] = { 0 };///Delay如果是1就是一整拍，2就是二分音符，以此类推
    int Company[32768] = { 0 };
    int Amount = 0;
    void PushBack(int Note, int Len)
    {
        if (Note)Notes[Amount] = GetNote(Note);
        Delay[Amount] = Len;
        Amount++;
    }
    void AddCompany(int Note)
    {
        Company[Amount - 1] = GetNote(Note);
    }
    void Play()
    {
        HMIDIOUT handle;
        midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);
        for (int i = 0; i < Amount; i++)
        {
            PlayNote(handle, Notes[i]);
            if(Company[i])PlayNote(handle, Company[i]);
            Sleep(Shot / Delay[i]);
        }
        midiOutClose(handle);
    }
};

Section Sections[SECTIONNUM];
#define Add(a,b) Sections[0].PushBack(a,b)
#define AddC(a) Sections[0].AddCompany(a)

void Construct1();//追光者
void Construct2();//星茶会
int main()
{
    Construct2();
    cin;
    Sections[0].Play();
    Sleep(3000);
    return 0;
}

void Construct1()
{
    BPM = 150;
    Sections[0].PushBack(0, 1);
    int i = 2;
    while (i--)
    {
        Sections[0].PushBack(G5, 1);
        if (i == 0)Sections[0].AddCompany(G4);
        Sections[0].PushBack(A5, 1);
        if (i == 0)Sections[0].AddCompany(B3);
        Sections[0].PushBack(B5, 1);
        if (i == 0)Sections[0].AddCompany(G4);
        Sections[0].PushBack(D6, 1);
        Sections[0].AddCompany(A3);
        Sections[0].PushBack(C6, 2);
        Sections[0].AddCompany(E4);
        Sections[0].PushBack(E5, 2);
        Sections[0].PushBack(0, 1);
        Sections[0].AddCompany(C5);
        Sections[0].PushBack(G5, 1);
        Sections[0].PushBack(G5, 1);
        Sections[0].AddCompany(F3);
        Sections[0].PushBack(A5, 1);
        Sections[0].AddCompany(C4);
        Sections[0].PushBack(E5, 2);
        Sections[0].AddCompany(F4);
        Sections[0].PushBack(D5, 2);
        Sections[0].PushBack(C5, 1);
        Sections[0].PushBack(D5, 1);
        Sections[0].AddCompany(G3);
        Sections[0].PushBack(C5, 2);
        Sections[0].AddCompany(D4);
        Sections[0].PushBack(D5, 2);
        Sections[0].PushBack(0, 1);
        Sections[0].AddCompany(B4);
        Sections[0].PushBack(G5, 1);
        Sections[0].PushBack(E5, 1);


        Sections[0].AddCompany(C4);
        Sections[0].PushBack(G5, 1);
        Sections[0].AddCompany(G4);
        Sections[0].PushBack(A5, 1);
        Sections[0].AddCompany(B3);
        Sections[0].PushBack(B5, 1);
        Sections[0].AddCompany(G4);
        Sections[0].PushBack(D6, 1);
        Sections[0].AddCompany(A3);
        Sections[0].PushBack(C6, 2);
        Sections[0].AddCompany(E4);
        Sections[0].PushBack(E5, 2);
        Sections[0].PushBack(0, 1);
        Sections[0].AddCompany(C5);
        Sections[0].PushBack(G5, 1);
        if (i == 1)
        {
            Sections[0].PushBack(G5, 1);
            Sections[0].AddCompany(F3);
            Sections[0].PushBack(A5, 1);
            Sections[0].AddCompany(C4);
            Sections[0].PushBack(E5, 2);
            Sections[0].AddCompany(F4);
            Sections[0].PushBack(D5, 2);
            Sections[0].PushBack(C5, 1);
            Sections[0].PushBack(D5, 1);
            Sections[0].AddCompany(G3);
            Sections[0].PushBack(C5, 2);
            Sections[0].AddCompany(D4);
            Sections[0].PushBack(C5, 2);
            Sections[0].PushBack(B4, 2);
            Sections[0].AddCompany(G4);
            Sections[0].PushBack(C5, 2);
            Sections[0].PushBack(0, 2);
            Sections[0].PushBack(C5, 2);
            Sections[0].PushBack(0, 1);
        }
        else
        {
            Sections[0].PushBack(G5, 1);
            Sections[0].AddCompany(F3);
            Sections[0].PushBack(0, 1);
            Sections[0].AddCompany(C4);
            Sections[0].PushBack(E5, 2);
            Sections[0].AddCompany(E4);
            Sections[0].PushBack(G5, 2);
            Sections[0].PushBack(0, 1);
            Sections[0].PushBack(G5, 1);
            Sections[0].AddCompany(G3);
            Sections[0].PushBack(0, 1);
            Sections[0].AddCompany(C4);
            Sections[0].PushBack(0, 1);
            Sections[0].AddCompany(D4);
            Sections[0].PushBack(0, 1);
            Sections[0].PushBack(F5, 1);
            Sections[0].PushBack(E5, 1);
            Sections[0].PushBack(D5, 1);
            Sections[0].PushBack(C5, 1);
        }
    }

}
void Construct2()
{
    BPM = 100;
    Add(G5, 2);
    Add(G6, 2);
    Add(G6, 2);
    Add(G6, 2);
    int t = 2;
    while (t--)
    {
        Add(G6, 2);
        AddC(F4);
        Add(C6, 2);
        AddC(C5);
        Add(D6, 1);
        AddC(F5);

        Add(G6, 2);
        AddC(G4);
        Add(C6, 2);
        AddC(C5);
        Add(D6, 1);
        AddC(G5);

        Add(G6, 2);
        AddC(A4);
        Add(C6, 2);
        AddC(E5);
        Add(D6, 2);
        AddC(G5);
        Add(A6, 2);

        Add(G6, 2);
        AddC(G4);
        Add(E6, 6);
        AddC(C5);
        Add(G6, 6);
        Add(E6, 6);
        Add(C6, 2);
        AddC(G5);
        Add(G5, 2);

        Add(E6, 2);
        AddC(F4);
        Add(C6, 2);
        AddC(C5);
        Add(G5, 1);
        AddC(F5);

        Add(E6, 2);
        AddC(G4);
        Add(C6, 2);
        AddC(C5);
        Add(G5, 1);
        AddC(G5);

        Add(E6, 2);
        AddC(A4);
        Add(B5, 2);
        AddC(E5);
        Add(G5, 2);
        AddC(G5);
        Add(B5, 2);
        Add(C6, 2);
        AddC(G4);
        if (t)
        {
            Add(D6, 2);
            AddC(C5);
            Add(E6, 2);
            Add(G6, 2);
        }
        else
        {
            Add(0, 1);
            Add(0, 1);
        }

    }
}
//void Play()
//{
//    HMIDIOUT handle;
//    midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);
//    for (int i = 0; i < max(Sections[0].Amount, Sections[0].Amount); i++)
//    {
//        PlayNote(handle, Sections[0].Notes[i], Sections[0].Delay[i]);
//    }
//    midiOutClose(handle);
//}
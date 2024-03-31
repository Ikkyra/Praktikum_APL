#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int nilai;
};

struct mahasiswa mhs[10];

int n = 0;

void create()
{
    cout << "Nama Mahasiswa : ";
    cin.ignore();
    getline(cin, mhs[n].nama);
    cout << "NIM Mahasiswa : ";
    cin >> mhs[n].nim;
    cout << "Nilai : ";
    cin >> mhs[n].nilai;
    n++;
}

void read()
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nama Mahasiswa : " << mhs[i].nama << endl;
        cout << "NIM Mahasiswa : " << mhs[i].nim << endl;
        cout << "Nilai : " << mhs[i].nilai << endl;
        cout << "=======================================" << endl;
    }
}

void update()
{
    string nim_update;
    cout << "Masukan NIM yang ingin diubah : ";
    cin >> nim_update;
    for (int i = 0; i < n; i++)
    {
        if (nim_update == mhs[i].nim)
        {
            try
            {
                while (true)
                {
                    cout << "Nama Mahasiswa Baru : ";
                    cin.ignore();
                    getline(cin, mhs[i].nama);
                    cout << "Nilai : ";
                    if (!(cin >> mhs[i].nilai))
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Inputan Salah" << endl;
                        continue;
                    }
                    else
                    {
                        throw nim_update;
                    }
                }
            }
            catch (string a)
            {
            }
            break;
        }
    }
}

void del()
{
    string nim_delete;
    cout << "Masukan NIM yang ingin dihapus : ";
    cin >> nim_delete;
    for (int i = 0; i < n; i++)
    {
        if (nim_delete == mhs[i].nim)
        {
            for (int j = i; j < n; j++)
            {
                mhs[j].nama = mhs[j + 1].nama;
                mhs[j].nim = mhs[j + 1].nim;
                mhs[j].nilai = mhs[j + 1].nilai;
            }
            n--;
            break;
        }
    }
}

int main()
{
    int pilihan;
    while (true)
    {
        cout << "Menu" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Delete Data" << endl;
        cout << "Pilih : ";
        cin >> pilihan;
        if (pilihan == 1)
        {
            create();
        }
        else if (pilihan == 2)
        {
            read();
        }
        else if (pilihan == 3)
        {
            update();
        }
        else if (pilihan == 4)
        {
            del();
        }
        else
        {
            cout << "Pilihan tidak ada" << endl;
        }
    }
}
//
//  main.cpp
//  C++Database
//
//  Created by Rumahproject.com on 9/15/13.
//  Copyright (c) 2013 Rumahproject.com. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>


using namespace std;

// fungsi untuk menampilkan loading sementara
void loading(char * text){
    cout << "\n";
    cout << "\t" << text << " ";
    //int i = 0;
    for(int o = 0;o<45;o++){
        cout<<">";
        //Sleep(50);
    }
}

// fungsi untuk memecah kalimat menjadi array
void explode(char *kalimat,char hasil[25][25],char separator,int *itung){
    int i, itungs = 0;
    for(i=0;i<strlen(kalimat);i++){
        if(kalimat[i] == separator){
            itungs = 0;
            *itung = *itung + 1;
        }else{
            hasil[*itung][itungs] = kalimat[i];
            itungs++;
        }
    }
}

// fungsi untuk mengubah char ke string
string cstr(char * str){
    string tmp_str(str);
    return tmp_str;
}

// fungsi untuk cek apakah kata awal dalam suatu kalimat
// sama dengan kata yang kita cari
bool startsWith(char *cari, char *kalimat){
    string needle = cstr(cari);
    string text = cstr(kalimat);
    if(text.substr(0,strlen(cari))==cari)
        return true;
    else return false;
}

int main(){
    system("color f0"); // set backgorund terminal
    //loading("Tunggu Sebentar");
    system("cls"); // clearscreen
    
    cout << "\t\t\t+--------------------------------+" << endl;  
	cout << "\t\t\t|  AAAA   PPPPP   PPPPP   SSSSS  |" << endl;  
	cout << "\t\t\t| AA  AA  PP  PP  PP  PP SS      |" << endl;  
	cout << "\t\t\t| AAAAAA  PPPPP   PPPPP   SSSS   |" << endl;  
	cout << "\t\t\t| AA  AA  PP      PP         SS  |" << endl;  
	cout << "\t\t\t| AA  AA  PP      PP     SSSSS   |" << endl;  
	cout << "\t\t\t+--------------------------------+" << endl;  
	cout << "\t\t\t|         DIGITAL LIBRARY        |" << endl;
	cout << "\t\t\t+--------------------------------+" << endl << endl;
	
	char password[4];
    string nama;
login:
    cout<<endl;
    cout<<"\t\t\tLogin Administrator Digital Library "<<endl;
    cout<<"\t\t\t----------------------------------- "<<endl;
    cout<<"\t\t\tUsername : "; cin>>nama;
    cout<<"\t\t\tPassword : "; cin>>password;
    
    if(nama == "apps" && strcmp(password,"1234")==0){
        system("cls");
        cout<<"\n";
        cout<<"\t\t\t+-----------------------------------+"<<endl;
        cout<<"\t\t\t|        Selamat Datang Admin       |"<<endl;
        cout<<"\t\t\t+-----------------------------------+"<<endl;
        cout<<"\n";
    }else{
        cout<<"\t\t\tLogin Gagal ..."<<endl;
        goto login;
    }
	
    string baris;
    string tampung;
    string bacaFile;
    string swapPinjamBuku;
    string swapPeminjam;
    string isiFile;
    
    char tanya;
    char separator = '|';
    char hasil[25][25];
    const char *test;
    ifstream dataBuku("databuku.txt");
    if(dataBuku.is_open()){
        while(!dataBuku.eof()){
            getline(dataBuku,baris);
            tampung += baris+"|";
            bacaFile += " "+baris+"\n";
            isiFile += baris+"\n";
        }
        dataBuku.close();
    }
    int itung = 0;
    test = tampung.c_str();
    char *kalimat = const_cast<char*>(test);
    explode(kalimat,hasil,separator,&itung);
    
    char inpmenu;
    string pinjamBuku = "";
    string kodeBuku;
    string tampungPinjam;
    string namaPeminjam;
    string kembaliBuku;
    
    menu :
    cout << "\t\t\t+-----------------------------------+"<< endl;
    cout << "\t\t\t| Silakan Pilih Menu                |"<< endl;
    cout << "\t\t\t+-----------------------------------+"<< endl;
    cout << "\t\t\t| 1. Pinjam Buku                    |"<< endl;
    cout << "\t\t\t| 2. Daftar Buku                    |"<< endl;
    cout << "\t\t\t| 3. Tambah Koleksi                 |"<< endl;
    cout << "\t\t\t| 4. Pengembalian Buku              |"<< endl;
    cout << "\t\t\t| 5. Selesai                        |"<< endl;
    cout << "\t\t\t+-----------------------------------+"<< endl;
    cout << "\n Pilihan Anda : ";
    cin >> inpmenu;
    cout << endl;
    system("cls");
    
    switch(inpmenu){
        case '1' :
            namaPeminjam = "";
            cout << endl;
            cout << "\t\t\t+-----------------------------------+" << endl;
            cout << "\t\t\t| Menu Pilihan                      |" << endl;
            cout << "\t\t\t+-----------------------------------+" << endl;
            cout << "\t\t\t| 1. PINJAM BUKU                    |" << endl;
            cout << "\t\t\t+-----------------------------------+" << endl;
            
            pinjam :
            cout << bacaFile << endl;
            cout << " Silahkan Masukkan Kode Buku (01 ... n) : ";
            cin >> kodeBuku;
            if(tampung.find(kodeBuku)!=string::npos){
                if(pinjamBuku.find(kodeBuku)!=string::npos){
                    cout << "\n Maaf, sedang dipinjam\n\n";
                    goto pinjam;
                }else{
                    cout << "\n Masukkan Nama Peminjam : ";
                    cin  >> namaPeminjam;
                    pinjamBuku += kodeBuku+",";
                    tampungPinjam += kodeBuku+" \t\t"+namaPeminjam+"\n ";
                    cout << "\n Buku dengan kode " << kodeBuku << " berhasil dipinjam\n\n";
                    system("cls");
                    goto menu;
                }
            }else{
                cout << "\n Maaf, buku dengan kode buku tersebut tidak tersedia\n\n";
                goto pinjam;
            }
            break;
    }
    
    switch(inpmenu){
        case '2' :
            cout << endl;
            cout << "\t\t\t+-----------------------------------+" << endl;
            cout << "\t\t\t| Menu Pilihan                      |" << endl;
            cout << "\t\t\t+-----------------------------------+" << endl;
            cout << "\t\t\t| 2. DAFTAR BUKU                    |" << endl;
            cout << "\t\t\t+-----------------------------------+" << endl;
            cout << endl;
            
            ifstream db("databuku.txt");
            if(db.is_open()){
                while(!db.eof()){
                    getline(db,baris);
                    bacaFile += " "+baris+"\n";
                }
                db.close();
            }
            
            cout << bacaFile << "\n " << endl;
            cout << " Daftar Buku Yang Sedang Dipinjam" << endl;
            cout << " ================================" << endl;
            cout << " Kode Buku \tNama Peminjam\n";
            cout << " " << tampungPinjam;
            cout << "\n\n";
            cout << " Kembali Ke Menu (y/t) ? ";
            cin  >> tanya;
            if(tanya=='y') { system("cls"); goto menu; }
            else system("exit");
            system("pause");
            break;
    }
    
    switch(inpmenu){
        case '3' :
            string kdBk = "";
            string nmBk = "";
            cout << endl;
            cout << "\t\t\t+-----------------------------------+" << endl;
            cout << "\t\t\t| Menu Pilihan                      |" << endl;
            cout << "\t\t\t+-----------------------------------+" << endl;
            cout << "\t\t\t| 3. TAMBAH BUKU                    |" << endl;
            cout << "\t\t\t+-----------------------------------+" << endl;
            cout << endl;
            cout << " Masukkan Kode Buku : ";
            cin  >> kdBk;
            cout << " Masukkan Nama Buku : ";
            cin  >> nmBk;
            
            ofstream fl("databuku.txt");
            if(fl.is_open()){
                fl << isiFile;
                fl << kdBk+" "+nmBk;
                fl.close();
                cout << " Buku telah berhasil ditambahkan. Silahkan lihat Daftar Buku." << endl;
            }else{
                cout << "Maaf, file Data Buku tidak ditemukan";
            }
            
            cout << "\n\n";
            cout << " Kembali Ke Menu (y/t) ? ";
            cin  >> tanya;
            if(tanya=='y') { system("cls"); goto menu; }
            else system("exit");
            system("pause");
            break;
    }
    
    switch(inpmenu){
        case '4' :
            kembaliBuku = "";
            cout << endl;
            cout << "\t\t\t+-----------------------------------+" << endl;
            cout << "\t\t\t| Menu Pilihan                      |" << endl;
            cout << "\t\t\t+-----------------------------------+" << endl;
            cout << "\t\t\t| 4. PENGEMBALIAN BUKU              |" << endl;
            cout << "\t\t\t+-----------------------------------+" << endl;
            cout << endl;
            cout << " Masukkan Kode Buku (01 ... n) : ";
            cin  >> kembaliBuku;
            
            if(pinjamBuku.find(kembaliBuku)!=string::npos){
                char separasi = ',';
                char separsis = '\n';
                
                char result[25][25];
                char rsults[25][25];
                
                int hitung = 0, count = 0;
                const char * pBuku;
                const char * pNama;
                const char * bk;
                
                pBuku = pinjamBuku.c_str();
                pNama = tampungPinjam.c_str();
                bk = kembaliBuku.c_str();
                
                char * bukuP = const_cast<char*>(pBuku);
                char * namaP = const_cast<char*>(pNama);
                char * kb = const_cast<char*>(bk);
                
                explode(bukuP,result,separasi,&hitung);
                explode(namaP,rsults,separsis,&count);
                
                for(int a=0;a<hitung;a++){
                    if(result[a]==kembaliBuku){
                        swapPinjamBuku += "";
                    }else{
                        swapPinjamBuku += cstr(result[a])+",";
                    }
                    
                    if(startsWith(kb,rsults[a])){
                        swapPeminjam += "";
                    }else{
                        swapPeminjam += cstr(rsults[a])+"\n";
                    }
                }
                
                pinjamBuku = "";
                tampungPinjam = "";
                pinjamBuku = swapPinjamBuku;
                tampungPinjam = swapPeminjam;
                
                cout << " Buku dengan kode " << kembaliBuku << " telah dikembalikan";
                cout << "\n\n";
            }else{
                cout << " Maaf, buku dengan kode tersebut belum dipinjam\n\n";
            }
            
            cout << " Kembali Ke Menu (y/t) ? ";
            cin  >> tanya;
            if(tanya=='y') { system("cls"); goto menu; }
            
            system("pause");
            break;
    }
    
    switch(inpmenu){
        case '5' :
            //loading("Terima Kasih ");
            system("exit");
            break;
    }
}

#include "parent.h"
#include "child.h"
#include "relasi.h"
using namespace std;

int main()
{
    char Pilih,pil;
    bool cek = true;
    address_child C;
    address_parent P;
    address_relasi R;
    infotype_parent x;
    infotype_child y;
    List_relasi L;
    Parent G;
    Child N;
    createList(G);
    createList(N);
    createList(L);

    while(cek == true)
    {
        system("cls");
        cout<<"*************************************************"<<endl;
        cout<<"*                   MENU                        *"<<endl;
        cout<<"*************************************************"<<endl;
        cout<<"* 1. Tambah Data                                *"<<endl;
        cout<<"* 2. Hapus Data                                 *"<<endl;
        cout<<"* 3. Lihat Data                                 *"<<endl;
        cout<<"* 4. Relasikan Data                             *"<<endl;
        cout<<"* 5. Edit Data                                  *"<<endl;
        cout<<"* 0. exit                                       *"<<endl;
        cout<<"*                                               *"<<endl;
        cout<<"*************************************************"<<endl;
        cout<<endl;
        cout<<"Masukan Pilihan = "<<endl;
        cin>>Pilih;
        if(Pilih == '1')
        {
            do
            {
                system("cls");
                cout<<"====================================="<<endl;
                cout<<"||           Insert Menu            ||"<<endl;
                cout<<"======================================"<<endl;
                cout<<"|| 1.Tambahkan Data Sosial Media    ||"<<endl;
                cout<<"|| 2.Tambahkan Data Netizen         ||"<<endl;
                cout<<"|| 0.Kembali                        ||"<<endl;
                cout<<"====================================="<<endl;
                cout<<endl;
                cout<<"Masukkan Pilihan = ";
                cin>>pil;
                if(pil == '1')
                {
                    InsertDataGroup(G);
                    getch();
                }
                if(pil == '2'){
                    InsertDataNetizen(N);
                    getch();
                }
            }
            while (pil!='0');
        }else if(Pilih =='2'){
            infotype_parent x;
                system("cls");
                cout<<"====================================="<<endl;
                cout<<"||           Insert Menu            ||"<<endl;
                cout<<"======================================"<<endl;
                cout<<"|| 1.Hapus Data Sosial Media        ||"<<endl;
                cout<<"|| 2.Hapus Data Netizen             || "<<endl;
                cout<<"|| 0.Kembali                        ||"<<endl;
                cout<<"====================================="<<endl;
                cout<<endl;
                cout<<"Masukkan Pilihan = ";
                cin>>pil;
                if(pil == '1'){
                    cout<<"Masukan Nama Socmed Yang Akan Dihapus = ";
                    cin>>x.socmed;
                    DeleteRelasiGroup(L,x);
                    deleteElmParent(G,x);

                }else if(pil=='2'){
                    cout<<"Masukan Nama Netizen Yang Akan Dihapus = ";
                    cin>>y.nama;
                    DeleteRelasiNetizen(L,y);
                    DeleteChild(N,y);
                }

        }
        else if(Pilih == '3')
        {
            do
            {
                system("cls");
                cout<<"================================================================="<<endl;
                cout<<"||                       View Menu                             ||"<<endl;
                cout<<"================================================================="<<endl;
                cout<<"|| 1.Lihat Semua Data Sosial Media                             ||"<<endl;
                cout<<"|| 2.Lihat Semua DataNetizen                                  ||"<<endl;
                cout<<"|| 3.Lihat Semua Relasi                                        ||"<<endl;
                cout<<"|| 4.Lihat Data Social Media Dengan Netizen Tertentu           ||"<<endl;
                cout<<"|| 5.Lihat Data Netizen Dengan Social Media Tertentu           ||"<<endl;
                cout<<"|| 6.Lihat Data Social Media Dengan Member Terbanyak           ||"<<endl;
                cout<<"|| 7.Lihat Data Social Media Dengan Member Paling Sedikit      ||"<<endl;
                cout<<"|| 0.Kembali                                                   ||"<<endl;
                cout<<"================================================================="<<endl;
                cout<<endl;
                cout<<"Masukkan Pilihan = ";
                cin>>pil;
                if(pil == '1'){
                    Print(G);
                }else if(pil == '2'){
                    printInfo(N);
                }else if(pil == '3'){
                    PrintSemuaRelasi(L);
                }else if(pil == '4'){
                    cout<<"Masukan Nama Netizen Yang ingin dicari = ";
                    cin>>y.nama;
                    PrintGroupNetizenTertentu(L,y);
                }else if(pil =='5'){
                    cout<<"Masukan Social Media Yang Ingin Dicari = ";
                    cin>>x.socmed;
                    PrintNetizenGroupTertentu(L,x);
                }else if(pil=='6'){
                      GroupMemberTerbanyak(L);
                }else if(pil=='7'){
                      GroupMemberTersedikit(L,G);
                }
                getch();
            }while (pil!='0');
        }else if(Pilih == '4'){
            InsertRelasi(L,G,N);
            getch();
        }else if(Pilih == '5'){
                system("cls");
                cout<<"================================================================="<<endl;
                cout<<"||                       Edit Menu                             ||"<<endl;
                cout<<"================================================================="<<endl;
                cout<<"|| 1.Edit Data Sosial Media                                    ||"<<endl;
                cout<<"|| 2.Edit Netizen                                              ||"<<endl;
                cout<<"|| 0.Kembali                                                   ||"<<endl;
                cout<<"================================================================="<<endl;
                cout<<"Masukan Pilihan = ";
                cin>>pil;
                if(pil=='1'){
                    cout<<"Masukan Social Media Yang Ingin Diedit = ";
                    cin>>x.socmed;
                    P = findElmParent(G,x);
                    if(P != NULL){
                        editDataSocmed(G,P);
                    }else{
                        cout<<"DATA TIDAK DITEMUKAN";
                    }
                }else if(pil =='2'){
                    cout<<"Mssukan Nama Netizen Yang Ingin Diedit = ";
                    cin>>y.nama;
                    C = findElmChild(N,y);
                    if(C!=NULL){
                        editDataNetizen(N,C);
                    }else{
                        cout<<"DATA TIDAK DITEMUKAN";
                    }
                }
        }
        else if(Pilih == '0')
        {
            cek = false;
        }
    }

    return 0;

}

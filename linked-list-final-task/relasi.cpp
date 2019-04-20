#include "relasi.h"
#include "parent.h"
#include "child.h"

void createList(List_relasi &L)
{
    first(L) = NULL;
}
address_relasi alokasi(address_child C, address_parent P)
{
    address_relasi R = new elmlist_relasi;
    group(R)    = P;
    netizen(R)  = C;
    next(R) = NULL;
    return R;
}

void dealokasi(address_relasi &P)
{
    delete P;
}

void insertFirst(List_relasi &L, address_relasi P)
{
    if(first(L) != NULL)
    {
        next(P) = first(L);
        first(L) = P;
    }
    else
    {
        first(L)=P;
    }

}

void insertLast(List_relasi &L, address_relasi P)
{
    if(first(L)==NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        address_relasi q = first(L);
        while(next(q)!=NULL)
        {
            q = next(q);
        }
        next(q) = P;
    }
}

void deleteFirst(List_relasi &L, address_relasi &P)
{
    if(first(L)!=NULL)
    {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;

    }

}

void deleteLast(List_relasi &L, address_relasi &P)
{
    if(first(L)!=NULL)
    {
        P = first(L);
        if(next(P)==NULL)
        {
            deleteFirst(L,P);
        }
        else
        {
            cout<<"CEK2";
            while(next(next(P))!=NULL)
            {
                P = next(P);
            }
            address_relasi Q = P;
            P = next(Q);
            next(Q) = NULL;
        }
    }
}

void deleteAfter(List_relasi &L,address_relasi prec, address_relasi &P)
{
    if(first(L) != NULL)
    {
        address_relasi Q = first(L);
        while(next(Q) != NULL)
        {
            Q = next(Q);
        }
        if(next(prec) == Q)
        {
            deleteLast(L,P);
        }
        else if(next(prec) != NULL)
        {
            P = next(prec);
            next(prec) = next(P);
            next(P) = NULL;
        }
    }
}

address_relasi FindSocmed(List_relasi L, infotype_parent x)
{
    if(first(L)!=NULL)
    {
        address_relasi P = first(L);
        while(P != NULL && info(group(P)).socmed != x.socmed)
        {
            P = next(P);
        }
        return P;
    }
}

address_relasi FindNetizen(List_relasi L, infotype_child x)
{
    if(first(L) != NULL)
    {
        address_relasi P = first(L);
        while(P != NULL && info(netizen(P)).nama != x.nama)
        {
            P = next(P);
        }
        return P;
    }
}

bool isRelation(List_relasi L, infotype_child C, infotype_parent P)
// This Code made By FNZ
{
    address_relasi S = first(L);

    if(S!=NULL)
    {
        getch();
        while(S!=NULL )
        {
            if(info(group(S)).socmed==P.socmed && info(netizen(S)).nama==C.nama)
            {
                return true;
            }
            else
            {
                S = next(S);
            }
        }
        if(S==NULL)
        {
            return false;
        }

    }
    else
    {
        return false;
    }
}
void InsertRelasi(List_relasi &R, Parent &A, Child &B)
{
    system("cls");
    infotype_child N;
    infotype_parent G;
    address_child Q;
    address_parent P;
    address_relasi S;
    cout<<"Masukan Nama Social Media Yang Ingin Dihubungkan = "<<endl;
    cin>>G.socmed;
    P = findElmParent(A, G);
    if(P != NULL)
    {
        cout<<"Masukan Nama Netizen Yang Ingin Dihubungkan ="<<endl;
        cin>>N.nama;
        Q = findElmChild(B, N);
        if(Q != NULL)
        {
            S = alokasi(Q,P);
            if(isRelation(R,N,G))
            {
                cout<<"DATA SUDAH PERNAH DIHUBUNGKAN";
            }
            else
            {
                insertLast(R,S);
                info(P).member++;
                info(Q).member++;

                system("cls");
                cout<<"============================="<<endl;
                cout<<"|  BERHASIL MENAMBAH RELASI |"<<endl;
                cout<<"============================="<<endl;

            }
        }
        else
        {
            cout<<"============================="<<endl;
            cout<<"|  GAGAL MENAMBAH RELASI    |"<<endl;
            cout<<"============================="<<endl;

        }
    }
    else
    {
        cout<<"============================="<<endl;
        cout<<"|  GAGAL MENAMBAH RELASI    |"<<endl;
        cout<<"============================="<<endl;

    }

}

void DeleteRelasiGroup(List_relasi &L, infotype_parent X)
{
    address_relasi P = FindSocmed(L,X);
    address_relasi C = first(L);
    address_relasi K;
    if(P != NULL)
    {
        while(C!=NULL)
        {
            if(info(group(C)).socmed== X.socmed)
            {
                info(netizen(C)).member--;
                if(C==first(L))
                {
                    C = next(C);
                    deleteFirst(L,K);
                }
                else if(next(C)==NULL)
                {
                    C = next(C);
                    deleteLast(L,K);
                }
                else
                {
                    address_relasi S = first(L);
                    while(next(S) != C)
                    {
                        S = next(S);
                    }
                    C = next(C);
                    deleteAfter(L,S,K);
                }
                dealokasi(K);
            }
            else
            {
                C = next(C);
            }

        }
    }
    else
    {
        cout<<"SOCIAL MEDIA TIDAK TERDAFTAR";
    }
}


void DeleteRelasiNetizen(List_relasi &L, infotype_child X)
{
    address_relasi P = FindNetizen(L,X);
    address_relasi C = first(L);
    address_relasi K;
    if(P != NULL)
    {
        while(C!=NULL)
        {
            if(info(netizen(C)).nama == X.nama)
            {
                info(group(C)).member--;
                if(C == first(L))
                {
                    C = next(C);
                    deleteFirst(L,K);
                }
                else if(next(C) == NULL)
                {
                    C = next(C);
                    deleteLast(L,K);
                }
                else
                {
                    address_relasi S = first(L);
                    while(next(S) != C)
                    {
                        S = next(S);
                    }
                    C = next(C);
                    deleteAfter(L,S,K);
                }
                dealokasi(K);
            }
            else
            {
                C = next(C);
            }
        }

    }
    else
    {
        cout<<"SOCIAL MEDIA TIDAK TERDAFTAR";
    }
}



void PrintSemuaRelasi(List_relasi L)
{
    if (first(L) == NULL)
    {
        cout<<"DATA MASIH KOSONG"<<endl;
    }
    else
    {
        address_relasi P = first(L);
        while(P !=NULL)
        {
            system("cls");
            cout<<"=============================="<<endl;
            cout<<"||      Social Media        ||"<<endl;
            cout<<"=============================="<<endl;
            cout<<"|| Social Media   = "<<info(group(P)).socmed<<endl;
            cout<<"|| Jenis Socmed   = "<<info(group(P)).Jenis<<endl;
            cout<<"|| Tanggal Dibuat = "<<info(group(P)).tglGabung<<endl;
            cout<<"|| Jumlah Member  = "<<info(group(P)).member<<endl;
            cout<<"==============================="<<endl;
            cout<<"||     Netizen               ||"<<endl;
            cout<<"==============================="<<endl;
            cout<<"|| Nama Netizen   = "<<info(netizen(P)).nama<<endl;
            cout<<"|| Umur Netizen   = "<<info(netizen(P)).umur<<endl;
            cout<<"|| Hobi Netizen   = "<<info(netizen(P)).hobi<<endl;
            cout<<"|| Jumlah Socmed  = "<<info(netizen(P)).member<<endl;
            cout<<endl;
            P = next(P);
            getch();
        }
    }
}

void PrintGroupNetizenTertentu(List_relasi L, infotype_child X)
{
    if(first(L)!=NULL)
    {
        address_relasi P = first(L);
        while(P != NULL)
        {
            if(info(netizen(P)).nama == X.nama)
            {
                system("cls");
                cout<<"==============================="<<endl;
                cout<<"||     Netizen               ||"<<endl;
                cout<<"==============================="<<endl;
                cout<<"|| Nama Netizen   = "<<info(netizen(P)).nama<<endl;
                cout<<"=============================="<<endl;
                cout<<"||      Social Media        ||"<<endl;
                cout<<"=============================="<<endl;
                cout<<"|| Social Media   = "<<info(group(P)).socmed<<endl;
                cout<<"|| Jenis Socmed   = "<<info(group(P)).Jenis<<endl;
                cout<<"|| Tanggal Dibuat = "<<info(group(P)).tglGabung<<endl;
                cout<<"|| Jumlah Member  = "<<info(group(P)).member<<endl;
                cout<<"=============================="<<endl;

                getch();
            }
            P = next(P);
        }
    }
    else
    {
        cout<<"DATA MASIH KOSONG";
    }
}

void PrintNetizenGroupTertentu(List_relasi L, infotype_parent X)
{
    if(first(L)!=NULL)
    {
        address_relasi P = first(L);
        while(P != NULL)
        {
            if(info(group(P)).socmed == X.socmed)
            {
                system("cls");
                cout<<"=============================="<<endl;
                cout<<"||      Social Media        ||"<<endl;
                cout<<"=============================="<<endl;
                cout<<"|| Social Media   = "<<info(group(P)).socmed<<endl;
                cout<<"==============================="<<endl;
                cout<<"||     Netizen               ||"<<endl;
                cout<<"==============================="<<endl;
                cout<<"|| Nama Netizen   = "<<info(netizen(P)).nama<<endl;
                cout<<"|| Umur Netizen   = "<<info(netizen(P)).umur<<endl;
                cout<<"|| Hobi Netizen   = "<<info(netizen(P)).hobi<<endl;
                cout<<"|| Jumlah Socmed  = "<<info(netizen(P)).member<<endl;
                cout<<"==============================="<<endl;
                getch();
            }
            P = next(P);
        }

    }
    else
    {
        cout<<"DATA MASIH KOSONG";
    }
}

void GroupMemberTerbanyak(List_relasi R)
{
    if(first(R)!=NULL)
    {
        address_relasi tmp,P,Q;
        P = first(R);
        Q = first(R);
        cout<<info(group(P)).member;
        if(P != NULL)
        {
            while(P != NULL)
            {
                while(Q != NULL)
                {
                    if(info(group(P)).member >= info(group(Q)).member)
                    {
                        tmp = P;
                    }
                    else
                    {
                        tmp = Q;
                    }
                    Q = next(Q);
                }
                P = next(P);
            }
            P = first(R);
            while(P!= NULL)
            {
                if(info(group(P)).member == info(group(tmp)).member)
                {
                    system("cls");
                    cout<<"=============================="<<endl;
                    cout<<"||      Social Media        ||"<<endl;
                    cout<<"=============================="<<endl;
                    cout<<"|| Social Media   = "<<info(group(P)).socmed<<endl;
                    cout<<"|| Jenis Socmed   = "<<info(group(P)).Jenis<<endl;
                    cout<<"|| Tanggal Dibuat = "<<info(group(P)).tglGabung<<endl;
                    cout<<"|| Jumlah Member  = "<<info(group(P)).member<<endl;
                    cout<<"=============================="<<endl;
                    cout<<"||     Netizen               ||"<<endl;
                    cout<<"==============================="<<endl;
                    cout<<"|| Nama Netizen   = "<<info(netizen(P)).nama<<endl;
                    cout<<"|| Umur Netizen   = "<<info(netizen(P)).umur<<endl;
                    cout<<"|| Hobi Netizen   = "<<info(netizen(P)).hobi<<endl;
                    cout<<"==============================="<<endl;
                    getch();
                }
                P = next(P);
            }

        }
    }
}
void GroupMemberTersedikit(List_relasi R, Parent G)
{
    if(first(R)!=NULL)
    {
        address_relasi tmp,P,Q;
        address_parent S;
        S = first(G);
        P = first(R);
        Q = first(R);
        int mn=9999999999;
        int cek=1;
        if(P != NULL)
        {
            while(P != NULL)
            {
                if(info(group(P)).member<=mn)
                {
                    mn = info(group(P)).member;
                }
                P = next(P);
            }

            do
            {
                if(info(S).member==0)
                {
                    cek = 0;
                }
                S = next(S);
            }
            while(S!=first(G));

            if(cek != 0)
            {
                P = first(R);
                while(P!= NULL)
                {
                    if(info(group(P)).member == mn)
                    {
                        system("cls");
                        cout<<"=============================="<<endl;
                        cout<<"||      Social Media        ||"<<endl;
                        cout<<"=============================="<<endl;
                        cout<<"|| Social Media   = "<<info(group(P)).socmed<<endl;
                        cout<<"|| Jenis Socmed   = "<<info(group(P)).Jenis<<endl;
                        cout<<"|| Tanggal Dibuat = "<<info(group(P)).tglGabung<<endl;
                        cout<<"|| Jumlah Member  = "<<info(group(P)).member<<endl;
                        cout<<"=============================="<<endl;
                        cout<<"||     Netizen               ||"<<endl;
                        cout<<"==============================="<<endl;
                        cout<<"|| Nama Netizen   = "<<info(netizen(P)).nama<<endl;
                        cout<<"|| Umur Netizen   = "<<info(netizen(P)).umur<<endl;
                        cout<<"|| Hobi Netizen   = "<<info(netizen(P)).hobi<<endl;
                        cout<<"==============================="<<endl;
                        getch();
                    }
                    P = next(P);
                }
            }
            else
            {
                S = first(G);
                do
                {
                    if(info(S).member == 0)
                    {
                        system("cls");
                        cout<<"=============================="<<endl;
                        cout<<"||      Social Media        ||"<<endl;
                        cout<<"=============================="<<endl;
                        cout<<"|| Social Media   = "<<info(S).socmed<<endl;
                        cout<<"|| Jenis Socmed   = "<<info(S).Jenis<<endl;
                        cout<<"|| Tanggal Dibuat = "<<info(S).tglGabung<<endl;
                        cout<<"|| Jumlah Member  = "<<info(S).member<<endl;
                        cout<<"=============================="<<endl;
                        getch();
                    }
                    S = next(S);
                }
                while(S!=first(G));
            }



        }
//
    }
}






#include "child.h"
#include "parent.h"
void createList(Child &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x)
{
    address_child P = new ElemenChild;
    info(P) = x;
    info(P).member = 0;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(Child &L, address_child P)
{
    if(first(L) == NULL)
    {
        last(L) = P;
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }

}

void insertAfter(Child &C, address_child Prec, address_child P)
{
    if(first(C) != NULL)
    {
        if(Prec == last(C))
        {
            insertLast(C,P);
        }
        else
        {
            prev(next(Prec)) = P;
            next(P) = next(Prec);
            prev(P) = Prec;
            next(Prec) = P;
        }
    }

}

void insertLast(Child &L, address_child P)
{
    if(first(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }

}

void deleteFirst(Child &L, address_child &p)
{
    if(first(L) != NULL)
    {
        p = first(L);
        if(next(first(L)) == NULL)
        {
            first(L) = NULL;
            last(L) = NULL;

        }
        else if(first(L) == last(L))
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            first(L) = next(first(L));
            prev(first(L)) = first(L);
            next(p) = NULL;
            prev(p) = NULL;
        }
    }
}

void deleteLast(Child &L, address_child& p)
{
    if(first(L) != NULL)
    {
        if(first(L) == last(L))
        {
            deleteFirst(L,p);
        }
        else
        {
            p = last(L);
            last(L) = prev(p);
            next(last(L)) = NULL;
            next(p) = NULL;
            prev(p) = NULL;
        }
    }
}

void deleteAfter(Child &L, address_child Prec, address_child &P)
{
    if(first(L) != NULL && next(Prec)!=NULL)
    {
        if(next(Prec) == last(L))
        {
            deleteLast(L,P);
        }
        else
        {
            P = next(Prec);
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

void DeleteChild(Child &L, infotype_child x)
{
    address_child P,Q;

    P = findElmChild(L,x);
    if (P !=NULL)
    {
        if (P==first(L))
        {
            deleteFirst(L,P);
        }
        else
        {
            Q = first(L);
            while (next(Q)!= P)
            {
                Q=next(Q);
            }
            deleteAfter(L,Q,P);
        }
    }
}

void sorting(Child &L,address_child P)
{
    if(first(L) != NULL)
    {
        if(info(P).umur<=info(first(L)).umur)
        {
            insertFirst(L,P);
        }
        else if(info(P).umur>=info(last(L)).umur)
        {
            insertLast(L,P);
        }
        else
        {
            address_child Q = first(L);
            while(info(P).umur > info(next(Q)).umur)
            {
                Q = next(Q);
            }
            insertAfter(L,Q,P);

        }
    }
    else
    {
        insertFirst(L,P);
    }
}

address_child findElmChild(Child L, infotype_child x)
{
    if(first(L) != NULL)
    {
        address_child P = first(L);
        while(P != NULL && info(P).nama != x.nama)
        {
            P = next(P);
        }
        return P;
    }
}

void InsertDataNetizen(Child &L)
{
    system("cls");
    infotype_child x;
    address_child P;
    address_child C;

    cout<<"========================"<<endl;
    cout<<"|   Pengisian Data     |"<<endl;
    cout<<"========================"<<endl;
    cout<<"Masukan Nama Netizen  = ";
    cin>>x.nama;
    cout<<"Masukan Umur Netizen  = ";
    cin>>x.umur;
    cout<<"Masukan Hobi Netizen  = ";
    cin>>x.hobi;
    cout<<endl;
    P = alokasi(x);
    C = findElmChild(L,x);
    if(C!=NULL)
    {
        cout<<"=========================="<<endl;
        cout<<"|   DATA GAGAL TERDAFTAR |"<<endl;
        cout<<"=========================="<<endl;

    }
    else
    {
        sorting(L,P);
        system("cls");
        cout<<"============================="<<endl;
        cout<<"|  BERHASIL MENAMBAH DATA   |"<<endl;
        cout<<"============================="<<endl;
    }

}

void printInfo(Child L)
{
    if(first(L) == NULL)
    {
        cout << "List Kosong";
    }
    else
    {
        address_child P = first(L);
        while(P != NULL)
        {
            cout<<"Nama Netizen          = "<<info(P).nama<<endl;
            cout<<"Umur Netizen          = "<<info(P).umur<<endl;
            cout<<"Hobi Netizen          = "<<info(P).hobi<<endl;
            cout<<"Jumlah Socmed Netizen = "<<info(P).member<<endl;
            P = next(P);
        }
        cout << endl;
    }
}

void CekUmur(Child &L, address_child P)
{
    address_child Q,S,R;
    Q = first(L);
    S = first(L);

    if (P !=NULL)
    {
        if (P==first(L))
        {
            deleteFirst(L,R);
        }
        else
        {
            Q = first(L);
            while (next(Q)!= P)
            {
                Q=next(Q);
            }
            deleteAfter(L,Q,R);
        }
    }

    if(info(R).umur < info(first(L)).umur)
    {
        insertFirst(L,R);
    }
    else if(info(R).umur > info(last(L)).umur)
    {
        insertLast(L,R);
    }
    else
    {
        while(info(R).umur > info(next(S)).umur)
        {
            S = next(S);
        }
        insertAfter(L,S,R);
    }
}

void editDataNetizen(Child &L, address_child P)
{
    infotype_child X;
    cout<<"========================"<<endl;
    cout<<"|   Pengeditian Data   |"<<endl;
    cout<<"========================"<<endl;
    cout<<"Masukan Nama Netizen = ";
    cin>>X.nama;
    cout<<"Masukan Hobi Netizen = ";
    cin>>X.hobi;
    cout<<"Masukan Umur Netizen = ";
    cin>>X.umur;
    if(findElmChild(L,X)!=NULL)
    {
        cout<<"NAMA SUDAH TERDAFTAR";
    }
    else
    {
        info(P).nama = X.nama;
        info(P).hobi = X.hobi;
        info(P).umur = X.umur;

        CekUmur(L,P);

        system("cls");
        cout<<"============================="<<endl;
        cout<<"|  BERHASIL MENGEDIT DATA   |"<<endl;
        cout<<"============================="<<endl;
    }
    getch();

}

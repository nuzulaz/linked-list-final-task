#include "parent.h"

address_parent Alokasi(infotype_parent x)
{
    address_parent P = new Elmparent;
    info(P) = x;
    info(P).member = 0;
    next(P) = NULL;
    return P;
}
void dealokasi(address_parent &P)
{
    delete P;
}

void createList(Parent &L)
{
    first(L) = NULL;
}

void Print(Parent L)
{
    if(first(L) == NULL)
    {
        cout << "List Kosong";
    }
    else
    {
        address_parent P = first(L);
        while(next(P) != first(L))
        {

            cout <<"Social Media       = "<<info(P).socmed <<endl;;
            cout <<"Jenis Social Media = "<<info(P).Jenis <<endl;;
            cout <<"Tanggal Dibuat     = "<<info(P).tglGabung <<endl;
            cout <<"Jumlah Member      = "<<info(P).member<<endl;
            P = next(P);
        }
        cout <<"Social Media       = "<<info(P).socmed <<endl;;
        cout <<"Jenis Social Media = "<<info(P).Jenis <<endl;;
        cout <<"Tanggal Dibuat     = "<<info(P).tglGabung <<endl;
        cout <<"Jumlah Member      = "<<info(P).member<<endl;

    }
    cout << endl;
}


void insertFirst(Parent &L, address_parent p)
{
    address_parent q = NULL;
    q = first(L);
    if(first(L) == NULL)
    {
        first(L) = p;
        next(p) = first(L);
    }
    else
    {
        while (next(q) != first(L))
        {
            q = next(q);
        }
        next(p) = first(L);
        next(q) = p;
        first(L) = p;
    }

    system("cls");
    cout<<"============================="<<endl;
    cout<<"|  BERHASIL MENAMBAH DATA   |"<<endl;
    cout<<"============================="<<endl;

}

void insertLast(Parent &L, address_parent p)
{
    address_parent q = NULL;
    q = first(L);
    if(first(L) == NULL)
    {
        insertFirst(L,p);
    }
    else
    {
        while (next(q) != first(L))
        {
            q = next(q);
        }
        next(q) = p;
        next(p) = first(L);
    }


    system("cls");
    cout<<"============================="<<endl;
    cout<<"|  BERHASIL MENAMBAH DATA   |"<<endl;
    cout<<"============================="<<endl;

}

void insertAfter(Parent &L, address_parent Prec, address_parent p)
{
    if(first(L) == NULL)
    {
        insertFirst(L,p);
    }
    else if(next(Prec)==first(L))
    {
        insertLast(L,p);
    }
    else
    {
        next(p) = next(Prec);
        next(Prec) = p;
    }

    system("cls");
    cout<<"============================="<<endl;
    cout<<"|  BERHASIL MENAMBAH DATA   |"<<endl;
    cout<<"============================="<<endl;

}

void DeleteFirst(Parent &L, address_parent &P)
{
    if(first(L) != NULL)
    {
        if(next(first(L)) == first(L))
        {
            P = first(L);
            first(L) = NULL;
        }
        else
        {
            address_parent q = first(L);
            while(next(q) != first(L))
            {
                q = next(q);
            }
            P = first(L);
            next(q) = next(P);
            first(L) = next(P);
            next(P) = NULL;
        }
    }
}

void DeleteLast(Parent &L, address_parent &p)
{
    address_parent q;
    if(first(L) != NULL)
    {
        if(next(first(L)) == first(L))
        {
            DeleteFirst(L,p);
        }
        else
        {
            p = first(L);
            q = first(L);
            while (next(p) != first(L))
            {
                q = p;
                p = next(p);
            }
            next(q) = first(L);
            next(p) = NULL;
        }
    }
    else
    {
        p = first(L);
    }
}

void DeleteAfter(Parent &L, address_parent Prec, address_parent &P)
{
    if(first(L) != NULL)
    {
        if(next(Prec)==first(L))
        {
            DeleteLast(L,P);
        }
        else if(next(first(L))==first(L))
        {
            DeleteFirst(L,P);
        }
        else
        {
            P = next(Prec);
            next(Prec) = next(P);
            next(P) = NULL;
        }
    }
}

void deleteElmParent(Parent &L, infotype_parent x)
{
    address_parent q,p;
    p = findElmParent(L,x);
    if(p == NULL)
    {
        cout<<"GROUP TIDAK ADA"<<endl;
    }
    else
    {
        if (p == first(L))
        {
            DeleteFirst(L,p);
        }
        else if (next(p) == first(L))
        {
            DeleteLast(L,p);
        }
        else
        {
            q = first(L);
            while (next(q) != p)
            {
                q = next(q);
            }
            DeleteAfter(L,q,p);
        }
    }
}

address_parent findElmParent(Parent L, infotype_parent x)
{
    if(first(L)!=NULL)
    {
        address_parent P = first(L);
        while(next(P)!=first(L) && info(P).socmed!=x.socmed)
        {
            P = next(P);
        }
        if(info(P).socmed == x.socmed)
        {
            return P;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }

}

void InsertDataGroup(Parent &L)
{
    system("cls");
    infotype_parent x;
    address_parent P;
    address_parent C;
    char pil;

    cout<<"========================"<<endl;
    cout<<"|   Pengisian Data     |"<<endl;
    cout<<"========================"<<endl;
    cout<<"Masukan Nama Social Meda  = ";
    cin>>x.socmed;
    cout<<"Masukan Tanggal Dibuat    = ";
    cin>>x.tglGabung;
    cout<<"Masukan Tipe Social Media = ";
    cin>>x.Jenis;
    P = Alokasi(x);
    cout<<endl;
    C = findElmParent(L,x);
    if(C!=NULL)
    {
        cout<<"=========================="<<endl;
        cout<<"|   DATA GAGAL TERDAFTAR |"<<endl;
        cout<<"=========================="<<endl;

    }
    else
    {

        cout<<"===================="<<endl;
        cout<<"|  Menu   Insert   |"<<endl;
        cout<<"===================="<<endl;
        cout<<"|1.Insert First    |"<<endl;
        cout<<"|2.Insert Last     |"<<endl;
        cout<<"|3.Insert After    |"<<endl;
        cout<<"|0.Back            |"<<endl;
        cout<<"===================="<<endl;
        cout<<"Masukan Pilihan = ";
        cin>>pil;
        if(pil=='1')
        {
            insertFirst(L,P);
        }
        else if(pil=='2')
        {
            insertLast(L,P);
        }
        else if(pil=='3')
        {
            cout<<"Masukan Setelah Socmed Apa ? ";
            cin>>x.socmed;
            if(findElmParent(L,x)==NULL)
            {
                cout<<"SOCMED TIDAK DITEMUKAN";
            }
            else
            {
                insertAfter(L,findElmParent(L,x),P);

            }
        }
    }

}

void editDataSocmed(Parent &L, address_parent P){
    infotype_parent x;
    cout<<"========================"<<endl;
    cout<<"|   Pengeditian Data   |"<<endl;
    cout<<"========================"<<endl;
    cout<<"Masukan Nama Social Meda  = ";
    cin>>x.socmed;
    cout<<"Masukan Tanggal Dibuat    = ";
    cin>>x.tglGabung;
    cout<<"Masukan Tipe Social Media = ";
    cin>>x.Jenis;

     if(findElmParent(L,x)!=NULL)
    {
        cout<<"SOCMED SUDAH TERDAFTAR";
    }
    else
    {
        info(P).socmed = x.socmed;
        info(P).tglGabung = x.tglGabung;
        info(P).Jenis = x.Jenis;

        system("cls");
        cout<<"============================="<<endl;
        cout<<"|  BERHASIL MENGEDIT DATA   |"<<endl;
        cout<<"============================="<<endl;
    }
    getch();

    system("cls");
    cout<<"============================="<<endl;
    cout<<"|  BERHASIL MENGEDIT DATA   |"<<endl;
    cout<<"============================="<<endl;
    getch();
}






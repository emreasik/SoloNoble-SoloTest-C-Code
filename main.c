#include <stdio.h>
#include <stdlib.h>

//EMRE ASIK
//180101015
//SOLO TEST PROJE

void masagiris(char dizi[][7])  // Baslangicta karsimiza cikacak masa
{
    int i,j;
    int xekseni=1;

    printf("\t    ");

    for(i=0;i<7;i++)
    printf("%d   ",xekseni++);

    printf("\n");

    printf("\t    ");

    for(i=0;i<7;i++)
    printf("%c   ",95); // "_" nin decimal kodu

    printf("\n\n");

    for(i=0;i<7;i++)
    {
        printf("\t");
        printf("%d | ",i+1);

        for(j=0;j<7;j++)
            {
            if(dizi[i][j]!=2)
            {
                system("color 4");          // RGB efekti
                system("color 2");
                system("color 3");
                printf("%c   ",dizi[i][j]);
            }
            else
            {
            printf("    ");
            }
        }
        printf("\n\n");
    }
    system("color 7");
}

void masa(char dizi[][7])  //Oyunun oynandigi masa
{
    int i,j;
    int xekseni=1;

    printf("\t    ");

    for(i=0;i<7;i++)
    printf("%d   ",xekseni++);

    printf("\n");

    printf("\t    ");

    for(i=0;i<7;i++)
    printf("%c   ",95);

    printf("\n\n");

    for(i=0;i<7;i++)
    {
        printf("\t");
        printf("%d | ",i+1);

        for(j=0;j<7;j++)
            {
            if(dizi[i][j]!=2)
            {
            printf("%c   ",dizi[i][j]);
            }
            else
            {
            printf("    ");
            }
        }
        printf("\n\n");
    }
}

int kalan(char dizi[][7])  //kalan tas hesaplamasi
{
    int i,j;
    int count=0;

    for(i=0;i<7;i++)
        {
        for(j=0;j<7;j++)
            {
            if(dizi[i][j]=='o')
                count=count+1;
            }

        }
        return count;
}

void hareket(char dizi[][7])
{
    int x1,x2;
    int y1,y2;

    printf("Lutfen Hareket Ettireceginiz Tasin X Eksenindeki Rakamini Giriniz: ");
    scanf("%d",&x1);
    printf("Lutfen Hareket Ettireceginiz Tasin Y Eksenindeki Rakamini Giriniz: ");
    scanf("%d",&y1);

    printf("Lutfen Hareket Ettirmek Istediginiz Noktanin X Eksenindeki Rakamini Giriniz: ");
    scanf("%d",&x2);
    printf("Lutfen Hareket Ettirmek Istediginiz Noktanin Y Eksenindeki Rakamini Giriniz: ");
    scanf("%d",&y2);


        if(dizi[y1-1][x1-1]=='o' && dizi[y1-1][x1]=='o' && dizi[y2-1][x2-1]=='.' && x2-x1==2 && y2-y1==0) //Satir Hareketi Soldan Saga
        {
            dizi[y1-1][x1-1]='.';
            dizi[y1-1][x1]='.';
            dizi[y2-1][x2-1]='o';
              system("cls");
        }
        else if(dizi[y1-1][x1-1]=='o' && dizi[y1-1][x1-2]=='o' && dizi[y2-1][x2-1]=='.' && x1-x2==2 && y2-y1==0) //Satir Hareketi Sagdan Sola
        {
            dizi[y1-1][x1-1]='.';
            dizi[y1-1][x1-2]='.';
            dizi[y2-1][x2-1]='o';
              system("cls");
        }
        else if(dizi[y1-1][x1-1]=='o' && dizi[y1][x1-1]=='o' && dizi[y2-1][x2-1]=='.' && y2-y1==2 && x1-x2==0) //Sutun Hareketi Yukaridan Asagi
        {
            dizi[y1-1][x1-1]='.';
            dizi[y1][x1-1]='.';
            dizi[y2-1][x2-1]='o';
              system("cls");
        }
        else if(dizi[y1-1][x1-1]=='o' && dizi[y1-2][x1-1]=='o' && dizi[y2-1][x2-1]=='.' && y1-y2==2 && x1-x2==0) //Sutun Hareketi Asagidan Yukari
        {
            dizi[y1-1][x1-1]='.';
            dizi[y1-2][x1-1]='.';
            dizi[y2-1][x2-1]='o';
              system("cls");
        }
        else //Hatalı Nokta Seciminde Cikacak Hata Mesaji
        {
              system("cls");
            printf(" ___________________________________\n");
            printf("|                                   |\n");
            printf("| Lutfen Gecerli Bir Nokta Seciniz! |\n");
            printf("|___________________________________|\n\n");
        }
}

int puanlama(int sutun,int satir,int kalan)
{
    int sonuc;
                if(sutun==1 && satir==1)
                        {
                            printf("Yapilabilecek Hamle Kalmadi\n");
                            printf("-Oyun Bitti-\n\n");
                            printf("Kalan Tas Sayisi: %d\n",kalan);
                            printf("Dereceniz: ");
                            sonuc=kalan;

                            if(sonuc==1)
                            printf("COK IYI\n");
                            else if(sonuc==2)
                            printf("IYI\n");
                            else if(sonuc==3)
                            printf("NORMAL\n");
                            else if(sonuc==4)
                            printf("FENA DEGIL\n");
                            else if(sonuc==5)
                            printf("KOTU\n");
                            else if(sonuc>=6)
                            printf("COK KOTU\n");
                            return 1;
                        }
                    return 0;
}

int bitis(char dizi[][7])
{
    int k,z;
    int sutun,satir,kal;

                        satir=1;
                        sutun=1;
                        for(z=0;z<7;z++)
                        {
                            for(k=0;k<7;k++)
                            {
                                if((dizi[k][z]=='.' && dizi[k+1][z]=='o' && dizi[k+2][z]=='o') || (dizi[k][z]=='o' && dizi[k+1][z]=='o' && dizi[k+2][z]=='.'))
                                    {
                                        sutun=0;
                                    }

                                else if((dizi[z][k]=='.' && dizi[z][k+1]=='o' && dizi[z][k+2]=='o') || (dizi[z][k]=='o' && dizi[z][k+1]=='o' && dizi[z][k+2]=='.'))
                                    {
                                        satir=0;
                                    }
                            }
                        }

                        kal=kalan(dizi);
                        if(puanlama(sutun,satir,kal))
                            return 1;

    return 0;
}


int main()
{
    int devam1; //goto yapısında kullandık
    int sayi; //Tema Secimi
    int i,k;
    char isim[20];
    char dizi[7][7]={{2,2,'o','o','o',2,2},{2,2,'o','o','o',2,2},{'o','o','o','o','o','o','o'},{'o','o','o','.','o','o','o',},{'o','o','o','o','o','o','o',},{2,2,'o','o','o',2,2},{2,2,'o','o','o',2,2}};

    printf("\n\n\n");
    printf("\t\t\t\t\t| Oyun Yukleniyor");

    for(i=0;i<10;i++)
    {
        for(k=0;k<100000000;k++); //Yükleniyor Efekti vermek icin
        printf(".");
    }

    for(k=0;k<900000000;k++);
    system("cls");

    printf("\t|________________________________|\n");
    printf("\t| SOLO TEST OYUNUNA HOSGELDINIZ! |\n");
    printf("\t|________________________________|\n\n");

    masagiris(dizi);

        printf("\n");

        printf("Baslamak Icin Oyuncu Adi Giriniz: ");
        scanf("%s",isim);

    system("cls");

    DEVAM:
    printf(" _____________________________________________\n");
    printf("|                                             |\n");
    printf("| 1- Kirmizi Temada Oynamak Icin 1'i Tuslayin |\n");
    printf("| 2- Mavi Temada Oynamak Icin 2'yi Tuslayin   |\n");
    printf("| 3- Yesil Temada Oynamak Icin 3'u Tuslayin   |\n");
    printf("|_____________________________________________|\n");
    printf("|                                             |\n");
    printf("|Lutfen Devam Etmek Icin Bir Sayi Seciniz: ");
    scanf("%d",&sayi);
    system("cls");

    switch(sayi)
    {
    case 1:
        system("color 4");
        for(;;)
        {
                masa(dizi);
                printf("\t\t\t\t\tOyuncu Adi: %s \n",isim);
                printf("\t\t\t\t\tKalan Tas: %d \n",kalan(dizi));
                printf("\n");
                hareket(dizi);
                if(bitis(dizi))
                {
                    printf("Oyuncu Adi: %s\n",isim);
                    return 0;
                }

        }
        break;
    case 2:
        system("color 3");
        for(;;)
        {
            masa(dizi);
            printf("\t\t\t\t\tOyuncu Adi: %s \n",isim);
            printf("\t\t\t\t\tKalan Tas: %d \n",kalan(dizi));
            printf("\n");
            hareket(dizi);
            if(bitis(dizi))
                {
                    printf("Oyuncu Adi: %s\n",isim);
                    return 0;
                }
        }
        break;
    case 3:
        system("color 2");
        for(;;)
        {
            masa(dizi);
            printf("\t\t\t\t\tOyuncu Adi: %s \n",isim);
            printf("\t\t\t\t\tKalan Tas: %d \n",kalan(dizi));
            printf("\n");
            hareket(dizi);
            if(bitis(dizi))
                {
                    printf("Oyuncu Adi: %s\n",isim);
                    return 0;
                }
        }
        break;
    default:
        printf("Lutfen Gecerli Bir Tema Sayisi Giriniz!\n");
        DEVAM2:
        printf("Devam Etmek Icin 1'i Enterlayin: ");
        scanf("%d",&devam1);
        if(devam1==1)
        {
            system("cls");
            goto DEVAM;
        }
        else
        {
            system("cls");
            printf("Lutfen 1 Giriniz!\n");
            goto DEVAM2;
        }
        break;

    }

    return 0;
}

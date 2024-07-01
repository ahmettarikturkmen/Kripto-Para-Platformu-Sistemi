/****************************************************************************
**					        SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				         BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI:2
**				ÖĞRENCİ ADI: Ahmet Tarık Türkmen
**				ÖĞRENCİ NUMARASI: g221210087
**				DERS GRUBU: 2.Öğretim C Grubu
****************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

const int MAX_ACCOUNTS = 20; //Açılabilen max hesap sayısı.

class Hesap
{
public:

    string hesapAdi;

    double ilkPara;
    double tlBakiye = 0;
    double bitcoinBakiye = 0;
    double cekilenTl;
    double yatirilanTl;
    double bitcoinAdet = 0;
    double bitcoinDeger = 1;
    double yeniBitcoinDeger = 1;
    double toplamKar;
    double toplamDeger;

    int genelGun;
    int ozelGun;
    int hesapTipi = 0;

    //Fonksiyonlar başlangıç.

    void parayatir()
    {
        cout << "Ne kadar TL yatırmak istiyorsunuz? " << endl;
        cin >> yatirilanTl;
        ilkPara += yatirilanTl;

        tlBakiye += yatirilanTl;
        cout << endl << yatirilanTl << " TL yatırdınız. " << endl;
        system("pause");
    }



    void paracek()
    {
        cout << "Ne kadar TL çekmek istiyorsunuz? " << endl;
        cin >> cekilenTl;
        //Çekmek istediği paranın bakiyeden büyük olup olmadığını kontrol eder.
        if (cekilenTl <= ilkPara)
        {
            ilkPara -= cekilenTl;

            tlBakiye -= cekilenTl;
            cout << endl << cekilenTl << " TL çektiniz. ";
            system("pause");
        }
        else
        {
            cout << "Yeterli TL Bakiyeniz Yok. Lütfen Para Yatırın." << endl;
            system("pause");
        }
    }



    void kriptoal()
    {
        cout << "Ne kadar Bitcoin almak istiyorsunuz? " << endl;
        cin >> bitcoinAdet;
        //Almak istediği bitcoinlerin fiyatının bakiyeden büyük olup olmadığını kontrol eder.
        if (tlBakiye >= yeniBitcoinDeger * bitcoinAdet)
        {
            bitcoinBakiye += bitcoinAdet * bitcoinDeger;
            tlBakiye -= bitcoinBakiye;
            cout << bitcoinAdet << " tane Bitcoin aldınız. ";
            system("pause");
        }
        else
        {
            cout << "Yeterli TL Bakiyeniz Yok.Lütfen Para Yatırın." << endl;
            system("pause");
        }

    }



    void kriptosat()
    {
        cout << "Ne kadar Bitcoin satmak istiyorsunuz? " << endl;
        cin >> bitcoinAdet;
        //Satmak istediği bitcoinin mevcut bitcoininden büyük olup olmadığını kontrol eder.
        if (bitcoinAdet <= bitcoinBakiye)
        {
            bitcoinBakiye -= bitcoinAdet * bitcoinDeger;
            tlBakiye += bitcoinBakiye;
            cout << bitcoinAdet << " tane Bitcoin sattınız. ";
            system("pause");
        }
        else
        {
            cout << "Yeterli Bitcoin Yok" << endl;
            system("pause");
        }
    }



    void bakiyegoruntule()
    {
        cout << "Hesap Adı: " << hesapAdi << endl;
        cout << "Hesapta " << tlBakiye << " TL " << endl;
        cout << "ve " << bitcoinBakiye << " Bitcoin var" << endl;
        cout << "Bitcoinin birim değeri: " << fixed << setprecision(2) << yeniBitcoinDeger << endl;
    }


    void kargoruntule()
    {
        toplamDeger = tlBakiye + (bitcoinAdet * yeniBitcoinDeger);
        cout << endl << endl << "hesabınızın toplam değeri : " << fixed << setprecision(2) << toplamDeger << endl;

        toplamKar = toplamDeger - ilkPara;
        cout << "hesabınızın toplam karı : " << fixed << setprecision(2) << toplamKar << endl;
    };


    void genelTarihiIleriSar()
    {
        // İlk tarihi otomatik olarak sistem tarihi olarak belirle
        time_t currentTime = time(0);
        tm localTime;


#ifdef _MSC_VER
        localtime_s(&localTime, &currentTime);
#else
        localtime_r(&currentTime, &localTime);
#endif

        int firstDay = localTime.tm_mday;
        int firstMonth = localTime.tm_mon + 1; // tm_mon Ocak'ı 0 olarak kabul ettiği için 1 çıkartıyoruz
        int firstYear = localTime.tm_year + 1900; // tm_year 1900'den başladığı için 1900 çıkartıyoruz

        // İkinci tarihi giriş al
        int secondDay, secondMonth, secondYear;
        cout << "Şu anki tarih: " << firstDay << " " << firstMonth << " " << firstYear << endl;
        cout << "İşlem yaptığınız hesap: " << "'" << hesapAdi << "'" << " " << " Hesabınızdaki Kripto Parayı Satmak İstediğiniz Tarihi Giriniz (Gün Ay Yıl) - " << endl;
        cout << "Gün: ";
        cin >> secondDay;
        cout << "Ay: ";
        cin >> secondMonth;
        cout << "Yıl: ";
        cin >> secondYear;

        // İlk tarihi tm yapısına dönüştür
        tm firstDate = { 0 };
        firstDate.tm_mday = firstDay;
        firstDate.tm_mon = firstMonth - 1; // tm_mon Ocak'ı 0 olarak kabul ettiği için 1 çıkartıyoruz
        firstDate.tm_year = firstYear - 1900; // tm_year 1900'den başladığı için 1900 çıkartıyoruz

        // İkinci tarihi tm yapısına dönüştür
        tm secondDate = { 0 };
        secondDate.tm_mday = secondDay;
        secondDate.tm_mon = secondMonth - 1;
        secondDate.tm_year = secondYear - 1900;

        // İlk tarihi saniye cinsine dönüştür
        time_t firstTime = mktime(&firstDate);

        // İkinci tarihi saniye cinsine dönüştür
        time_t secondTime = mktime(&secondDate);

        // Farkı hesapla
        double difference = difftime(secondTime, firstTime);

        // İki tarih arasındaki gün farkı bulunur.
        int daysDifference = static_cast<int>(difference) / (60 * 60 * 24);
        genelGun = daysDifference;
        // i, 1 den başlayarak Gün farkına kadar birer birer artar.Her arttığında bitcoinin değeri % 1 artış sağlar.
        for (int i = 1; i <= genelGun; i++)
        {
            bitcoinDeger = (bitcoinDeger * 0.01) + bitcoinDeger;
            //Eğer i 15 e bölümünden kalan 0 ise (15 günde bir) %5 düşüş sağlar.
            if (i % 15 == 0)
            {
                bitcoinDeger = bitcoinDeger - (bitcoinDeger * 5 / 100);
            }
        }
        yeniBitcoinDeger = bitcoinDeger;
    };


    void ozelTarihiIleriSar()
    {
        // İlk tarihi otomatik olarak sistem tarihi olarak belirle
        time_t currentTime = time(0);
        tm localTime;


#ifdef _MSC_VER
        localtime_s(&localTime, &currentTime);
#else
        localtime_r(&currentTime, &localTime);
#endif

        int firstDay = localTime.tm_mday;
        int firstMonth = localTime.tm_mon + 1; // tm_mon Ocak'ı 0 olarak kabul ettiği için 1 çıkartıyoruz
        int firstYear = localTime.tm_year + 1900; // tm_year 1900'den başladığı için 1900 çıkartıyoruz

        // İkinci tarihi giriş al
        int secondDay, secondMonth, secondYear;
        cout << "Şu anki tarih: " << firstDay << " " << firstMonth << " " << firstYear << endl;
        cout << "İşlem yaptığınız hesap: " << "'" << hesapAdi << "'" << " " << " Hesabınızdaki Kripto Parayı Satmak İstediğiniz Tarihi Giriniz (Gün Ay Yıl) - " << endl;
        cout << "Gün: ";
        cin >> secondDay;
        cout << "Ay: ";
        cin >> secondMonth;
        cout << "Yıl: ";
        cin >> secondYear;

        // İlk tarihi tm yapısına dönüştür
        tm firstDate = { 0 };
        firstDate.tm_mday = firstDay;
        firstDate.tm_mon = firstMonth - 1; // tm_mon Ocak'ı 0 olarak kabul ettiği için 1 çıkartıyoruz
        firstDate.tm_year = firstYear - 1900; // tm_year 1900'den başladığı için 1900 çıkartıyoruz

        // İkinci tarihi tm yapısına dönüştür
        tm secondDate = { 0 };
        secondDate.tm_mday = secondDay;
        secondDate.tm_mon = secondMonth - 1;
        secondDate.tm_year = secondYear - 1900;

        // İlk tarihi saniye cinsine dönüştür
        time_t firstTime = mktime(&firstDate);

        // İkinci tarihi saniye cinsine dönüştür
        time_t secondTime = mktime(&secondDate);

        // Farkı hesapla
        double difference = difftime(secondTime, firstTime);

        // Gün sayısına çevir
        int daysDifference = static_cast<int>(difference) / (60 * 60 * 24);
        ozelGun = daysDifference;


        srand(time(NULL));
        // 30 günde bir yeni 3 gün seçmek için 
        int rasgeleGun[3];
        // i,0 den başlayarak 3 e kadar birer birer artar.Böylelikle 3 rastgele gün belirlenir.
        for (int i = 0; i < 3; i++) {
            rasgeleGun[i] = rand() % 30;

        }

        if (ozelGun % 30 == 0)//Her 30 gün için aşağıdaki uygulanır.
            //Rastgele 3 gün her ay değişir.
            for (int i = 0; i < 3; i++) {
                rasgeleGun[i] = rand() % 30;

            }
        // i, 1 den başlayarak Gün farkına kadar birer birer artar.
        for (int i = 1; i <= ozelGun; i++)
        {
            //Eğer artıştaki sayı rastgele günlerden biriyse %10 düşüş sağlar.
            if (i == rasgeleGun[0] or i == rasgeleGun[1] or i == rasgeleGun[2])
            {
                bitcoinDeger -= bitcoinDeger * 0.1;
            }
            else//Her arttığında bitcoinin değeri % 5 artış sağlar.
            {
                bitcoinDeger += bitcoinDeger * 0.05;
            }
        }
        yeniBitcoinDeger = bitcoinDeger;
    }

    //Fonksiyonlar bitiş.
};


int main()
{
    setlocale(LC_ALL, "Turkish");

    Hesap hesaplar[MAX_ACCOUNTS];
    int hesapSayisi = 0;

    int secim = 4;
    int secim2 = 8;

    while (secim != 0)//Seçim sıfır değilse switch case ile seçtiği seçeneğe göre işlem yapar.Seçim 0 ise programı kapatır. 
    {
        cout << setw(65) << "KRİPTO PARA BORSASINA HOŞGELDİNİZ..." << endl << endl << endl;
        cout << setw(20) << "Lütfen Yapmak İstediğiniz İşlemi Seçiniz." << endl;
        cout << "[1] HESAP AÇ" << endl;
        cout << "[2] HESAP İŞLEMLERİ" << endl;
        cout << "[3] HESAPLARI GÖRÜNTÜLE " << endl;
        cout << "[0] PROGRAMDAN ÇIKIŞ " << endl;
        cin >> secim;

        switch (secim)
        {
        case 1:

            system("CLS");
            //Hesap sayısı açılabilen max accounts sayısından küçükse aşağıdakileri yapar.Değilse uyarır.
            if (hesapSayisi < MAX_ACCOUNTS)
            {

                cout << "Lütfen hesabınızı açmak için belli bir miktar para yatırın. :" << endl;
                cin >> hesaplar[hesapSayisi].ilkPara;
                cout << fixed << setprecision(2) << hesaplar[hesapSayisi].ilkPara << " TL yatırdınız." << endl;
                hesaplar[hesapSayisi].tlBakiye = hesaplar[hesapSayisi].ilkPara;

                cout << "Hesap Adınızı Oluşturunuz: ";
                cin.ignore();
                getline(cin, hesaplar[hesapSayisi].hesapAdi);

                cout << "Hesap Türünü Seçiniz (1: Genel, 2: Özel): ";
                cin >> hesaplar[hesapSayisi].hesapTipi;
                hesapSayisi++;
            }
            else
            {
                cout << "Maksimum hesap sayısına ulaşıldı." << endl;
            }

            break;

        case 2:

            system("CLS");
            if (hesapSayisi > 0)//Hesap sayısı 0 dan büyükse aşağıdakileri yapar.Değilse 'hesap bulunamadı' diye uyarır.
            {
                cout << "Lütfen işlem yapmak istediğiniz hesabı seçiniz:" << endl;

                // i,0dan başlayarak açılan tüm hesap sayısına kadar hesapları alt alta listeler ve kullanıcının seçim yapması beklenir.
                for (int i = 0; i < hesapSayisi; ++i)
                {
                    cout << "[" << (i + 1) << "] " << hesaplar[i].hesapAdi << endl;
                }

                int secilenHesapIndex;
                cout << "Hesap numarasını giriniz (1-" << hesapSayisi << "): ";
                cin >> secilenHesapIndex;

                // Seçilen hesap numarasını kontrol eder.
                if (secilenHesapIndex >= 1 && secilenHesapIndex <= hesapSayisi)
                {
                    int hesapIndex = secilenHesapIndex - 1;

                    int secim2 = 1;
                    //Seçim sıfır değilse switch case ile seçtiği seçeneğe göre işlem yapar.
                    while (secim2 != 0)
                    {
                        system("CLS");
                        cout << "Ne Yapmak İstersiniz?" << endl;
                        cout << "[1] PARA YATIR " << endl;
                        cout << "[2] PARA ÇEK " << endl;
                        cout << "[3] BİTCOİN AL " << endl;
                        cout << "[4] BİTCOİN SAT " << endl;
                        cout << "[0] GERİ " << endl;

                        cin >> secim2;

                        switch (secim2)
                        {
                        case 1:
                            system("cls");
                            hesaplar[hesapIndex].parayatir();
                            break;
                        case 2:
                            system("cls");
                            hesaplar[hesapIndex].paracek();
                            break;
                        case 3:
                            system("cls");
                            hesaplar[hesapIndex].kriptoal();
                            break;
                        case 4:
                            system("cls");
                            hesaplar[hesapIndex].kriptosat();
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            break;
                        }
                    }
                }
                else
                {
                    cout << "Geçersiz hesap numarası." << endl;
                }
            }
            else
            {
                cout << "Hesap bulunmamaktadır." << endl;
            }

            break;


        case 3:

            system("CLS");
            cout << "Genel Hesaplar:" << endl;
            //tüm genel hesapların bakiyelerini ve karlarını görüntüler.
            for (int i = 0; i < hesapSayisi; ++i)
            {
                //Genel Hesap Türü için görüntüler.
                if (hesaplar[i].hesapTipi == 1)
                {
                    hesaplar[i].genelTarihiIleriSar();
                    hesaplar[i].bakiyegoruntule();
                    hesaplar[i].kargoruntule();
                    cout << endl;
                }
            }

            cout << endl << "Özel Hesaplar:" << endl;
            //tüm özel hesapların bakiyelerini ve karlarını görüntüler.
            for (int i = 0; i < hesapSayisi; ++i)
            {
                //Özel Hesap Türü için görüntüler.
                if (hesaplar[i].hesapTipi == 2)
                {
                    hesaplar[i].ozelTarihiIleriSar();
                    hesaplar[i].bakiyegoruntule();
                    hesaplar[i].kargoruntule();
                    cout << endl;
                }
            }
            break;

        case 0:

            break;

        default:

            system("cls");
            cout << "Lütfen Geçerli Bir Sayı Giriniz :" << endl;

            break;
        }
    }

    cout << "Programdan başarıyla çıkış yaptınız." << endl;

    return EXIT_SUCCESS;
}

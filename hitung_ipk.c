#include <stdio.h>
#include <stdlib.h>

char ulang;
int sks[8] = {3,4,4,3,2,3,3,4};
char nilai_huruf[8] = {'A','A','B','C','C'};
int nilai_angka[8] = {4,4,3,2,2};

char matkul[8][30] = {"Robotika I           ", "Mikrokontroller      ", 
					  "Algoritma Pemrograman", "Basis Data           ", 
					  "Struktur Data        ", "Interfacing          ", 
					  "Sensor dan Tranduser ", "Mekatronika          "};

void tabel()//prosedur1
{
	system("clear");
	printf("---------------------------------------------------------------\n");
	printf("| No |        Mata Kuliah        |  SKS  |  Nilai  |   Mutu   |\n");
	printf("---------------------------------------------------------------\n");
}

int hitung_mutu (int h_nilai, int h_sks)//fungsi1
{
	int h_mutu = h_nilai*h_sks;
	return h_mutu;
}

int semua_mutu(float jumlah_mutu, int t_mutu)//fungsi2
{
	jumlah_mutu += t_mutu;
	return jumlah_mutu;
}

int semua_sks(float jumlah_sks, int t_sks)//fungsi3
{
	jumlah_sks += t_sks;
	return jumlah_sks;
}

void tabel2(float t_sks, float t_mutu)//prosedur2
{
	printf("---------------------------------------------------------------\n"); 
	printf("|          Jumlah Total          |%4.0f   |         |%6.0f    |\n",t_sks,t_mutu);
	printf("---------------------------------------------------------------\n");
	printf("|               IPK              |%16.2f            |\n",t_mutu/t_sks);
	printf("---------------------------------------------------------------\n");
}

int main()
{
	while (1)
	{
		float total_mutu=0, total_sks=0;
		int i=5, j=0, mutu[8], a1=0, c1=0;
		printf("Masukkan nilai A/B/C/D/E (Huruf Kapital)\n");
		
		while (i<8)
		{
			printf("Nilai %s : ",matkul[i]); scanf("%s",&nilai_huruf[i]);
			if (nilai_huruf[i] == 'A') {nilai_angka[i]=4; }
			else if(nilai_huruf[i] == 'B') { nilai_angka[i]=3; }
			else if(nilai_huruf[i] == 'C') { nilai_angka[i]=2; }
			else if(nilai_huruf[i] == 'D') { nilai_angka[i]=1; }
			else if(nilai_huruf[i] == 'E') { nilai_angka[i]=0; }
			i++;
		}
		tabel(); //prosedur1
		
		while (j<8)
		{	
			mutu[j] = hitung_mutu(nilai_angka[j],sks[j]); //fungsi1
			printf("| %i  |  %s    |   %i   |    %c    |    %2i    |\n", j+1, matkul[j], sks[j], nilai_huruf[j], mutu[j]);
			if (nilai_angka[j] == 4) { a1+=1; }
			if (nilai_angka[j] == 2) { c1+=1; }	
			total_mutu = semua_mutu(total_mutu,mutu[j]); //fungsi2
			total_sks = semua_sks(total_sks,sks[j]);//fungsi3
			j++;
		}
		
		tabel2(total_sks,total_mutu); //prosedur2
		
		printf("\n *Matkul yang mendapatkan nilai 'A' ada %i, yaitu :\n",a1);
		int y=0;
		while (y<8)
		{	if (nilai_angka[y] == 4)
			{
				printf("  - %s \n",matkul[y]);
			}
			y++;
		}
		
		printf("\n *Matkul yang mendapatkan nilai 'C' ada %i, yaitu :\n",c1);
		int z=0;
		while (z<8)
		{	if (nilai_angka[z] == 2)
			{
				printf("  - %s \n",matkul[z]);
			}
			z++;
		}

		printf("\nMau Ulangi? (y/t) : ");
		scanf("%s",&ulang);
		if (ulang == 't')
		{
			break;
		}
		system("clear");
	}
return 1;
}


#include <iostream>
#include <string>
#include <string.h> //char
#include <conio.h>	//getch()
#include <iomanip>	//setw, setprecision
using namespace std;
class sinhvien
{
	// private:
public:
	char hoten[30], gioitinh[20];
	char namsinh[20], diachi[100];
	char masv[20], lop[20];
	float toan, ly, hoa, van , anh, sinh, DTB;

	void nhap();
	void hienthi();
};
// xay dung phuong thuc nhap
void sinhvien::nhap()
{
	cin.ignore(1); // xoa bo nho dem
	cout << "\n Nhap ho ten:";
	cin.getline(hoten, 30);
	fflush(stdin);
	cout << "\n Nhap gioi tinh:";
	cin.getline(gioitinh, 20);
	fflush(stdin);
	cout << "\n Nhap nam sinh:";
	cin.getline(namsinh, 20);
	fflush(stdin);
	cout << "\n Nhap dia chi:";
	cin.getline(diachi, 100);
	fflush(stdin);
	cout << "\n Nhap ma sinh vien:";
	cin.getline(masv, 20);
	fflush(stdin);
	cout << "\n Nhap lop:";
	cin.getline(lop, 20);
	fflush(stdin);
	cout << "\n Nhap diem toan:";
	cin >> toan;
	cout << "\n Nhap diem ly:";
	cin >> ly;
	cout << "\n Nhap diem hoa:";
	cin >> hoa;
	cout << "\n Nhap diem van:";
	cin >> van;
	cout << "\n Nhap diem anh:";
	cin >> anh;
	cout << "\n Nhap diem sinh:";
	cin >> sinh;
	cout << endl;
}
// xay dung phuong thuc hien thi
std::string prd(const double x, const int decDigits)
{
	stringstream ss;
	ss << fixed;
	ss.precision(decDigits); // set # places after decimal
	ss << x;
	return ss.str();
}

std::string prd(const double x, const int decDigits, const int width)
{
	stringstream ss;
	ss << fixed << right;
	ss.fill(' ');			 // fill space around displayed #
	ss.width(width);		 // set  width around displayed #
	ss.precision(decDigits); // set # places after decimal
	ss << x;
	return ss.str();
}

std::string center(const string s, const int w)
{
	stringstream ss, spaces;
	int padding = w - s.size(); // count excess room to pad
	for (int i = 0; i < padding / 2; ++i)
		spaces << " ";
	ss << spaces.str() << s << spaces.str(); // format with padding
	if (padding > 0 && padding % 2 != 0)	 // if odd #, add 1 space
		ss << " ";
	return ss.str();
}

void sinhvien::hienthi()
{
	const char separator = '-';
	const int nameWidth = 14;
	const int genderWidth = 9;
	const int dateWidth = 8;
	const int addressWidth = 10;
	const int msvWidth = 14;
	const int classWidth = 5;
	const int tcWidth = 6;

	cout << "\n| " << center(hoten, nameWidth) << " | " << center(gioitinh, genderWidth) << " | " << center(namsinh, dateWidth);
	cout << " | " << center(diachi, addressWidth) << " | " << center(masv, msvWidth) << " | " << center(lop, classWidth);

	cout << " | " << prd(toan, 2, tcWidth) << " | " << prd(ly, 2, tcWidth) << " | " << prd(hoa, 2, tcWidth) << " | " << prd(van, 2, tcWidth);
	cout << " | " << prd(anh, 2, tcWidth) << " | " << prd(sinh, 2, tcWidth);

	DTB = (toan + ly + hoa + van + anh + sinh) / 6;
	cout << " | " << prd(DTB, 2, tcWidth);
	// xep loai hoc luc sinh vien
	if (DTB >= 8)
	{
		cout << " | " << center("Gioi", 10);
	}
	else if (DTB >= 7)
	{
		cout << " | " << center("Kha", 10);
	}
	else if (DTB >= 5)
	{
		cout << " | " << center("Trung Binh", 10);
	}
	else if (DTB < 5)
	{
		cout << " | " << center("Yeu", 10);
	}
	cout << " |\n";
}
// xay dung lop ke thua
class quanlysv : public sinhvien
{
public:
	double DTB;
	sinhvien sv[100]; // khai bao mang sinh vien
	int n;

	void nhap();
	void hienthi();
	void xeploaiHL();
	void dssvDTBtd();
	void dssvDTBgd();
	void timsvDTBMAX();
	void timkiemsv();
};
// xay dung phuong thuc nhap
void quanlysv::nhap()
{
	cout << "Nhap so luong sinh vien:";
	cin >> n; // n=2
	for (int i = 0; i < n; i++)
	{
		cout << "\n sinh vien thu:" << i + 1 << "";
		sv[i].nhap(); // Goi phuong thuc nhap o lop sinh vien
	}
}
// xay dung phuong thuc hien thi

void quanlysv::hienthi()
{
	const char separator = '-';
	const int nameWidth = 14;
	const int genderWidth = 9;
	const int dateWidth = 8;
	const int addressWidth = 10;
	const int msvWidth = 14;
	const int classWidth = 5;
	const int tcWidth = 6;

	const int arr[6] = {nameWidth, genderWidth, dateWidth, addressWidth, msvWidth, classWidth};

	for (int x : arr)
	{
		cout << '+' << string(x + 2, separator);
	}

	for (int i = 0; i < 7; i++)
	{
		cout << '+' << string(tcWidth + 2, separator);
	}
	cout << '+' << string(tcWidth + 6, separator) << '+';

	cout << "\n| " << center("Ho Ten", nameWidth) << " | " << center("Gioi Tinh", genderWidth);
	cout << " | " << center("Nam Sinh", dateWidth) << " | " << center("Dia Chi", addressWidth);
	cout << " | " << center("Ma Sinh Vien", msvWidth) << " | " << center("Lop", classWidth);

	cout << " | " << center("toan", tcWidth) << " | " << center("ly", tcWidth) << " | " << center("hoa", tcWidth) << " | " << center("van", tcWidth);
	cout << " | " << center("anh", tcWidth) << " | " << center("sinh", tcWidth) << " | " << center("DTB", tcWidth) << " | " << center("Xep Loai", 10) << " |\n";

	for (int i = 0; i < n; i++)
	{
		for (int x : arr)
		{
			cout << '+' << string(x + 2, separator);
		}

		for (int i = 0; i < 7; i++)
		{
			cout << '+' << string(tcWidth + 2, separator);
		}
		cout << '+' << string(tcWidth + 6, separator) << '+';
		sv[i].hienthi(); // Goi phuong thuc hien thi lop sinh vien o tren
	}
	for (int x : arr)
	{
		cout << '+' << string(x + 2, separator);
	}

	for (int i = 0; i < 7; i++)
	{
		cout << '+' << string(tcWidth + 2, separator);
	}
	cout << '+' << string(tcWidth + 6, separator) << '+';
}
// xep loai hoc luc sinh vien
void quanlysv::xeploaiHL()
{
	cout << "\n";
	cout << "---\n Sinh vien xep loai hoc luc gioi---" << endl;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].DTB >= 8)
		{
			sv[i].hienthi();
		}
	}
	cout << "\n";
	cout << "\n--- Sinh vien xep loai hoc luc yeu---" << endl;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].DTB < 5)
		{
			sv[i].hienthi();
		}
	}
}

// Danh sach sinh vien co diem trung binh tang dan
void quanlysv::dssvDTBtd()
{
	int i, j;
	sinhvien tg;
	cout << "\n";
	cout << "\n---Danh sach sinh vien co diem trung binh tang dan---" << endl;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (sv[i].DTB > sv[j].DTB)
				tg = sv[i];
			sv[i] = sv[j];
			sv[j] = tg;
		}
	}
	cout << "Sau khi sap xep la:" << endl;
	for (int i = 0; i < n; i++)
	{
		sv[i].hienthi();
	}
}
// Danh sach sinh vien co diem trung binh giam dan
void quanlysv::dssvDTBgd()
{
	int i, j;
	sinhvien tg;
	cout << "\n";
	cout << "\n---Danh sach sinh vien co diem trung binh giam dan---" << endl;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (sv[i].DTB < sv[j].DTB)
				tg = sv[i];
			sv[i] = sv[j];
			sv[j] = tg;
		}
	}
	cout << "Sau khi sap xep:" << endl;
	for (int i = 0; i < n; i++)
	{
		sv[i].hienthi();
	}
}
// sinh vien co diem trung binh max
void quanlysv::timsvDTBMAX()
{
	cout << "\n";
	cout << "\n---Danh sach sinh vien co diem trung binh cao nhat---" << endl;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].DTB > max)
		{
			max = sv[i].DTB;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (sv[i].DTB > max)
		{
			sv[i].hienthi();
		}
	}
}
// xay dung ham tim kiem sinh vien theo ma or hoten
void quanlysv::timkiemsv()
{
	string msv;
	int count = 0;
	cout << "\n Nhap ma sinh vien can tim:";
	fflush(stdin);
	getline(cin, msv);
	cout << "\n---Thong tin sinh vien khi nhap xong la---";
	cout << "\n Ho Ten" << setw(12) << "Gioi Tinh" << setw(11) << "Nam Sinh" << setw(12);
	cout << "Dia Chi" << setw(14) << "Ma Sinh Vien" << setw(12) << "Lop" << setw(10);
	cout << "toan" << setw(10) << "ly" << setw(10) << "hoa" << setw(10) << "van" << setw(10);
	cout << "anh" << setw(10) << "sinh" << setw(9) << "DTB" << setw(14) << "DTB Lam Tron" << setw(10);
	for (int i = 0; i < n; i++)
	{
		if (sv[i].masv == msv)
		{
			sv[i].hienthi();
			count++;
		}
	}
	if (count == 0)
	{
		cout << "\n Khong tim thay thong tin sinh vien";
	}
}
int main()
{
	quanlysv QLSV;
	int m, option;
	cout << " Chuong trinh quan li sinh vien, nhap 1 so > 0 de bat dau chuong trinh:";
	cin >> m;
	while (m > 0)
	{
		system("cls");
		cout << "\tCHUONG TRINH QUAN LY DIEM SINH VIEN.\t" << endl;
		;
		cout << "========================MENU============================\n";
		cout << "==                                                    ==\n";
		cout << "==        1.Nhap Thong Tin Sinh Vien.                 ==\n";
		cout << "==        2.In Ra Danh Sach Sinh Vien.                ==\n";
		cout << "==        3.Xep Loai Hoc Luc Sinh Vien Gioi Va Yeu.   ==\n";
		cout << "==        4.Danh Sach Sinh Vien DTB Tang Dan.         ==\n";
		cout << "==        5.Danh Sach Sinh Vien DTB Giam Dan.         ==\n";
		cout << "==        6.Danh Sach Sinh Vien DTB MAX.              ==\n";
		cout << "==        7.Tim Kiem Sinh Vien Theo MSV Or Ho Ten.    ==\n";
		cout << "==        8.Exit                                      ==\n";
		cout << "========================================================\n";
		cout << "\tHay nhap tuy chon cua ban: ";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Moi ban nhap thong tin sinh vien:\n";
			QLSV.nhap();
			cout << "Bam mot phim bat ky de tiep tuc\n";
			system("pause");
			break;
		case 2:
			cout << "Thong tin sinh vien ban nhap la:\n";
			QLSV.hienthi();
			cout << "Bam mot phim bat ky de tiep tuc\n";
			system("pause");
			break;
		case 3:
			cout << "Danh sach sinh vien xep loai hoc luc:\n";
			QLSV.xeploaiHL();
			cout << "Bam mot phim bat ky tiep tuc\n";
			system("pause");
			break;
		case 4:
			cout << "Danh sach sinh vien diem trung binh tang dan:\n";
			QLSV.dssvDTBtd();
			cout << "Bam mot phim bat ky de tiep tuc\n";
			system("pause");
			break;
		case 5:
			cout << "Danh sach sinh vien diem trung binh giam dan:\n";
			QLSV.dssvDTBgd();
			cout << "Bam mot phim bat ky de tiep tuc\n";
			system("pause");
			break;
		case 6:
			cout << "Sinh vien co dem trung binh Max:\n";
			QLSV.timsvDTBMAX();
			cout << "Bam mot phim bat ky tiep tuc\n";
			system("pause");
			break;
		case 7:
			cout << "Tim kiem sinh vien theo ma sinh vien:\n";
			QLSV.timkiemsv();
			cout << "Bam mot phim bat ky de tiep tuc\n";
			system("pause");
			break;
		case 8:
			system("pause");
			break;
		default:
			cout << "Ban da nhap sai. Xin moi nhap lai!\n";
			break;
		}
	}
	//	quanlysv QLSV;
	//	QLSV.nhap();
	//	QLSV.hienthi();
	//	QLSV.xeploaiHL();
	//	QLSV.dssvDTBtd();
	//	QLSV.dssvDTBgd();
	//	QLSV.timsvDTBMAX();
	//	QLSV.timkiemsv();
	getch();
	return 0;
}

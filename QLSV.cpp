#include<iostream>
#include<windows.h>
#include<cstring>

#define KHUNG cout << "\n|	MA SV	     |               HO  TEN             |       DIA CHI       |"
#define EMPTY cout << "\n Danh sach sinh vien rong!\n"
#define NO_FUN cout << "\n Sai chuc nang!\n"
#define CHAO cout << "\n\n\t	Hen gap lai!	\n\n"
#define LINE cout << "\n ------------------------------------------------------------------------------"

using namespace std;

/******** Cai dat danh sach liet ket ********/
typedef struct{
	string Ten, Masv, Id;
}Infor;

struct Sinhvien{
	Infor item;
	struct Sinhvien *next;
};

/******** Nguyen mau ham ********/
void Insert(Sinhvien *s);
void Insert_End(Sinhvien *s, Infor item);
void Result(Sinhvien *s);
Sinhvien *Search(Sinhvien *s, string key);
bool isEmpty(Sinhvien *s);
void Remove_B(Sinhvien *s);
void Edit(Sinhvien *s);
void PrintEdit(Sinhvien *s);
void Standard(Sinhvien *s);
void PrintStudent(Sinhvien *s);
void Menu();
void PrintMenu();
void Clear();

int main(){
	Menu();
	system("pause");
	return 0;
}

void Clear(){
	system("cls");
}

/******** Menu list ********/
void PrintMenu(){
	cout<<"\n	QUAN LY SINH VIEN\n"
		<<"\n 1. XEM DANH SACH SINH VIEN"
		<<"\n 2. THEM SINH VIEN"
		<<"\n 3. XOA SINH VIEN"
		<<"\n 4. SUA SINH VIEN"
		<<"\n 0. THOAT"
		<<"\n Ban chon: ";
	return;
}

/******** Menu chinh ********/
void Menu(){
	Sinhvien *s = new struct Sinhvien;
	s->next = NULL;
	int choice;
	do{
		Clear();
		PrintMenu();
		cin >> choice;
		switch(choice){
			case 0:
				Clear();
				CHAO;		
				break;
			case 1:	
				Clear();		
				Result(s);
				break;
			case 2:
				Clear();
				Insert(s);
				break;
			case 3:
				Clear();
				Remove_B(s);
				break;
			case 4:
				Clear();
				Edit(s);
				break;
			default:
				NO_FUN;
				system("pause");
				break;		
		}
	}while (choice);
}

/******** Kiem tra danh sach lien ket rong ********/
bool isEmpty(Sinhvien *s){
	if (s->next == NULL) return true;
	return false;
}

/******** in ra 1 sinh vien duoc truyen vao tu ham Result(); ********/
void PrintStudent(Sinhvien *s){
	cout<< endl << "|" << s->item.Masv << "|" << s->item.Ten << "|"
		<< s->item.Id << " |";
	LINE;
}

/******** Chuan hoa xau ky tu ********/
void Standard(Sinhvien *s){
	while (s->item.Masv.length() < 20) s->item.Masv = s->item.Masv + " ";
	while (s->item.Ten.length()  < 35) s->item.Ten = s->item.Ten + " ";
	while (s->item.Id.length() < 20) s->item.Id = s->item.Id + " ";
}

/******** in danh sach sinh vien ********/
void Result (Sinhvien *s){
	if (isEmpty(s)){
		EMPTY;
	}
	else{
		cout << "\n Print Students!\n";
		LINE;
		KHUNG;
		LINE;
		Sinhvien *tmp = s;
		while (!isEmpty(tmp)){
			PrintStudent(tmp->next);
			tmp = tmp->next;
		}
	}
	cout << endl;
	system("pause");
}

/******** Nhap thong tin sinh vien, roi goi ham Insert_End(); ********/
void Insert(Sinhvien *s){
	Infor item;
	fflush(stdin);
	cout << "\n Insert Student!\n";
	cout << "\n Nhap ma sinh vien: ";
	getline(cin, item.Masv);
	cout << "\n Ho Ten: ";
	getline(cin, item.Ten);
	cout << "\n Dia Chi: ";
	getline(cin, item.Id);
	Insert_End(s, item);
	cout << "\n Them thanh cong!\n";
	system("pause");
}

/******** Chen sinh vien vao cuoi danh sach lien ket ********/
void Insert_End (Sinhvien *s, Infor item){
	Sinhvien *tmp, *tmp1;
	tmp = new struct Sinhvien;
	tmp->item = item;
	tmp->next = NULL;
	Standard(tmp);
	if (isEmpty(s)) s->next = tmp;// neu ds trong thi la sv dau tien
	else{
		tmp1 = s;
		while (!isEmpty(tmp1)) tmp1 = tmp1->next;
		tmp1->next = tmp;
	}
}

/******** Tim kiem, tra ve dia chi truoc dia chi chua key ********/
Sinhvien *Search(Sinhvien *s, string key){
	Sinhvien *tmp = s;
	while (!isEmpty(tmp)){
		if (tmp->next->item.Masv == key) return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/******** Xoa sau vi tri tim thay ********/
void Remove_B(Sinhvien *s){
	if (isEmpty(s)){
		EMPTY;
	}
	else{
		string key;
		fflush(stdin);
		cout << "\n Delete Student!\n";
		cout << "\n Nhap Ma so sinh vien: ";
		getline(cin, key);
		while (key.length() < 20) key = key + " ";
		Sinhvien *position = Search(s, key);
		if (position == NULL){
			cout << "\n Khong ton tai ma sinh vien nay!\n";
		}
		else{
			Sinhvien *tmp = position->next;
			position->next = position->next->next;
			delete tmp;
			cout << "\n Xoa thanh cong!\n";
		}
	}
	system("pause");
}

void PrintEdit(Sinhvien *s){
	cout << "\n Tim thay sinh vien\n";
	LINE;
	KHUNG;
	LINE;
	PrintStudent(s->next);
}

/******** Sua sau vi tri tim thay ********/
void Edit(Sinhvien *s){
	if (isEmpty(s)){
		EMPTY;
	}
	else{
		string key;
		fflush(stdin);
		cout << "\n Edit Student!\n";
		cout << "\n Nhap ma sinh vien can sua: ";
		getline(cin, key);
		while (key.length() < 20) key = key + " ";
		Sinhvien *position = Search(s, key);
		if (position == NULL){
			cout << "\n Khong ton tai ma sinh vien nay!\n";
		}
		else{
			PrintEdit(position);
			Infor item;
			fflush(stdin);
			cout << "\n Ma SV moi: ";
			getline(cin, item.Masv);
			cout << "\n Ten SV moi: ";
			getline(cin, item.Ten);
			cout << "\n Dia chi moi: ";
			getline(cin, item.Id);
			position->next->item = item;
			Standard(position->next);
			cout << "\n Sua thanh cong!\n";
		}
	}
	system("pause");	
}

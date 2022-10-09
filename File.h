#ifndef __x_h__
#define __x_h__
#include "ThuVien.h"
#endif

//typedef struct maHoa{
//	char maSV[15], hoTen[30], ngaySinh[12], queQuan[20], lop[10], gioiTinh[6], xepLoai[5];
//	float toan, ly, hoa, diemTB;
//};
//
//maHoa encrypt(SinhVien temp){
//	maHoa ans;
//	strcpy(ans.maSV, temp.maSV.c_str());
//	strcpy(ans.hoTen, temp.hoTen.c_str());
//	strcpy(ans.ngaySinh, temp.ngaySinh.c_str());
//	strcpy(ans.queQuan, temp.queQuan.c_str());
//	strcpy(ans.lop, temp.lop.c_str());
//	strcpy(ans.queQuan, temp.queQuan.c_str());
//	strcpy(ans.gioiTinh, temp.gioiTinh.c_str());
//	ans.toan   = temp.toan;
//	ans.ly     = temp.ly;
//	ans.hoa	   = temp.hoa;
//	ans.diemTB = temp.diemTB;
//	strcpy(ans.xepLoai, temp.xepLoai.c_str());
//	return ans;
//}
//SinhVien decrypt(maHoa temp){
//	SinhVien ans;
//	ans.maSV     = string(temp.maSV);
//	ans.hoTen    = string(temp.hoTen);
//	ans.ngaySinh = string(temp.ngaySinh);
//	ans.queQuan  = string(temp.queQuan);
//	ans.lop      = string(temp.lop);
//	ans.queQuan  = string(temp.queQuan);
//	ans.gioiTinh =string(temp.gioiTinh);
//	ans.toan     = temp.toan;
//	ans.ly       = temp.ly;
//	ans.hoa	     = temp.hoa;
//	ans.diemTB   = temp.diemTB;
//	ans.xepLoai  = string(temp.xepLoai);
//	return ans;
//}

void openFileWrite(SinhVien strData){
	ofstream fileOut;
 	fileOut.open("output.txt",ios::app);
	
	int i=0;
	fileOut<<strData.MaSV<<'|'<<strData.HoTen<<'|'<<strData.NgaySinh<<'|'<<strData.QueQuan<<'|'
	<<strData.MaLop<<'|'<<strData.GioiTinh<<'|'<<strData.DiemToan<<'|'<<strData.DiemLy<<'|'
	<<strData.DiemHoa<<'|'<<strData.TB<<'|'<<strData.Xeploai<<'|';
	fileOut.close();
}

void docTungSV(ifstream &fileIn, SinhVien &SV){
	char temp;
	fileIn>>SV.MaSV;
	fileIn>>temp;
	getline(fileIn,SV.MaLop,'|');
	getline(fileIn,SV.MaLop,'|');
	getline(fileIn,SV.MaLop,'|');
	getline(fileIn,SV.MaLop,'|');
	getline(fileIn,SV.MaLop,'|');
	fileIn>>SV.DiemToan;
	fileIn>>temp;
	fileIn>>SV.DiemLy;
	fileIn>>temp;
	fileIn>>SV.DiemHoa;
	fileIn>>temp;
	fileIn>>SV.TB;
	fileIn>>temp;
	getline(fileIn,SV.XepLoai,'|');
}

void openFileRead(){
	ifstream fileIn;
	fileIn.open("output.txt",ios::in);
	char temp;
	fileIn>>temp;
	while(!fileIn.eof())
	{
		SinhVien temp;
		docTungSV(fileIn,temp);
		addSinhVien(temp, &dataSinhVien);
	}
	fileIn.close();
}




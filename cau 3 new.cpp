#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Khai báo c?u trúc Sinh viên
struct Student {
    char hoTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
};

struct Student danhSachSinhVien[MAX_STUDENTS]; // M?ng ch?a các sinh viên
int soLuongSinhVien = 0; // S? lu?ng sinh viên hi?n t?i trong m?ng

// Hàm nh?p thông tin cho sinh viên
void nhapThongTin(struct Student *sv) {
    printf("Nhap ho va ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = '\0'; // Xóa ký t? xu?ng dòng th?a

    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);
    getchar(); // Ð?c ký t? '\n' trong b? d?m

    printf("Nhap so dien thoai: ");
    fgets(sv->soDienThoai, sizeof(sv->soDienThoai), stdin);
    sv->soDienThoai[strcspn(sv->soDienThoai, "\n")] = '\0';

    printf("Nhap email: ");
    fgets(sv->email, sizeof(sv->email), stdin);
    sv->email[strcspn(sv->email, "\n")] = '\0';
}

// Hàm thêm sinh viên vào danh sách
void themSinhVien() {
    if (soLuongSinhVien < MAX_STUDENTS) {
        struct Student newStudent;
        nhapThongTin(&newStudent);
        danhSachSinhVien[soLuongSinhVien++] = newStudent;
        printf("Da them sinh vien moi.\n");
    } else {
        printf("Danh sach da day, khong the them sinh vien moi.\n");
    }
}

// Hàm in thông tin c?a sinh viên
void inThongTinSinhVien(struct Student sv) {
    printf("Ho va ten: %s\n", sv.hoTen);
    printf("Tuoi: %d\n", sv.tuoi);
    printf("So dien thoai: %s\n", sv.soDienThoai);
    printf("Email: %s\n", sv.email);
}

// Hàm in danh sách sinh viên ra màn hình
void inDanhSachSinhVien() {
    printf("Danh sach sinh vien:\n");
    if (soLuongSinhVien == 0) {
        printf("Khong co sinh vien nao trong danh sach.\n");
    } else {
        for (int i = 0; i < soLuongSinhVien; ++i) {
            printf("Sinh vien %d:\n", i + 1);
            inThongTinSinhVien(danhSachSinhVien[i]);
            printf("\n");
        }
    }
}

// Hàm s?a thông tin sinh viên t?i v? trí cho tru?c
void suaThongTinSinhVien(int viTri) {
    if (viTri >= 0 && viTri < soLuongSinhVien) {
        printf("Sua thong tin cho sinh vien tai vi tri %d:\n", viTri + 1);
        nhapThongTin(&danhSachSinhVien[viTri]);
        printf("Da sua thong tin cua sinh vien tai vi tri %d.\n", viTri + 1);
    } else {
        printf("Vi tri khong hop le.\n");
    }
}

// Hàm xóa sinh viên t?i v? trí cho tru?c
void xoaSinhVien(int viTri) {
    if (viTri >= 0 && viTri < soLuongSinhVien) {
        for (int i = viTri; i < soLuongSinhVien - 1; ++i) {
            danhSachSinhVien[i] = danhSachSinhVien[i + 1];
        }
        soLuongSinhVien--;
        printf("Da xoa sinh vien tai vi tri %d.\n", viTri + 1);
    } else {
        printf("Vi tri khong hop le.\n");
    }
}

int main() {
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Them sinh vien\n");
        printf("2. Sua thong tin sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. In danh sach sinh vien\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); // Ð?c ký t? '\n' trong b? d?m

        switch (choice) {
            case 1:
                themSinhVien();
                break;
            case 2:
                if (soLuongSinhVien > 0) {
                    int pos;
                    printf("Nhap vi tri can sua (1 - %d): ", soLuongSinhVien);
                    scanf("%d", &pos);
                    getchar(); // Ð?c ký t? '\n' trong b? d?m
                    suaThongTinSinhVien(pos - 1);
                } else {
                    printf("Khong co sinh vien nao de sua thong tin.\n");
                }
                break;
            case 3:
                if (soLuongSinhVien > 0) {
                    int pos;
                    printf("Nhap vi tri can xoa (1 - %d): ", soLuongSinhVien);
                    scanf("%d", &pos);
                    getchar(); // Ð?c ký t? '\n' trong b? d?m
                    xoaSinhVien(pos - 1);
                } else {
                    printf("Khong co sinh vien nao de xoa.\n");
                }
                break;
            case 4:
                inDanhSachSinhVien();
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

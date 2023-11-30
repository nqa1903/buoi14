#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Khai b�o c?u tr�c Sinh vi�n
struct Student {
    char hoTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
};

struct Student danhSachSinhVien[MAX_STUDENTS]; // M?ng ch?a c�c sinh vi�n
int soLuongSinhVien = 0; // S? lu?ng sinh vi�n hi?n t?i trong m?ng

// H�m nh?p th�ng tin cho sinh vi�n
void nhapThongTin(struct Student *sv) {
    printf("Nhap ho va ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = '\0'; // X�a k� t? xu?ng d�ng th?a

    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);
    getchar(); // �?c k� t? '\n' trong b? d?m

    printf("Nhap so dien thoai: ");
    fgets(sv->soDienThoai, sizeof(sv->soDienThoai), stdin);
    sv->soDienThoai[strcspn(sv->soDienThoai, "\n")] = '\0';

    printf("Nhap email: ");
    fgets(sv->email, sizeof(sv->email), stdin);
    sv->email[strcspn(sv->email, "\n")] = '\0';
}

// H�m th�m sinh vi�n v�o danh s�ch
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

// H�m in th�ng tin c?a sinh vi�n
void inThongTinSinhVien(struct Student sv) {
    printf("Ho va ten: %s\n", sv.hoTen);
    printf("Tuoi: %d\n", sv.tuoi);
    printf("So dien thoai: %s\n", sv.soDienThoai);
    printf("Email: %s\n", sv.email);
}

// H�m in danh s�ch sinh vi�n ra m�n h�nh
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

// H�m s?a th�ng tin sinh vi�n t?i v? tr� cho tru?c
void suaThongTinSinhVien(int viTri) {
    if (viTri >= 0 && viTri < soLuongSinhVien) {
        printf("Sua thong tin cho sinh vien tai vi tri %d:\n", viTri + 1);
        nhapThongTin(&danhSachSinhVien[viTri]);
        printf("Da sua thong tin cua sinh vien tai vi tri %d.\n", viTri + 1);
    } else {
        printf("Vi tri khong hop le.\n");
    }
}

// H�m x�a sinh vi�n t?i v? tr� cho tru?c
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
        getchar(); // �?c k� t? '\n' trong b? d?m

        switch (choice) {
            case 1:
                themSinhVien();
                break;
            case 2:
                if (soLuongSinhVien > 0) {
                    int pos;
                    printf("Nhap vi tri can sua (1 - %d): ", soLuongSinhVien);
                    scanf("%d", &pos);
                    getchar(); // �?c k� t? '\n' trong b? d?m
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
                    getchar(); // �?c k� t? '\n' trong b? d?m
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

// 读取与写入结构体数据

#include <stdio.h>
#include <string.h>

struct stu
{
    char name[30];
    int age;
    double score;
};

int main ()
{
    stu student[2];

    strcpy(student[0].name, "Tom");
    student[0].age = 21;
    student[0].score = 92.1f;

    strcpy(student[1].name, "jerry");
    student[1].age = 19;
    student[1].score = 86.2f;

    FILE *fp;
    fp = fopen("struct_file", "wb");
    if (!fp)
    {
        printf("Fail to open file!\n");
    }

    int stuSize = sizeof(stu);
    int studentSize = sizeof(student);
    printf("stuSize = %d\n", stuSize);  //48 = 32+8+8
    printf("studentSize = %d\n", studentSize);  //96 = 48*2

    int ret = fwrite(&student, sizeof(stu), 2, fp);
    printf("ret = %d\n", ret); //2
    
    fclose(fp);
    return 0;
}

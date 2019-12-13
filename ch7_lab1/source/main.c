#include<stdio.h>
#include<stdlib.h>

typedef struct _student
{
	char name[5];
	int chinese;
	int english;
	int math;
	int sum;
	float avg;
}student;
int main()
{
	errno_t err1;
	errno_t err2;
	errno_t err3;
	student data[5];
	FILE *stream1;
	FILE *stream2;
	int i;
	err1 = fopen_s(&stream1, "C://c_code/gradedata.txt", "r");
	err2 = fopen_s(&stream2, "C://c_code/gradeoutput.txt", "w");
	if (err1 != 0 || err2 != 0)
	{
		printf("檔案開啟失敗\n");
	}
	else
	{
		fprintf(stream2, "姓名\t國文\t英文\t數學\t總和\t平均\n");
		for (i = 0; i < 5; i++)
		{
			fscanf_s(stream1, "%s", data[i].name, 10 * sizeof(char));
			fscanf_s(stream1, "%d", &data[i].chinese, sizeof(int));
			fscanf_s(stream1, "%d", &data[i].english, sizeof(int));
			fscanf_s(stream1, "%d", &data[i].math, sizeof(int));

			data[i].sum = data[i].chinese + data[i].english + data[i].math;
			data[i].avg = data[i].sum / 3.0;
			fprintf(stream2, "%s\t%d\t%d\t%d\t%d\t%.2f\n",
				data[i].name, data[i].chinese, data[i].english,
				data[i].math, data[i].sum, data[i].avg);
		}
		fclose(stream1);
		fclose(stream2);
	}
	system("pause");
	return 0;
}
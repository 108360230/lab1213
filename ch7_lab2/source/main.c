#include <stdio.h>
#include <stdlib.h>

struct clientdata
{
	int ac;
	char name[15];
	char fname[10];
	double b;
};

int main(void)
{
	FILE *pr;
	FILE *pw;
	FILE *c;
	int cnt = 0;
	struct clientdata client = { 0,"","",0.0 };

	pr = fopen("C://C_code/credit.txt","r");
	if (pr == NULL)
		return 0;
	pw= fopen("C://C_code/credit_bin.txt", "wb");
	if (pw == NULL)
	{
		fclose(pr);
		return 0;
	}
	while (!feof(pr))
	{
		fscanf(pr, "%d%s%s%lf", &client.ac, client.name, client.fname, &client.b);

		fwrite(&client, sizeof(struct clientdata), 1, pw);

		printf("%-6d%-16s%-11s%10.2f\n", client.ac, client.name, client.fname, client.b);
	}
	fclose(pr);
	fclose(pw);
	printf("以讀取文字檔的ACSII資料，並轉成二進位資料檔案\n\n");
	system("pause");
	printf("\n讀取二進位資料檔案，並格式化輸出如下:\n");
	if ((c = fopen("C://C_code/credit_bin.txt", "rb")) == NULL)
		printf("file could not be opened.\n");
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "acct", "last name", "first name", "blance");
		cnt = fread(&client, sizeof(struct clientdata), 1, c);
		while (cnt > 0)
		{
			printf("%-6s%-16s%-11s%10.2s\n", client.ac, client.name, client.fname, client.b);
			cnt = fread(&client, sizeof(struct clientdata), 1, c);
		}
		fclose(c);
	}
	system("pause");
	return 0;
}
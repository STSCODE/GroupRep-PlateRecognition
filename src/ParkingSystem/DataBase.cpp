#include "stdafx.h"
#include "DataBase.h"

using namespace std;

#pragma comment(lib,"libmysql.lib")

//��ѯͣ������
void CarNumQuery(int year, int month, int day, int year2, int month2, int day2, char* &result)
{
	MYSQL * con;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char tmp[400];
	char *query = NULL;
	int isok;

	char dbuser[30] = "root";
	char dbpasswd[30] = "123456";
	char dbip[30] = "localhost";
	char dbname[50] = "parking";       //���ݿ���
	char tablename[50] = "car_info";   //����

	con = mysql_init((MYSQL*)0);
	//�������ݿ�
	if (con != NULL && mysql_real_connect(con, dbip, dbuser, dbpasswd, dbname, 3306, NULL, 0))
	{
		//��dbname����Ϊ��ǰ�Ŀ�
		if (!mysql_select_db(con, dbname))
		{
			printf("Select Successfully The Database!\n");
			con->reconnect = 1;

			//��ѯ����
			sprintf_s(tmp, "select COUNT(1)	from car_info WHERE InTime >= '%d-%d-%d'  and  OutTime < '%d-%d-%d' ", 
				year, month, day, year2, month2, day2);
			isok = mysql_real_query(con, tmp, strlen(tmp));
			if (isok)
			{
				printf("Query Error: %s !!!\n", mysql_error(con));
			}
			else
			{
				printf("%s Successful!!!\n", tmp);
			}
			res = mysql_store_result(con);//�����������res�ṹ����
			row = mysql_fetch_row(res);
			result =*row;
			return;
		}
		else
		{
			MessageBoxA(NULL, "Unable To Select Mysql,Check Your Configuration!", "", NULL);
			return;
		}
	}
	else
	{
		MessageBoxA(NULL, "Unable To Connect The Database,Check Your Configuration!", "", NULL);
		return;
	}
	return;
}


//��ѯͣ������
void CarMoneyQuery(int year, int month, int day, int year2, int month2, int day2, char* &result)
{
	MYSQL * con;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char tmp[400];
	char *query = NULL;
	int isok;

	char dbuser[30] = "root";
	char dbpasswd[30] = "123456";
	char dbip[30] = "localhost";
	char dbname[50] = "parking";       //���ݿ���
	char tablename[50] = "car_info";   //����

	con = mysql_init((MYSQL*)0);
	//�������ݿ�
	if (con != NULL && mysql_real_connect(con, dbip, dbuser, dbpasswd, dbname, 3306, NULL, 0))
	{
		//��dbname����Ϊ��ǰ�Ŀ�
		if (!mysql_select_db(con, dbname))
		{
			printf("Select Successfully The Database!\n");
			con->reconnect = 1;

			//��ѯ����
			sprintf_s(tmp, "select SUM(Total) from car_info WHERE InTime >= '%d-%d-%d'  and  OutTime < '%d-%d-%d' ",
				year, month, day, year2, month2, day2);
			isok = mysql_real_query(con, tmp, strlen(tmp));
			if (isok)
			{
				printf("Query Error: %s !!!\n", mysql_error(con));
			}
			else
			{
				printf("%s Successful!!!\n", tmp);
			}
			res = mysql_store_result(con);//�����������res�ṹ����
			row = mysql_fetch_row(res);
			result = *row;
			return;
		}
		else
		{
			MessageBoxA(NULL, "Unable To Select Mysql,Check Your Configuration!", "", NULL);
			return;
		}
	}
	else
	{
		MessageBoxA(NULL, "Unable To Connect The Database,Check Your Configuration!", "", NULL);
		return;
	}
	return;
}

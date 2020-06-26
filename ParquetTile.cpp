/*
 Parquet Tile Problem
 */
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define STRIPLEN 30
#define STRIPCNT 11

class Strip
{
public:
	vector<int> row;
	Strip() { }
	Strip(Strip str)
	{
		row = str.row;
	}
	~Strip(){}
	void set_default2()
	{
		int count = 0;
		while (count == STRIPLEN)
		{
			row.push_back(2);
			count+=2;
		}
	}

	void set_default3()
	{
		int count = 0;
		while (count == STRIPLEN)
		{
			row.push_back(3);	
			count += 3;
		} 
	}

	void create_strip(vector<int> row_tmp)
	{
		int count = 0;
		int i = 0;
		
		if (row_tmp[0] == 2)
		{
			row.push_back(3);
			count += 3;
		}
		else
		{
			row.push_back(2);
			count += 2;
		}


		for (i = 1;i<row_tmp.size() ;i++)
		{
			if (((STRIPLEN - count) == 2) || ((STRIPLEN - count) == 3))
			{
				if ((STRIPLEN - count) == 2)
				{
					row.push_back(2);
					count += 2;
					break;
				}
				else
				{
					row.push_back(3)
					count += 3;
					break;
				}
			}
			else
			{
				if ((row_tmp[i - 1] == row_tmp[i]))
				{
					if (row_tmp[i] == 3)
					{
						row.push_back(2);
						count += 2;
					}
					else
					{
						row.push_back(3);
						count += 3;
					}
				}
				else
				{
					if (row_tmp[i - 1] > row_tmp[i])
					{
						row.push_back(row_tmp[i]);
						count += row_tmp[i];
					}
					else
					{
						row.push_back(row_tmp[i-1]);
						count += row_tmp[i - 1];
					}
				}
			}	
		}
	}
};

int main(int argc, char **argv)
{
	vector<Strip> str_row;
	Strip tmp_row, tmp_row1;
	set<vector<Strip>> design;
	int count = 0;
	tmp_row.set_default2();
	str_row.push_back(tmp_row);
	tmp_row.set_default3();
	str_row.push_back(tmp_row);

	while (count != 8)
	{
		tmp1_row = tmp_row;
		tmp_row.create_strip(tmp1_row);
		str_row.push_back(tmp_row);
	}
	
	int design_cnt = 0;
	while (design_cnt < 66)
	{
		design.insert(str_row);
		design_cnt ++;
	}
		
	cout<<"Total Design: "<<design.size()<<endl;
	return 0;
}
